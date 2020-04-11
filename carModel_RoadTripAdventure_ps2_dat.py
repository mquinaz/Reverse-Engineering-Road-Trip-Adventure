from inc_noesis import *
#rapi methods should only be used during handler callbacks
import rapi

def registerNoesisTypes():
    handle = noesis.register("Road Trip Adventure PS2 textures", ".dat")
    noesis.setHandlerTypeCheck(handle, noepyCheckType)
    noesis.setHandlerLoadModel(handle, noepyLoadModel) #see also noepyLoadModelRPG
       #noesis.setHandlerWriteModel(handle, noepyWriteModel)
       #noesis.setHandlerWriteAnim(handle, noepyWriteAnim)
   noesis.logPopup()
       #print("The log can be useful for catching debug prints from preview loads.\nBut don't leave it on when you release your script, or it will probably annoy people.")
   return 
    return 1

def noepyCheckType(data):
    #Verify that the format is supported by this plugin. Default yes
    # file ID is the numeric part of the filename
    fname = rapi.getLocalFileName(rapi.getInputName())
    fileID = ''.join(c for c in fname if c.isdigit())
    bs = NoeBitStream(data)
    idstring = bs.readUInt()
    if idstring == int(fileID) or idstring == 1213416781: #MESH
        return 1
    return 0

#load the model
def noepyLoadModel(data, mdlList):
   ctx = rapi.rpgCreateContext()
   bs = NoeBitStream(data)
   rapi.rpgClearBufferBinds()   
   
       #fname=@"C:\Users\Xavier\Desktop\a\a\Q01\1.dat"
	#if(fname != null and fname.exists):
	#f = fopen fname "rb"   --open file in read only format
	#actionMan.executeAction 0 "550"  Views: Viewport Visual Style Shaded			
	#FileExtension = 
	#FileName =
	#clearlistener()
	fscale = 50
	#delete $*
	#Print "===================================="
	#print (FileName + FileExtension) as string
	#Print "===================================="
	--)
	meshOffset2 = f.readLong()
	meshOffset3 = f.readLong()

	f.seek("0x10")
	BuildModel(f,fscale)

	f.seek(meshOffset2)
	BuildModel(f,fscale)

	f.seek(meshOffset3)
	BuildModel(f,fscale)

	Print ("Last Read @ 0x"+((bit.intAsHex(f.tell()))as string))	
   
   return 1
   
   
def paddstring(length,instring):
	#instring=instring as string #I suppose you dont need to cast
	strAux = ""   #local str = ""
	if( len(instring) <= length):
		for i in range(1,length-len(instring)):
			strAux += "0"
		strAux = (strAux+instring)	
	else:
		for i in range(1,length):
			strAux += "0"
			strAux[i] = instring[i]
	return strAux

def addHexaDecimalPadding(nr):
	if( nr<= 15):
		return ("0" + hex(nr))
	if(nr > 15):
		return hex(nr)
	
def ReadFixedString(bstream,fixedLen):
	strAux = ""
	for i in range(1,fixedLed):
		str0 = bstream.readUByte()
		if(str0!="0xFD" and str0!="0xFC"):
			strAux += str(unichr(str0))
	return strAux
	
def ReadFixedByteString(bstream,fixedLen,var,var2):
	strAux = ""
	for i in range(0,fixedLen):
		strAux += addHexaDecimalPadding( bstream.readUByte() )
		if( i % 1 == 0):
			strAux += " "	
	#strAux ? what does this mean, a print?
	if(var == 1):
		f.seek(-fixedLen,NOESEEK_REL) #seek_cur
	if(var2 == 1)
		print(strAux)

def printHex(num):
	print(hex(num))
	
def printHere(bstream):
	print("Here 0x" + hex(bstream.tell()))

def getBoundBox(bstream,fscale):
	currBBMax = [bstream.readFloat(),bstream.readFloat(),bstream.readFloat()]*fscale
	currBBMin = [bstream.readFloat(),bstream.readFloat(),bstream.readFloat()]*fscale
	currA = currBBMax - currBBmin
	return currA
	
def GetName(bstream,offset):
	backJump = bstream.tell()
	bstream.seek(offset) #default is beggining file
	strAux = bstream.readString()
	bstream.seek(backJump)
	return strAux
	
def ReadFaces(VertCount,FaceType):
	faceArr = [] #() -- an empty array
	if(FaceType == 1):
		StartDirection = -1
		x= 0
		a=0
		b=1
		
		f1=a+1
		f2=b+1
		FaceDirection = StartDirection
		while(1):
			x += 1
			f3 = x
			FaceDirection *= -1
			if(f1!=f2 and f2!=f3 and f3!=f1):
				if(FaceDirection > 0):
					faceArr.append([f1,f2,f3])
				else:
					faceArr.append([f1,f3,f2])
				f1 = f2
				f2 = f3
			if(x >= VertCount)
				break;
		print(faceArr) #nomap
		
	if(FaceType == 0):
		a = 0
		b = 0
		c = 0
		
		for i in range(1,VertCount,3):
			a=x
			b=x+1
			c=x+2
			faceArr.append([a,b,c])
		
		print(faceArr) #nomap
	return faceArr
	
def BuildModel(bstream,fscale):
	Msh_Vert_array = []
	Msh_Normal_array = []
	Msh_UV_array = []
	Msh_Face_array = []
	Msh_Color_array = []
	MshVertexCount = 0

	ukwFlag = bstream.readLong()
	null = bstream.readLong()
	meshStartFlag = bstream.readLong()
	meshFlag = "0x6c018000" #its a do while
	while( meshFlag == "0x6c018000"):
		Vert_array = []
		UV_array = []
		Normal_array = []
		Face_array = []
		Color_array = []
		
		meshFlag = bstream.readULong()
		vertCount = bstream.readUByte()
		ukw = bstream.readByte() #always 0x80
		null = bstream.readShort()
		bstream.seek(0x10,NOESEEK_REL) #data,look at later
		for x in range(1,vertCount):
			vx = bstream.readFloat()
			vy = bstream.readFloat()
			vz = bstream.readFloat()
			nx = bstream.readFloat()
			ny = bstream.readFloat()
			nz = bstream.readFloat()
			cr = bstream.readFloat()
			cg = bstream.readFloat()
			cb = bstream.readFloat()
			tu = bstream.readFloat()
			tv = bstream.readFloat()
			ukw = bstream.readFloat()
			
			vColor = [cr,cg,cb,0] #color cr cg cb 0
			
			Vert_array.append([vx,vy,vz]*fscale)
			Normal_array.append([nx,ny,nz])
			Color_array.append(vColor)
			UV_array.append([tu,tv,0])
		ukw2 = bstream.readShort()
		ukw3 = bstream.readShort()
		
		Face_array = ReadFaces(vertCount,1)
		for i in range(1,len(Face_array)):
			vertices = Face_array[i]
			Msh_Face_array.append([vertices[1] + MshVertexCount, vertices[2] + MshVertexCount, vertices[3] + MshVertexCount])
		
		MshVertexCount += len(Vert_array)
		for i in range(1,len(Vert_array)):
			Msh_Vert_array.append(vert_array[i])
			Msh_UV_array.append(UV_array[i])
			Msh_Color_array.append(Color_array[i])
			Msh_Normal_array.append(normal_array[i])
		
		try:
			msh = 
			msh.numTVerts = len(Msh_UV_array)
			buildTVFaces msh
			setCVertMode msh true
			setNumCPVVerts msh vertCount
			defaultVCFaces msh
			setShadeCVerts msh true
			for j = 1 to Msh_UV_array.count do setTVert msh j Msh_UV_array[j]
			for j = 1 to Msh_Face_array.count do setTVFace msh j Msh_Face_array[j]
			for j = 1 to Msh_Normal_array.count do setNormal msh j Msh_Normal_array[j]
			for j = 1 to Msh_Color_array.count do setVertColor msh j Msh_Color_array[j]
			msh.transform = (matrix3 [-1,0,0] [0,0,1] [0,-1,0] [0,0,0])
			for j in range(1,len(Msh_UV_array)):
				
			for j in range(1,len(Msh_Face_array)):
			
			for j in range(1,len(Msh_Normal_array)):
			
			for j in range(1,len(Msh_Color_array)):
				
			#...
		except:
			#delete msh
		

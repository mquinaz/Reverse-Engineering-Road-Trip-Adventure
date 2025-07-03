# Reverse Engineering PS2 Road Trip Adventure (ChoroQ HG-2)

<img align="right" src="https://github.com/user-attachments/assets/d0b0dddc-e5f2-4bc8-b4e1-a9477bdc84da" alt="image" width="256" />
Out of the love for both this game and computer graphics, an attempt to analyze, understand and extract all possible data from it (Models, textures, audio, font...).

Started it on 2017 but rather than properly doing the work, I just depended on the help from people in Xentax, Zenhax to make the developments I needed, time has come to actually try it.

<br/><br/>

<br/><br/>

<br/><br/>
<br/><br/>

## File structure 

Game ISO directory and its files types of extension:

```bash
├── action
│   ├── .bin
├── car0
│   ├── .bin
├── car1
│   ├── .bin
├── car2
│   ├── .bin
├── car3
│   ├── .bin
├── car4
│   ├── .bin
├── cars
│   ├── .bin
├── course
│   ├── .bin
├── fld
│   ├── .bin
├── item
│   ├── .gsl
├── shop
│   ├── .bin
├── sound
│   ├── .vag / .tsq / .tvb
├── sys
│   ├── .bin / .gsl / .ico / .e3d
└── 
```

<details>
  <summary>Analysis of Directories</summary>
  
## action

## Car0 - Car1 - Car2 - Car3 - Car4

Q*.bin(1-150) files present in these Car* directories which **represent a different car model.**

### subfile 1 - 6

Splitting any archive For Car* directories will generate 7 different subfiles, the first 6 have 3D data information (TODO)

### subfile 7

The last file is a texture for a specific car. (TODO since it has probably a CLUT)

## course

## fld

## item

This directory consists of textures METER*, PARTS of ingame meter system and the shop 

## shop

## sound

## sys
  
</details>

## Archive

Older console games like PS2 tend to have restrictions on size of files, e.g. lower vertex data from models, and it is common to pack different data like textures, 3D data, etc, together into one big archive file (reduce number of files in CD, stop people from hacking the game, access all data from one stream). 

![q_bin_analysis](https://github.com/user-attachments/assets/a69f4469-ed07-46f8-a362-259aa80025df)

Each archive file have a 48 byte header:
- Starting with 4 byte pointers offsetting each sub-file (e.g. texture, 3D data); (7 pointers (28 bytes) = 7 sub-files )
- 4 byte value representing the size of the whole file (highlighted in yellow (uint32 = file size))
- 4 blocks of 4 bytes of padding

## Texure

A similar format is found for textures like TM2 (PlayStation 2 texture format) (https://openkh.dev/common/tm2.html).

TODO (finish analyze header)

Each texture file have a 70 byte header:
- Starting with 4 byte pointers for version of texture 0x1012, 0x1040, 0x1087
- 4 byte padding
- ...

After each header we have chunks of data without any palletted information, meaning RGBA each pixel color component is 1 byte, so for each pixel we have 32 bits.

![roadTripMap](https://github.com/user-attachments/assets/aef85bba-9905-4e7d-b477-271e2740d4fb)




### THIS ARTICLE IS STILL UNDER CONSTRUCTION
#### Goal
```
The main goal of the article is to summarize methods and techniques what you can use to extract 3D Models 
and Textures from a PS2 game named Road Trip Adventure. For further reading, I will provide additional, explanatory 
links as the article progress for a better understanding.
```
# Reverse-Engineering-Road-Trip-Adventure

## Introduction 

There are already a few methods of how to grab or export models with textures from any game or application. I would like to divide them into two main groups:

* [Lethal way](#lethal-way)

  Example of usage:
  * [Graphics analyzers](#graphics-analyzers)
  * [Ripper tools](#ripper-tools)
  * [Comparing Data](#comparing-data)
* [Non-lethal way](#non-lethal-way)
  * [Photogrammery method](#photogrammery-method) + Example of usage
  * [Game Modding](#game-modding)
##### Bonus: (This section will come)
* [Own tool](#own-tool)
  * [Prerequisities]()
  * [Theory]()
    * [What is a "data"]()
    * [Trial and error]()
  * [Writing Export Tool]()
    * [Research]()
    * [Execution]()
  * [Writing Ripper Tool]()
    * [Research]()
    * [Execution]()

There is many ways and reasons how or why you want to use obtained data:
* **Personal usage:** Just play with it around for a fun.
* **Study how GFX is made:** 3D geometry topology, UV-Maps, level design, etc...
* **Study how Game engine functions:** Mostly for a viewing rendering optimizations. Check this study of [GTA 5 Rendering engine](http://www.adriancourreges.com/blog/2015/11/02/gta-v-graphics-study/) made by Adrian Courrèges.
* **To learn programming:** Use assets for rendering models, textures because no one wants to look whole life on textured CUBE.
* **Optimizing  speed-runs:** Some tools can get/show trigger which are represented by boxes. This can be used to find an exploit.
* **3D printing:** For example just follow [this instructions!](https://www.instructables.com/id/3D-Printing-Models-from-video-game/)
* **Creating an impressive video:** Known as "3D Edit" for example [CS:GO 3D-Edit like NikkyHD, Fuze or maro2k8!](https://www.youtube.com/watch?v=R-fq8o4Do3g)
* **Modding a game:** 
  * Total conversion: For example [Duke Nukem 3D 'Forever' in Serious Sam 3](https://www.youtube.com/watch?v=BDSUeD-WErY)

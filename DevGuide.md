# Development Guide #

For proper compiling here are some important thing. I made a dev package with the required headers and libraries in case you do not want to put all the things together by yourself. It is available under the Releases link.

**GLEW**
Using the newest features of OpenGL or at least the 3.0 version, this library is needed. I had some trouble with the original release, because of MinGW compiler. I recompiled the GLEW source, so I can use the glew32.dll with MinGW. Or you can use MSVC, so the original GLEW binary release will be perfect.

**SDL** For creating window and handling keyboard. There is a great tutorial on how to install it: http://lazyfoo.net/SDL_tutorials/lesson01/index.php

**IDE** Code Blocks 12.11 + MinGW compiler. It isn't necessary, using other IDE is ok. http://www.codeblocks.org/

**GLM** For matrix calculations. Just put the source code in to the project folder, next to the main source code. In the Graphics.h you can see the include path to glm.hpp and to other glm headers. http://glm.g-truc.net/0.9.4/index.html

**OpenGL Tutorial** There is this great site http://www.opengl-tutorial.org/ where I understood the concept of the OpenGL 3.3. I'm using some code from it and I separated it from the original code.

### Code Blocks Setup Guide - headers and libraries ###

  1. Download the dev package (Releases link)
  1. Download and install Code Blocks. You need the mingw package!
  1. Copy the devpackage/include/GL content into <Code Blocks install dir>/MinGW/include/GL
  1. Copy the devpackage/include/SDL dir into <Code Blocks install dir>/MinGW/include/
  1. Copy the devpackage/lib/ content into <Code Blocks install dir>/MinGW/include/lib
  1. Copy the devpackage/ glew32.dll and SDL.dll into <Code Blocks install dir>/MinGW/bin

Note: the SDL files are not complete, if you want to use other features (image loader) you should download the full package. http://www.libsdl.org/

Note: glew32.dll and SDL.dll are needed for running the executable. If you compile and run it from Code Blocks it will be ok. If you want to run it independently, you will need put these two dll next to the exe or copy into the Windws/system32 folder.

### Code Blocks Setup Guide - creating the project ###

  1. Start Code Blocks:)
  1. File/New/Project... then select Console application
  1. On the next page select C++ , name you project, change the project dir if you want, than Finish
  1. Right click on project name and click Build options...
  1. On the Linker settings tab add the following keywords to the left window (one by one): mingw32, direct path to the glew32.dll, opengl32, SDLmain, SDL
  1. Copy the source code into the project folder
  1. Copy the devpackage/lib\_3rd\_party dir into the project folder, next to the source files
  1. Right click on project name and Add files..., select all the source files
  1. You may need to add the shader.hpp and shader.cpp too
  1. Now you can Build your project
  1. Don't forget to save the project (File/Save project), because if you don't, next time you open it, all the options and source file won't be there.

I hope it will help build the project. In case of any problems or ideas, feel free to contact me!
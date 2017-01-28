OpenGL Modern Graphics Learning Project
---------------------------------------
This repository contains all the code that I'm writing for experimenting with openGL and also contains extensive notes disguised as comments on how some of the functions of OpenGL work and explain the lines of communication the program has with the GPU.

### Setup:
You need the following libraries:
* `cmake`
* `SDL2`
* `GLEW`
* `GLM`

CMake recommends out of directory builds, so it's a smart idea to make a new directory
(I'm calling it `build`) and run the following command from there:
```
cmake ..
make
```

> Note: These instructions are for Mac and Linux, Windows/Visual Studio details
coming soon.

In action:
![Suzanne Demo](res/demo.gif)


### Tools:
<strong>IDE: </strong>Visual Studio 2013  
<strong>Libraries: </strong>GL Mathematics, GLEW, Simple Directmedia Library.  
<strong>Languages: </strong>C, C++, OpenGL Shader Language.

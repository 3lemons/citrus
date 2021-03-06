# Citrus
A game engine written in C.

## Purposes of this project
I'm not a game developer. I'm not even really a massive gamer; I enjoy a bit of causal gaming on my PS3 when I'm at a loose end. From the development side-of-things, my experience is primarily with web apps.
With that backdrop, bizarrely, I've decided to undertake the project of developing a game engine with the primary goal being education. A little while back I learnt the C programming language and was very drawn to it's diy, low-level, powerful and performant qualities. I liked the challenges that come with the C programming language. So I've decided to have a go at writing a game engine in this language to develop my proficiency.
I am developing this engine under the organisation [3lemons](https://github.com/3lemons) so have opted for the name 'Citrus', to continue the lemon theme and also as a reference to the language in which the engine is written.
I imagine I may not get to the end of project, and that's okay. I'm sure I will have learnt a lot along the way and it will help me tackle future problems, both in C and in other languages. If I get a working engine out of this that would be an added bonus, and if it's put to use in other people's game development: even better.
Therefore, I'm going to make no promises when it comes to supporting and maintaining this engine. That said, if anyone has any suggestions or find any bugs, feel free to raise them through the [issue tracker](https://github.com/3lemons/citrus/issues) and I'll do my best to look at them. If you wish to contribute, you are more than welcome and I'm sure I will learn a lot from what you have to offer.
Here goes nothing! But more importantly, let's have some fun!

## The scope of the Engine
From the initial research I've done into game engines it appears, quite understandably, that the more complexity the engine has, the longer it takes to write.
Therefore I intent to implement the following:
- Window Management 
- Logging
- File I/O
- 2D graphics rendering using OpenGL
- Physics and Collision detection

The following features will remain outside of the scope of the engine.
- Networking and multiplay
- 3D graphics
- Level editor tools

## <a name="building"></a>Building from source

### Dependencies
To build Citrus, you will first need [cmocka](https://cmocka.org/) installed on your development environment. If you are on Linux, you should be able to install this through your respective package manager. It is also available through [brew](https://formulae.brew.sh/formula/splint). If you do install it this way, you need to make sure that your brew's include and lib directories are in the C compiler's paths. This might not be an issue, depending on how you install brew. If brew's include and lib directories are not in your compiler's paths, you can include them by adding the following lines to the CMakeLists.txt file:

```
target_include_directories(${PROJECT_NAME} PUBLIC /path/to/brew/include/directory)
link_directories(${PROJECT_NAME} PUBLIC /path/to/brew/lib/directory)
```

To build this engine from source run the following at the top level of this directory
```
if [ ! -d build ]
then
    mkdir build
fi
cd build && cmake .. -DCMAKE_BUILD_TYPE=Release
```

To build in Debug mode run the following cmake command in the build directory instead
```
cmake .. -DCMAKE_BUILD_TYPE=Debug
```

To build everything (Citrus and unit test) simply run:
```
make
```

To build just the engine and not the unit tests run:
```
make Citrus
```

## Running unit tests
Assuming you have build the engine and tests (see [Building from source](#building)), run the following executable within the build directory
```
./CitrusTests
```
These unit tests will be run as part of the CI
### N.B
Unit tests use [cmocka](https://cmocka.org/) for the testing framework so you will need to download this framework in order to build the tests if you don't already have it.

## Linter
To lint this C source files in both the src and test directories, run the following script
```
./linter.sh
```
This linter shell script runs cmake first to ensure all header files are created (including header generated from .h.in files) then runs [splint](https://splint.org/) on the source files.

If you don't already have splint, you'll need to install it for your respective OS. For Linux users, it will likely be found in your package manager, and is also available through [brew](https://formulae.brew.sh/formula/splint)

Linting will be run as part of the CI

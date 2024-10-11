<h1 align="center"> 
    🌀 fract-ol 
</h1> 

<p align="center"> 
  <img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/jose5556/fract-ol?color=lightblue" /> 
  <img alt="Code language count" src="https://img.shields.io/github/languages/count/jose5556/fract-ol?color=yellow" /> 
  <img alt="GitHub top language" src="https://img.shields.io/github/languages/top/jose5556/fract-ol?color=blue" /> 
  <img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/jose5556/fract-ol?color=green" /> 
</p>

# 💡 About the project

Fract-ol is a project completed during my studies at School 42. 
The goal of this project is to explore and render various types of fractals using a graphical library (MiniLibX). 
The program allows for real-time interaction with fractals, including zooming, shifting, and customizing color schemes.

# 🔍 Overview

This project implements the rendering of mathematical fractals such as the Mandelbrot set, Julia set and the Barnsley Fern. 
It allows for smooth zooming and color transitions, offering users the ability to explore the depth of fractal patterns. 
The fractals are displayed in an interactive window, where users can navigate with keyboard and mouse inputs.

### Some Key Features

    Real-time zoom using mouse whell
    Multiple fractal types
    Adjustable iterations for more detail
    100% customizable color schemes for psychedelic effects

For more detailed implementation information, see the project subject that is among the uploaded files.

# 🛠️ Usage

### Requirements

The project is written in C and requires the cc compiler.

### Instructions

1. Compiling the library

To compile the fractal viewer, run the following command in the project directory:

```shell

$ make
```

2. Running the program

Once compiled, run the program and specify which fractal you want to explore:

```shell
$ ./fractol <fractal_name>
```

Examples of fractal names available to be presented on the program:

    mandelbrot
    julia
    fern

### Example:

```shell
$ ./fractol mandelbrot
```
Note that if you chose the julia set to be displayed, you must explicitly put in the desired arguments (x and y coordinates) that you want in order to see the exact julia set you have in mind.
See more julia types sets [here]([https://example.com](https://pt.wikipedia.org/wiki/Conjunto_de_Julia)).

```shell
$ ./fractol julia -0.835 -0.2321
```
This will open a window displaying the fractal on the argument. You can interact with it by using your mouse to zoom, keyboard arrows to move around the fractal and numbers/space buutons to customize collors..

3. Controls

    <h4> -> Mouse wheel for a real time and infinity zoom (zoom in, and zoom out); </h4>
    <h4> -> Keybord numbers (0 till 9) and space bar to customize the exact collors you want; </h4>
    <h4> -> Try pressing the minos buttom ("-") to see some crazy stuff happening with the collors, press the equal buttom ("=") to come back to normal; </h4>
    <h4> -> Plus buttom ("+") to add more iterarions and see a more clear image. </h4>


# 📌 Note

Make sure you have the necessary MiniLibX library installed.
Barnsley Fern is a probability fractal, so you cant zoom in.
The project supports multiple fractal types, each with crazy and unique characteristics. Experiment with different settings to discover fascinating fractal details!

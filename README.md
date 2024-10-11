<h1 align="center"> 
    🌿 fract-ol 
</h1> 

<p align="center"> 
  <img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/jose5556/fract-ol?color=lightblue" /> 
  <img alt="Code language count" src="https://img.shields.io/github/languages/count/jose5556/fract-ol?color=yellow" /> 
  <img alt="GitHub top language" src="https://img.shields.io/github/languages/top/jose5556/fract-ol?color=blue" /> 
  <img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/jose5556/fract-ol?color=green" /> 
</p>

## 💡 About the project

Fract-ol is a project completed during my studies at School 42. 
The goal of this project is to explore and render various types of fractals using a graphical library (MiniLibX) provided by school 42. 
The program allows for real-time interaction with fractals, including zooming, shifting, and customizing color schemes.

## 🔍 Overview

This project implements the rendering of mathematical fractals such as the Mandelbrot set, Julia set and the Barnsley Fern. 
It allows for smooth zooming and color transitions, offering users the ability to explore the depth of fractal patterns. The fractals are displayed in an interactive window, where users can navigate with keyboard and mouse inputs.
Key Features

    Real-time zoom and pan functionality
    Mouse-controlled zoom that follows the cursor position
    Multiple fractal types and color schemes
    Adjustable iterations for more detail
    Customizable color transitions for unique visual effects

For more detailed information about the implementation, please refer to the project files and documentation.
🛠️ Usage
Requirements

The project is written in C and requires the cc compiler. The program uses the MiniLibX graphical library to handle the window, rendering, and user inputs.
Instructions

1. Compiling the program

To compile the fractal viewer, run the following command in the project directory:

shell

$ make

2. Running the program

Once compiled, run the program and specify which fractal you want to explore:

shell

$ ./fractol <fractal_name>

Examples of fractal names:

    mandelbrot
    julia
    burningship

Example:

shell

$ ./fractol mandelbrot

This will open a window displaying the Mandelbrot fractal. You can interact with it by using your mouse to zoom and keyboard arrows to move around the fractal.

3. Controls

    Arrow keys: Pan left, right, up, or down
    Mouse scroll: Zoom in/out
    Keyboard +/-: Increase/decrease iterations
    Space: Change color schemes

Note

Make sure you have the necessary MiniLibX library installed. The project supports multiple fractal types, each with unique characteristics. Experiment with different settings to uncover fascinating fractal details!

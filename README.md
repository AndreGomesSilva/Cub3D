# Cub3D

Cub3D is a 3D game engine project based on the principles of raycasting. This project is currently a work in progress and aims to create a simple 3D game similar to Wolfenstein 3D.

## Table of Contents

- [About](#about)
- [Features](#features)
- [Installation](#installation)
- [How to Play](#how-to-play)
- [Initialize](#initialize)

## About

Cub3D is a project that demonstrates the basics of 3D rendering using raycasting techniques. The project is being developed as part of a learning process and is inspired by early 3D games. The primary goal is to understand and implement core concepts of 3D graphics and game development.

## Features

- Raycasting engine to simulate 3D perspective
- Basic movement and collision detection
- Simple texture mapping


https://github.com/user-attachments/assets/66a913ba-4585-4737-9041-3cdb217acaa9


## Installation

To install and run Cub3D, follow these steps:

1. Clone the repository:
    ```bash
    git clone https://github.com/andregomessilva/cub3d.git
    ```
2. Navigate to the project directory:
    ```bash
    cd Cub3D
    ```
3. Build the project using `make`:
    ```bash
    make
    ```

*Note: Ensure you have the necessary development tools and libraries installed on your system.*

## How to Play

In Cub3D, you can control your movement using the following keys:

- **W**: Move forward
- **A**: Move left
- **S**: Move backward
- **D**: Move right
- **ESC**: End game

You can also use the mouse or arrows to rotate your view and look around.

## Initialize

To run the Cub3D application, execute the following command in the project directory:

```bash
make play
```
or this way for the map you want
```bash
./cub3d maps/map.cub
``` 

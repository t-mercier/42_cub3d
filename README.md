# cub3D

<table>
  <tr>
    <td>
      <img src="https://github.com/t-mercier/42_cub3d/assets/94700601/f1e11f6e-026f-4451-8f4e-0cf4688108eb" alt="madhouseGH">
    </td>
    <td>
      <img src="https://github.com/t-mercier/42_cub3d/assets/94700601/39ae137b-f3ed-4ed8-a92a-8bc4a2219f12" alt="bunker">
    </td>
  </tr>
</table>

## Overview
`cub3D` is a collaborative project I developped with my friend, inspired by the classic game "Wolfenstein 3D". The goal is to create a functional raycasting engine in C, rendering a 3D maze from a 2D map for an immersive first-person experience.

## Team
- **Timothée**: Focused on raycasting, developped the rendering part of the project.
- **Alfa**: Handled the map parsing and related functionalities.

## Features
- Raycasting engine for 3D maze rendering.
- First-person navigation.
- Textured walls and sprite rendering.
- Map parsing from `.cub` files.
- Collision detection and adjustable player movements.

## Technologies
- C language and Raycasting principles.
- 42 Minilib MLX graphics library.

## Submodule Initialization and Update

To  within this project, run the following command:

## Installation and Usage
1. Clone the repository.
2. Initialize and update submodules `git submodule update --init`
3. Compile with `make`
4. Run with `./cub3D maps/<map>`

## Map Configuration
- The `.cub` file defines the map layout, textures, and other settings.

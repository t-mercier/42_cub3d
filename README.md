# cub3D

<table>
  <tr>
    <td>
      <img src="https://github.com/t-mercier/42_cub3d/assets/94700601/39ca786a-6768-4ae7-96fb-ff0f108cd92b" alt="madhouseGH">
    </td>
    <td>
      <img src="https://github.com/t-mercier/42_cub3d/assets/94700601/4f5dc98b-c286-4949-a253-557ab59c6640" alt="bunker">
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

## Installation and Usage
1. Clone the repository.
2. Compile with `make`.
3. Run with `./cub3D maps/<map>`.

## Map Configuration
- The `.cub` file defines the map layout, textures, and other settings.

# 🕹️ cub3D

cub3D is a 3D graphics project from the 42 curriculum.  
The goal is to create a basic 3D game using raycasting, inspired by early games like Wolfenstein 3D.

---

## 📖 About the Project

cub3D renders a 3D environment from a 2D map using a raycasting technique.

The player can move through the map and view the world from a first-person perspective.

This project focuses on:

- Raycasting
- Graphics programming
- Mathematical calculations (vectors, angles)
- Event handling
- Map parsing

---

## ⚙️ Features

- First-person 3D view using raycasting
- Player movement (forward, backward, rotation)
- Wall rendering with textures
- Map parsing from `.cub` file
- Basic collision detection

---

## 🎮 Controls

- `W` / `S` – move forward / backward  
- `A` / `D` – move left / right  
- Arrow keys – rotate view  
- `ESC` – exit the program  

---

## 🎥 Gameplay Video

[cub3d.webm](https://github.com/user-attachments/assets/c96c329c-c288-4177-8882-1006f159b6b3)

---

## 📦 Installation

Clone the repository:

```bash
git clone https://github.com/Mert5558/Cub3d.git
cd Cub3d
```

Compile the project:

```bash
make
```

---

## 🚀 Usage

Run the program with a map file:

```bash
./cub3D map1.cub
```

---

## 🗺 Map Format

The map is defined in a `.cub` file and must:

- Be surrounded by walls
- Contain exactly one player position
- Include valid texture paths and colors

Example:

```
111111
100001
10N001
100001
111111
```

---

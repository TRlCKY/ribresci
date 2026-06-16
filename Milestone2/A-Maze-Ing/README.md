# A Maze Ing  
*Project created as part of the 42 curriculum by fbinchi & ribresci*

---

# Overview

**A Maze Ing** is a modular framework for the **generation**, **solving**, and **visualization** of mazes.  
The project name is a wordplay (“amazing” → “a maze ing”), reflecting the goal of providing a simple yet powerful environment for experimenting with *maze generation* and *pathfinding* algorithms.

The system is composed of three main modules:

- **Generator** — creates mazes through a customizable algorithm  
- **Solver** — computes a valid path from entry to exit  
- **Renderer** — produces a visual representation of the maze  

All modules are orchestrated by `a_maze_ing.py` and configured through external configuration files.

---

# Installation & Requirements

To run the project you need:

- Python **3.10+**
- The dependencies listed in `requirements.txt`

## Install dependencies

```bashffbinchi

pip install -r requirements.txt
```

# mazegen — Reusable Maze Generator

## Installazione
```bash
pip install mazegen-1.0.0-py3-none-any.whl

---

# Makefile

The project includes a Makefile with useful commands:

| Command | Description |
|----------|-------------|
| `make install` | Automatically installs dependencies |
| `make run` | Executes `a_maze_ing.py` |
| `make clean` | Removes temporary/build files |

---

# Project Structure

```text
project/
├── a_maze_ing.py
├── output_file/
│   ├── *.txt
├── mazegenerator/
│   ├── generator.py
│   └── solver.py
├── renderer/
│   ├── data.txt
│   └── output_file_renderer.py
├── config/
│   └── config.txt
├── README.md
├── requirements.txt
└── Makefile
```

---

# Usage

The main executable is:

```bash
python a_maze_ing.py config/config.txt
```

or simply:

```bash
make run
```

If the program does not receive **exactly one** configuration file as argument, it exits with an error.

---

# **Come buildare il pacchetto**

Da dentro la root del progetto:

```bash
pip install build
python3 -m build

---

# Configuration File

The file `config/config.txt` must contain **exactly 6 parameters**:

```text
WIDTH=<int>
HEIGHT=<int>
ENTRY=<x.y>
EXIT=<x.y>
PERFECT=<0|1>
OUTPUT_FILE=<filename>
```

## Validation Rules

- `WIDTH * HEIGHT >= 63`
- `ENTRY != EXIT`
- `ENTRY` and `EXIT` cannot overlap the `"42"` pattern
- `PERFECT = 1` → generates a perfect maze  
- `PERFECT = 0` → generates an imperfect maze  

---

# General Workflow

After reading the configuration file:

1. A random seed is generated  
2. A `MazeGenerator` object is created  
3. The maze grid is initialized via `_init_grid()`  
4. Prim’s algorithm is applied through `_prim_algorithm()`  
5. The solver computes a valid path  
6. The maze is rendered and exported to file  

---

# Interactive Menu

After the first maze generation, an interactive menu is displayed:

1. Generate a new maze  
2. Show/Hide shortest path  
3. Change wall color  
4. Seed management  
5. Exit  

## Menu Features

### 1 — Generate a New Maze

- Uses a new random seed  
- Reloads the configuration file  
- Rebuilds the entire grid  

### 2 — Show/Hide Shortest Path

- Hidden mode → displays only the maze structure  
- Visible mode → highlights the shortest path  

### 3 — Change Wall Color

Available colors:

- White  
- Magenta  
- Cyan  

### 4 — Seed Management

- Set a custom seed manually  
- Display the current seed  

### 5 — Exit Program

Terminates execution safely.

---

# Maze Generation Algorithm

## Selected Algorithm: Randomized Prim’s Algorithm

### Why Prim’s Algorithm?

- Produces **perfect mazes** (single valid solution path)
- Easy to implement and maintain
- Stable and predictable behavior
- Allows controlled introduction of imperfections/cycles

---

# MazeGenerator — Core Functions

| Function | Description |
|----------|-------------|
| `_init_grid()` | Initializes the 2D maze grid |
| `_open_wall_between()` | Removes walls between adjacent cells |
| `make_imperfect()` | Adds cycles and alternative paths |
| `generate()` | Reusable generation entry point |

---

# Solver

The solver is based on a generic **Breadth-First Search (BFS)** implementation for grids.

## Main Features

- Computes the shortest valid path
- Traverses the maze efficiently
- Reconstructs the final route through `path_reveal()`

### `path_reveal()`

Rebuilds the solution path using tuples in the form:

```python
(y, x, y_prev, x_prev)
```

---

# Renderer

## Main Functions

| Function | Description |
|----------|-------------|
| `output_file()` | Compact maze export to file |
| `print_labyrinth()` | ANSI terminal rendering |

The renderer supports colored terminal output and optional path visualization.

---

# Team & Project Management

## fbinchi

- Generator  
- Renderer  
- `a_maze_ing.py`

## ribresci

- Solver  
- `"42"` pattern logic  
- Interactive menu  

## Shared Contributions

- `output_file_renderer`
- Makefile
- Requirements management

---

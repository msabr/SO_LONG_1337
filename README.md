# **so_long - 42 Network**  

## **Overview**  
**so_long** is a small **2D game** built using **MiniLibX (mlx)**. This project introduces fundamental concepts of **game development**, such as **textures, sprites, tiles**, and **player movement**. The game is based on a **tile-based map system**, and the objective is to navigate through the map while interacting with various elements.  

## **Project Scope**  
In this project, you will:  

- Use **MiniLibX** to create a game window and render graphics.  
- Load and display **textures** for walls, collectibles, and the player.  
- Work with **sprites** to create movement animations.  
- Implement a **tile-based map system** for level design.  
- Handle **keyboard inputs** for player movement.  
- Detect **collisions** and manage game events (e.g., collecting items, reaching the exit).  

## **Learning Outcomes**  
- Understanding **2D rendering** and **image manipulation** in C.  
- Working with **MiniLibX** for graphics programming.  
- Managing **player movement** and **collision detection**.  
- Handling **event-driven programming** with keyboard inputs.  

## **Usage**  
### How to Build and Run

1. Clone the repository:

   ```bash
   git clone https://github.com/msabr/SO_LONG_1337
   cd SO_LONG_1337

2. Build the mandatory part:

   ```bash
   make

3. Run the game with a `.ber` map file:

   ```bash
   ./so_long maps/<map_name>.ber

4. Build the bonus part (optional):

   ```bash
   make bonus

5. Run the bonus game:

   ```bash
   ./so_long_bonus maps/valid_map_bonus.ber

#### Additional commands

- `make clean`: remove object files.
- `make fclean`: remove the program and object files.
- `make re`: rebuild everything.

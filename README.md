# cub3d

First-person 3D representation of a maze using raycasting, similar to Wolfenstein 3D (1992).

### Prerequisites

The project runs using the MiniLibX, a simplified version of the Xlib. It can therefore only run in MacOSX, preferably on a computer with a solid CPU !

### How to run it

Using ``make test`` will make and run the mandatory part.

You can also use ``make`` to generate the ``cub3D`` executable. You can launch it with ``./cub3D map/map.cub``.

### Controls

You can move around the maze with ``W`` ``A`` ``S`` ``D``.

You can also rotate the view with the directional arrows ``←`` and ``→``.

To exit the game, press ``ESC`` or click the red cross.

### The mandatory part

The basic program that was required to pass. It only includes wall textures and a sprite ; no floor/ceiling textures, no weapons, no enemies, no game elements at all.

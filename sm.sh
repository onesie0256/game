#!/bin/bash

gcc $1.c colors.c -lSDL -L/usr/lib -lSDL_gfx  -lSDL_ttf -lSDL_mixer -o $1
#-lSDL_gfx-lSDL_ttf
#gcc $1.c -lSDL -lSDL_image -L/usr/lib
#gcc $1.c -lSDL -lSDL_mixer -L/usr/lib
#gcc $1.c -lSDL -lSDL_net -L/usr/lib
#gcc $1.c -lSDL -lGL -L/usr/lib

./$1

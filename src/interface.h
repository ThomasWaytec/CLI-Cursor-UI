#ifndef INTERFACE_H
#define INTERFACE_H

#include "controls.h"

#define STD_HANDLE GetStdHandle(STD_OUTPUT_HANDLE)

void draw_grid(const size_t GRID_HEIGHT, const size_t GRID_LENGTH, char*** grid, const size_t BASE_PADDING);

Cursor live_grid(const size_t GRID_HEIGHT, const size_t GRID_LENGTH, char*** grid);

#endif

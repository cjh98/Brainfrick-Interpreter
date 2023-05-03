#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MEMORY_CELLS 2048

char *load_source(const char *);
void decode_execute(const char *);

// instructions
void move_pointer_right();
void move_pointer_left();
void inc_mem_cell();
void dec_mem_cell();
void ouput_char();
void input_char();
size_t jump_forward(const char *, size_t);
size_t jump_back(const char *, size_t);
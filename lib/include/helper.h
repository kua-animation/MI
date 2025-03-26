#ifndef HELPER_H
#define HELPER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void MI_print(int x, int y, char* text);

void MI_sleep(float time); 

void MI_square(int x, int y, int w, int h, char X, float time);

void MI_hiden_input(int x, int y, const char* prompt, char** code);

void MI_move_cursor(int x, int y);
void MI_hide_show_cursor(int show);
#endif

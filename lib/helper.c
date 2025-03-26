#include "include/helper.h"

void MI_move_cursor(int x, int y) {
	printf("\033[H");

	if (x > 0) {
		printf("\033[%dC", x);
		fflush(stdout);
	}

	if (y > 0) {
		printf("\033[%dB", y);
		fflush(stdout);
	}
}
void  MI_print(int x, int y, char* text) {

	MI_move_cursor(x, y); 	

	printf("%s", text);
	fflush(stdout);

	return;
}

void MI_sleep(float time) {
	if (time == 0) {
		return;
	}

	int Mictosecond = 1000000;

	int NewTime = time * Mictosecond;

	if (NewTime <= Mictosecond)  {

		usleep(NewTime);

	} else {
	
		sleep(NewTime/Mictosecond);
		usleep(NewTime%Mictosecond);
	}

	return;

}

void MI_square(int x, int y, int w, int h, char X, float time) {

	char *line = malloc(w + 1);
	for (int i = 0; i < w ; i++) {
		line[i] = X;
	}
	line[w] = '\0';
	for (int i = 0; i < h; i++) {
		MI_print(x, y+i, line);
		fflush(stdout);
		if (time != 0) {
			MI_sleep(time/h);
		}
	}

	free(line);

	return; 
}

void MI_hide_show_cursor(int show) {
	if (show) {
		printf("\033[?25h");
		fflush(stdout);
	} else {
		printf("\033[?25l");
		fflush(stdout);
	}
}

void MI_hiden_input(int x, int y, const char* prompt, char** code) {

	MI_move_cursor(x, y);
	*code = getpass(prompt);
}

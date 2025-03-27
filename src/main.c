#include "../lib/include/Mi.h"
#define MAX_VAR 3

int main(int argc, char* argv[]) {

	if (argc < 2) {
		exit(0);
	}

	FILE *file = fopen(argv[1], "r");

	if (!file) {
		printf("file dosn't exist"); 
		exit(0); }
	

	int LineCount = 0;
	for (char c = getc(file); c != EOF; c = getc(file)) {
		if (c == '\n') {
			LineCount ++;
		}
	}

	fseek(file, 0, SEEK_SET);

	const int lineNumber = LineCount;

	int *IntFileContext = malloc(lineNumber * sizeof(int));

	nuber_file_content(file, IntFileContext);

	int vars[MAX_VAR];

	int t;
	for (int i = 0; i < lineNumber; i++ ) {
		switch(IntFileContext[i]) {
		case 100:
			printf("%c", vars[0]);
		break;
		case 101:
			printf("%c", vars[1]);
		break;
		case 102:
			printf("%c", vars[2]);
		break;
		
		} 
		if (IntFileContext[i] <= 110+126*MAX_VAR && IntFileContext[i] > 110) {
			for (int j = 0; j < MAX_VAR; j++) {
				t = IntFileContext[i] - (110+126*j);
				//printf("%d %d\n", IntFileContext[i], t);
				if (t <= 126) {
					//printf("a");
					vars[j] = t;
					break;
				}
			}
		}
	}


	fclose(file);
	free(IntFileContext);

}

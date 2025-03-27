#include "include/helper.h"


void nuber_file_content(FILE *file, int *intFileContext) {
	int lineNumberCount = 0;
	char *fileContext = malloc(128);
	while (fgets(fileContext, 128, file)) {

		for (int i = 0; i < strlen(fileContext); i ++) {
			if ((int)fileContext[i] != 10) {
				intFileContext[lineNumberCount] += (int)fileContext[i];
			}
		}


		lineNumberCount ++;
	}

	free(fileContext);
}

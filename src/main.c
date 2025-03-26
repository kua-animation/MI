#include "../lib/include/Mi.h"
#include <string.h>
int main(int argc, char* argv[]) {

	if (argc < 3) {
		exit(0);
	}

	FILE *file = fopen(argv[1], "r");

	if (!file) {
		printf("file dosn't exist"); 
		exit(0);
	}
	
	int lineNumber = atoi(argv[2]);

	int lineNumberCount = 0;
	int *ifileContext = malloc(lineNumber * sizeof(int));
	char *fileContext = malloc(128); 


	while (fgets(fileContext, 128, file)) {

		for (int i = 0; i < strlen(fileContext); i ++) {
			if ((int)fileContext[i] != 10) {
				ifileContext[lineNumberCount] += (int)fileContext[i];
			}
		}


		lineNumberCount ++;
	}
	for (int i = 0; i < lineNumber; i++ ){
		printf("line number %d = %d\n", i, ifileContext[i]);
	}
	

	fclose(file);
	free(ifileContext);
	free(fileContext);

}



#include<stdio.h>
#define FILEPATH "pyramid.txt"


int main() {

    // Create File pointer
    FILE *filepointer;
    filepointer = fopen(FILEPATH, "w+");
    //Check for Errors
    if (filepointer == NULL)
    {
        printf("Could not open file");
        return 0;
    }
    // Solution to Section 6.69 (o)
	for (int i = 1; i <= 10; i++) {
		for (int k = 10; k > i; k--) {
			fprintf(filepointer," ");
		}

		for (int j = i; j < 2 * i - 1; j++) {
			fprintf(filepointer,"%d", j % 10);
		}

		for (int j = 2 * i - 1; j >= i; j--) {
			fprintf(filepointer,"%d", j % 10);
		}
		fprintf(filepointer,"\n");
	}
    printf("Successfully wrote into %s", FILEPATH);
	printf("Closing %s", FILEPATH);
	// Close File
	fclose(filepointer);
	return 0;
}

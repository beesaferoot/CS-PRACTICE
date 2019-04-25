#include<stdio.h>
#define FILEPATH "weightedAverage.txt"
// Solution to Section 6.69 (a)
double weightedAvearange(double f[], double x[], int n) {

	double average = 0.0;
	for (int i = 0; i < n; i++) {
		average += f[i] * x[i];
	}
	return average;
}

int main()
{
	double f[10] = {0.06, 0.08, 0.08, 0.10, 0.10, 0.10, 0.12, 0.12, 0.12, 0.12};
	double x[10] = {27.5, 13.4, 53.8, 29.2, 74.5, 87.0, 39.9, 47.7, 8.1, 63.2};
	const int size = 10;

    //File pointer
    FILE *filepointer;
    filepointer = fopen(FILEPATH, "w+");
    //Check for Errors
    if (filepointer == NULL)
    {
        printf("Could not open file");
        return 0;
    }
    // output f values
    int i;
    fprintf(filepointer, "values of list f1...fn: ");
    for(i = 0; i < size; i++){
        fprintf(filepointer,"%.2f, ", f[i]);
    }
    fprintf(filepointer,"\nvalues of list x1...xn: ");
	for(i=0; i < size; i++){
        fprintf(filepointer,"%.2f, ", x[i]);
	}
	double average = weightedAvearange(f, x, size);
	fprintf(filepointer,"\nAverage value: %.2f\n", average);
	printf("Successfully wrote into %s", FILEPATH);
	printf("Closing %s", FILEPATH);
	// Close File
	fclose(filepointer);
	return 0;
}

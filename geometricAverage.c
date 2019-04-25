#include<stdio.h>
#include<math.h>
#define FILEPATH "geometricAverage.txt"

//Solution for Section 6.69(c)
// function to calculate geometric average of a given list of numbers
double geoAverage(double list[], const int size) {
	// using formula Xavg = [x1*x2....xn]^1/n

	double average = pow(list[0], (double)1/size); // varible storing total numbers average

	for (int i = 1; i < size; i++) {
		// increment geometric multiplications (x1 * x2)^1/n where n => size
		average *= pow(list[i], (double)1 / size);
	}
	return average;
}


int main()
{
	const int size = 6;
	double f[6] = { 6.2, 12.3, 5.0, 18.8, 7.1, 12.8};
    // Create File pointer
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
    fprintf(filepointer,"values of list f1...fn: ");
    for(i = 0; i < size; i++){
        fprintf(filepointer,"%.2f, ", f[i]);
    }

    //printf("\n");
	double average = geoAverage(f, size);
	fprintf(filepointer,"\nGeometric average value: %.2f\n", average);
    printf("Successfully wrote into %s", FILEPATH);
	printf("Closing %s", FILEPATH);
	// Close File
	fclose(filepointer);
	return 0;
}

#include<stdio.h>
#define FILEPATH "Fib.txt"
// Solution to Section 6.69 (e)
// fib function returns sum of first (N) sequence of fibonacci numbers
int fib(int n) {

	if (n <= 0 || n <= 2) {
		return 1;
	}
	return fib(n - 1) + fib(n - 2);
}


int main()
{
    // Create File pointer
    FILE *filepointer;
    filepointer = fopen(FILEPATH, "w+");
    //Check for Errors
    if (filepointer == NULL)
    {
        printf("Could not open file");
        return 0;
    }
    fprintf(filepointer, "Fibonacci Series\n");
	//test input for n = 7, n = 17, n = 23
	int n = 7;
	fprintf(filepointer,"fib(%d) ==> %d\n", n, fib(n));

	n = 17;
	fprintf(filepointer,"fib(%d) ==> %d\n", n, fib(n));

	n = 23;
	fprintf(filepointer,"fib(%d) ==> %d\n", n, fib(n));
    printf("Successfully wrote into %s", FILEPATH);
	printf("Closing %s", FILEPATH);
	// Close File
	fclose(filepointer);
	return 0;
}

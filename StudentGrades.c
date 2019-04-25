
#include<stdlib.h>
#include<stdio.h>
#define EOL '\n'
#define MAX_NAMES 10
#define MAX_GRADES 6
#define MAX_LENGTH 12


void averageStudentGrades(void) {

	// setup local variables
	int i, j;
	double averageScore = 0.0;
	// interactively retrieve students Names
    char studentArr[MAX_NAMES][MAX_LENGTH];
    int gradesArr[MAX_NAMES][MAX_GRADES];
    double avgArr[MAX_NAMES];
    int numOfstudents = getStudentName(studentArr);
    getGrades(studentArr, numOfstudents, gradesArr, MAX_GRADES);

    for(i=0; i < numOfstudents; i++){

        for(j=0; j < MAX_GRADES; j++){
            averageScore += gradesArr[i][j];
        }
        averageScore = averageScore / MAX_GRADES;
        avgArr[i] = averageScore;
    }

    printAvgrade(studentArr, numOfstudents, gradesArr, avgArr, MAX_GRADES);

}

void getGrades(char studentArr[MAX_NAMES][MAX_LENGTH], const int numOfstudents,  int gradesArr[MAX_NAMES][MAX_GRADES], const int arrSize) {

    int i, j;
    for(i=0; i < numOfstudents; i++){
        printf("Enter grade for %s: ", studentArr[i]);

        for(j=0; j < arrSize; j++){
            scanf("%d", &gradesArr[i][j]);
        }
    }
}

int getStudentName(char studentArr[MAX_NAMES][MAX_LENGTH]){
    // retrieve students name
    int i, numOfstudents;
    printf("How many names would you like to enter to the list? ");
    scanf("%d", &numOfstudents);

    while(numOfstudents > MAX_NAMES){
        printf("Please choose a smaller entry!!!");
        printf("How many names would you like to enter to the list? ");
        scanf("%d", &numOfstudents);
    }
    for(i=0; i < numOfstudents; i++){
        printf("Enter Name for Student(%d): ", i+1);
        scanf("%s", studentArr[i]);
    }

    return numOfstudents;
}

void printAvgrade(char studentArr[MAX_NAMES][MAX_LENGTH], int numOfstudents,  int gradesArr[MAX_NAMES][MAX_GRADES], double avgArr[],  int arrSize){

    // init variables
    int i, j;
    // output Students Grading
    printf("Name(s)");
    printf("\t\tExams Scores(percent)");
    printf("\t\tAverage Scores\n");

    for(i=0; i < numOfstudents; i++){

        printf("%-*s", MAX_LENGTH, studentArr[i]);
        for(j=0; j < arrSize; j++){
            printf("%5d", gradesArr[i][j]);
        }
        printf("\t%5.2f\n", avgArr[i]);
    }
}

int main(void)
{
//    char studentArr[MAX_NAMES][MAX_LENGTH];
//    int gradesArr[MAX_GRADES];
//    int numOfstudents = getStudentName(studentArr);
//    getGrades(studentArr, numOfstudents, gradesArr, MAX_GRADES);
    //entry point for program :)
    averageStudentGrades();
    return 0;

}

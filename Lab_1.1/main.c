#include <stdio.h>
#include <stdlib.h>

#define Name "Vika"
#define LastName "Gunko"
#define GroupName "RI-21"
#define Faculty "RTF"
#define University "Igor Sikorsky Kyiv Polytechnic Institute"


int main()
{   unsigned int semestr;
    float admissionScore;
    int grade1;
    int grade2;
    int grade3;
    int grade4 = 60;
    int grade5 = 85;
    double averageGrade;
    unsigned int age;


    printf("%s %s follow next steps.\n", Name, LastName);

    printf("Enter semestr number: ");
    scanf("%u", &semestr);

    printf("Enter your admission score:");
    scanf("%f", &admissionScore);

    printf("Enter a grade for subject ¹1:");
    scanf("%d", &grade1);

    printf("Enter a grade for subject ¹2:");
    scanf("%d", &grade2);

    printf("Enter a grade for subject ¹3:");
    scanf("%d", &grade3);

    printf

    printf("Enter your age:");
    scanf("%u", &age);

    averageGrade = (double)(grade1 + grade2 + grade3 + grade4 + grade5)/5;

    system("cls");
    printf("***************\n");
    printf("===============\n");

    printf("%s", University);

    printf("\n%s", Faculty);

    printf("\n%s", GroupName);

    printf("\n---------------------------");

    printf("\nstudent: %s %s", Name, LastName );

    printf("\nage: %u", age);

    printf("\nsemestr: %u", semestr);

    printf("\n---------------------------");

    printf("\nadmission score: %.1f", admissionScore);

    printf("\naverage grade = %.2lf", averageGrade);

    printf("\n");

    return 0;
}

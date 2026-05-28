#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 4 // Έλειπε το #


struct person
{
    int sex;
    int age;
    int education;
    int test1;
    int test2;
    float life;
};

struct person Persons[N]; // ) instead of ] // using persons instead of person


void read_data();


void display_education_level();


void good_life();


void best_worst_well_live (); // extra i


int main(void)
{
    int i, men, women; // men and woman is not initialized

    read_data();

    for (i = 0; i < N; i++)
        if (Persons[i].sex == 0) // missing =
            men++; // missing +
        else
            women++;

    printf("Number of men in the research= %d\n",men); // missing %d
    printf("Number of women in the research= %d\n",women);
    display_education_level();
    good_life();
    best_worst_well_live();
    system("pause");
}



void read_data()
{
    int i;
    for (i = 0; i < N; i++) // missing i<N
    {
        printf("\nFilo: "); //missing closing ""

        do
        {
            scanf("%d", &Persons[i].sex);
            if ((Persons[i].sex != 0) && // missing &
                (Persons[i].sex != 1)) printf("Wrong values... Try again ");
        }       
        while ((Persons[i].sex != 0) && (Persons[i].sex != 1));

        printf("\nHlikia (10-100): ");

        do
        {
            scanf("%d", &Persons[i].age);
            if ((Persons[i].age < 0) || 
            (Persons[i].age > 100)) printf("\n Wrong values... Try again ");
        } 
        while ((Persons[i].age < 0) || (Persons[i].age > 100)); // missing .age
        
        printf("\nEducation (1-6): ");

        do
        {
            scanf("%d", &Persons[i].education);
            if ((Persons[i].education < 1) || 
            (Persons[i].education > 6)) printf("\n Wrong values... Try again "); // misssing [i]
        } 
        while ((Persons[i].education<1) || (Persons[i].education>6));

        printf("\nTest 1 (0-100): ");

        do
        {
            scanf("%d", &Persons[i].test1);
            if ((Persons[i].test1 < 0) || 
            (Persons[i].test1 > 100)) printf("\n Wrong values... Try again ");
        } 
        while ((Persons[i].test1 < 0) || (Persons[i].test1 > 100));

        printf("\nTest 2 (0-100): ");

        do
        {
            scanf("%d", &Persons[i].test2); //missing .test2 //misssing comma
            if ((Persons[i].test2 < 0) || 
            (Persons[i].test2 > 100)) printf("\n Wrong values... Try again ");
        }
        while ((Persons[i].test2 < 0) || (Persons[i].test2 > 100));  
    }
}


void display_education_level()
{
    int i, level;
    int edu[7];

    for (i = 0; i < 7; i++) edu[i] = 0; // extra =
    // else without meaning

    for (i = 0; i < N; i++) // missing i=0
        {
            level = Persons[i].education;
            edu[level]++;
        }


    printf("Education level \t Number of people. \n");
    printf("DHMOTIKO \t %d\n",          edu[1]); // missing ""
    printf("GYMNASIO \t %d\n",          edu[2]);
    printf("LYKEIO \t %d\n",            edu[3]);
    printf("IEK \t %d\n",               edu[4]);
    printf("TEI \t %d\n",               edu[5]);
    printf("PANEPISTIMIO \t %d\n",      edu[6]);
}

void good_life()
{
    int i; // misssing ;
    for (i = 0; i < N; i++) // missing i=0
        Persons[i].life = 0.6*Persons[i].test1+0.4*Persons[i].test2;        
}







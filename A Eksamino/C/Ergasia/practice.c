#include <stdio.h>

int main(void)
{
    int number;

    printf("Δωσε εναν ακεραιο αριθμο: ");
    scanf("%d", &number);

    if (number % 2 == 0)
    {
        printf("Ο αριθμος %d ειναι ζυγος.\n", number);
    }
    else
    {
        printf("Ο αριθμος %d ειναι μονος.\n", number);
    }

    return 0;
}

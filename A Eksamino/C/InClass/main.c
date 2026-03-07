#include <stdio.h>

#define N 4


int main(void) 
{
    int x,y,z,k;
    printf("Dwse x: ");
    scanf("%d", &x);
    printf("Dwse y: ");
    scanf("%d", &y);
    printf("Dwse z: ");
    scanf("%d", &z);
    k = sinolo(x,y,z);
    printf("Sinolo: %d\n",k);
    system("PAUSE");
    return 0;
}

int sinolo (int x, int y, int z)
{
    int w = x + y + z;
    return w;
}
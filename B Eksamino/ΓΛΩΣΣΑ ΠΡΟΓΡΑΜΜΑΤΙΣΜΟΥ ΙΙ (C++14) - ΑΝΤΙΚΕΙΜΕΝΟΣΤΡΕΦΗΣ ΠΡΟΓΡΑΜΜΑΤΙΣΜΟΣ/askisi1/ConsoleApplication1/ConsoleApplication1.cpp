#include <iostream>

int main(int argc, char* argv[])
{
    for (int x=0;x<100000;x++)
    {
        for (int y=0;y<100000;y++)
        {
            if (2*x+3*y==12500 && x+2*y==7500)
            {
                std::cout << x << '\n';
                std::cout << y << '\n';
            }
        }
    }
    return 0;
}



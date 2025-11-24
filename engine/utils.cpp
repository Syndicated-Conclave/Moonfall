#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int RNG()
{
    int x = time(0);
    srand(x);    
    return 1;
}
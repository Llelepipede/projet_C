#include "header.h"

void  test_color()
{
    int i=1;

    while(i<81)
    {
        color(0,i%15);
        printf("%d",i%15);
        i++;
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int i;

    for(i=0;i<argc-1;i++)
    {
        printf("%10.5s\n", argv[1]);

    }
    return 0;
}

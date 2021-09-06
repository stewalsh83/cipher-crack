#include <stdio.h>
#include <stdlib.h>

// int main(int argc, char *argv[])
// {
//     char line[255];
// 	FILE *fpointer = fopen(argv[1], "r");

//     fgets(line, 255, fpointer); // reads first line
//     printf("%s", line);

//     printf("\n");
//     return 0;
// }

int main(int argc, char *argv[])
{
    char line; // line from text file variable 
    FILE *fpointer; // pointer for file

    // read file from command line
    fpointer = fopen(argv[1], "r");

    // Incorrect file name or no file in directory or no command line argument = error warning
    if (fpointer == NULL)
    {
       perror("Error no file found.\n");
       exit(EXIT_FAILURE);
    }

    // returns character in file until end of file or error.
    while((line = fgetc(fpointer)) != EOF)
        printf("%c", line);

    fclose(fpointer);
    return 0;
}
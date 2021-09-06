#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// void test(char name[])
// {
//     printf("Hello %c\n", name);
// }

int main(int argc, char *argv[])
{
    char file_name1[100];
    char file_name2[100];
    char line; // line from text file variable 
    FILE *fp_read, *fp_decrypt, *fp_key; // pointer for file

    // read file from command line
    fp_read = fopen(argv[1], "r");

    // Incorrect file name or no file in directory or no command line argument = error warning
    if (fp_read == NULL)
    {
       perror(": Error no file found\n");
       exit(EXIT_FAILURE);
    }

    strcpy(file_name1, argv[1]);
    strcpy(file_name2, argv[1]);
	strcat(file_name1, "-decrypted.txt");
    strcat(file_name2, "-key.txt");

    fp_decrypt = fopen(file_name1, "w");
    fp_key = fopen(file_name2, "w");

    // returns character in file until end of file or error.
   while((line = fgetc(fp_read)) != EOF)
   {
        // printf("%c", line);
        fprintf(fp_decrypt, "%c", line);
        fprintf(fp_key, "%c", line);
        // fputc(line, fp_decrypt);
        // fputc(line, fp_key);
   }

    fclose(fp_read);
    fclose(fp_decrypt);
    fclose(fp_key);
    return 0;
}

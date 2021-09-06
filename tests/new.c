#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// void mod_key(char **s){
//   char *new_name = "ABC";
//   *s = new_name;
// }

// int main(){
//   char *name = "Hello World";
//   mod_key(&name);
//   printf("%s\n", name);
//   return 0;
// }


int main(int argc, char *argv[])
{
    //char *name = "Hello World";
    int i, key;
    char file_name1[100];
    char file_name2[100];
    char line, letter; // line variable for text file
    // file pointer to read input file, then for decryption and key files.
    FILE *fp_read, *fp_decrypt, *fp_key; 

    // read file from command line
    fp_read = fopen(argv[1], "r");

    // Incorrect file name or no file in directory or no command line argument = error warning
    if (fp_read == NULL)
    {
       perror("Error no file found.\n");
       exit(EXIT_FAILURE);
    }

    // file naming convention

    strcpy(file_name1, argv[1]);
    strcpy(file_name2, argv[1]);
	strcat(file_name1, "-decrypted.txt");
    strcat(file_name2, "-key.txt");

    // file pointer to write input to output files.
    fp_decrypt = fopen(file_name1, "w");
    fp_key = fopen(file_name2, "w");

    printf("\nEnter Key : ");
    scanf("%d", &key);

    // returns character in file until end of file or error.
    while ((line = fgetc(fp_read)) != EOF)
    {
        // caesar cipher
        letter = line;
        if (letter >= 'a' && letter <= 'z')
        {
            letter = letter - key;
            if (letter < 'a')
            {
                letter = letter + 'z' - 'a' + 1;
            }
            line = letter;
        }
        else if (letter >= 'A' && letter <= 'Z')
        {
            letter = letter - key;
            if (letter < 'A')
            {
                letter = letter + 'Z' - 'A' + 1;
            }
            line = letter;
        }

        fprintf(fp_decrypt, "%c", line);
    }
    
    while ((line = fgetc(fp_read)) != EOF)
    {
        fprintf(fp_key, "%c", line);
    }

    //mod_key(&name);
    //printf("%c\n", name);

    fclose(fp_read);
    fclose(fp_decrypt);
    fclose(fp_key);
    return 0;
}


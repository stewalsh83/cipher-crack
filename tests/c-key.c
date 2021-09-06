#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int i, key;
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


    strcpy(file_name2, argv[1]);

    strcat(file_name2, "-key.txt");

    // file pointer to write input to output files.

    fp_key = fopen(file_name2, "w");

    printf("\nEnter Key : ");
    scanf("%d", &key);

    // returns character in file until end of file or error.
    #define MAX 26
    char shift[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char alpha[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    //char shift[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    //char alpha[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char ch;
    for(i = 0; i < MAX; i++)
    {
        if(shift[i] != key)
        {
            ch = shift[i] + key;
            
            if(ch >= 65 && ch <= 90)
            {
                fprintf(fp_key, "%c = %c\n", alpha[i], ch);
            }
        }
    }

    for(i = 0; i < MAX; i++)
    {
        if(shift[i] != key)
        {
            ch = shift[i] + key;
            //fprintf(fp_key, "%c = %c\n", alpha[i], ch);
            
            if(ch > 90)
            {
                ch = shift[0]++;
                //ch = shift[key++];
                //ch = shift[MAX-1];
                fprintf(fp_key, "%c = %c\n", alpha[i], ch);
            }
        }
    }

    // for(i = 0; i < strlen(shift); i++)
    // {
    //     if(ch >= strlen(shift))
    //     {
    //         ch = shift[key++];
    //         //ch = shift[MAX-1];
    //         fprintf(fp_key, "%c = %c\n", alpha[i], ch);
    //     }
    // }

    // for(i = 0; i < 26; i++)
    // {
    //     if(shift[i] != key)
    //         shift[i] = shift[i] + key;
    //         //printf("%c\n", shift[i]);
    //         fprintf(fp_key, "%c = %c\n", ch[i], shift[i]);
    // }    


    fclose(fp_read);
    fclose(fp_key);
    return 0;
}


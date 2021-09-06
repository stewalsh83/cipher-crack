#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char *argv[])
{
    // starting program time
    clock_t begin1 = clock();
    int i, key;
    char file_name1[100];
    char file_name2[100];
    char line, letter; // line variable for text file

    // file pointer to read input, decryption and key files
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

    // file pointer to write input to output files
    fp_decrypt = fopen(file_name1, "w");
    fp_key = fopen(file_name2, "w");

    // to take int value as the key
    printf("\nEnter Number (Key): ");
    scanf("%d", &key);

    // starting program time after key is entered
    clock_t begin2 = clock();

    // Caesar Cipher to produce decrypted file as output
    // returns each character in file until end of file is reached
    while ((line = fgetc(fp_read)) != EOF)
    { // letter is each character from the encrypted input file
        letter = line;
        // if letter is lower case and in the bounds of a to z
        if (letter >= 'a' && letter <= 'z')
        { // the keys value is use to shift the position of letter
            letter = letter - key;

            if (letter < 'a')
            { // aligns letters from z - key value
                letter = letter + 'z' - 'a' + 1;
            }
            // lower case letters are now decrypted and returned to line
            line = letter;

            // The same as above but for upper case letters
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
        // it will print to a prenamed decrypted txt file
        fprintf(fp_decrypt, "%c", line);
    }

// setting MAX at 26 (lenght of alphbet)
#define MAX 26

    // alphabet array for both shift and letters
    char shift[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char letters[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // variable to compare letters with cipher letters
    char cipher_letter;

    // To produce keyfile as output
    // for loop to run against MAX
    for (i = 0; i < MAX; i++)
    { // if the shift array is not equal to the key input
        if (shift[i] != key)
        { // add key value to shift position
            cipher_letter = shift[i] + key;
            // if cipher_letter is within the bounds of ascii characters A to Z
            if (cipher_letter >= 'A' && cipher_letter <= 'Z')
            { // it will print to a prenamed txt file, to the point of Z then stop
                fprintf(fp_key, "%c = %c\n", letters[i], cipher_letter);
            } // then if cipher_letter goes beyond Z
            else if (cipher_letter > 'Z')
            { // it resets to A and iterates until the letters array is complete
                cipher_letter = shift[0]++;
                // it will print to a prenamed txt file the key comparision between fixed letters and shifted letters
                fprintf(fp_key, "%c = %c\n", letters[i], cipher_letter);
            }
        }
    }

    // closing all files
    fclose(fp_read);
    fclose(fp_decrypt);
    fclose(fp_key);

    // For timing the execution speed of the program
    clock_t end = clock();
    double time_1 = (double)(end - begin1) / CLOCKS_PER_SEC;
    double time_2 = (double)(end - begin2) / CLOCKS_PER_SEC;
    printf("Total time: %.10f Seconds\n", time_1);
    printf("Time after user input: %.10f Seconds\n", time_2);
    return 0;
}

/**
 * @file writeData.c
 * @author 
 * @brief A program that creates a binary file called traffic.dat. The program takes a number of lanes as a command line argument, asks the user for the lane type and duration for each lane and writes the data to the file.
 * @details This program takes a number as a command line argument, asks the user for the lane type and duration for each lane, and writes the data to a binary file called traffic.dat.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * A struct to represent a traffic lane.
 * @struct Traffic
 * @var duration the active duration of the lane in seconds.
 * @var lane the type of the lane, either "main" or "alt".
 */
typedef struct {
    int duration; // active duration of the lane in seconds
    char lane[5]; // main or alt
} Traffic;

/**
 * @function main
 * @brief The main function of the program.
 * @param argc The number of command line arguments.
 * @param argv The command line arguments.
 * @return The exit status of the program.
 */
int main(int argc, char **argv)
{
    // Check if the user entered a command line argument
    if (argc == 1) {
        printf("Enter a number as a command line argument.");
        return 1;
    }

    int i;

    // Check if the command line argument is a number
    for (i = 0; i < strlen(argv[1]) && isdigit(argv[1][i]); i++) {}

    if (i == strlen(argv[1]) && i > 0)
    {
        // Convert the command line argument to an integer
        int size = atoi(argv[1]);
        printf("%d\n", size);
        Traffic t[size];

        // Ask the user for the lane type and duration for each lane
        for (i = 0; i < size; i++)
        {
            printf("Enter lane %d (main/alt): ", i + 1);
            scanf(" %s", t[i].lane);
            printf("Enter duration of the lane %d in seconds: ", i + 1);
            scanf("%d", &t[i].duration);
        }

        // Open a binary file called traffic.dat and write the data to it
        FILE *fp = fopen("traffic.dat", "wb");
        fwrite(t, sizeof(Traffic), size, fp);
        fclose(fp);
    } 
    else
    {
        printf("Please enter a number as a command line argument.\n");
    }

    return 0;
}



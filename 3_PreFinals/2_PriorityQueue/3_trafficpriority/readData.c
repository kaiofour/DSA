#include <stdio.h>

// Define a structure to represent a traffic lane
typedef struct {
    int duration; // active duration of the lane in seconds
    char lane[5]; // type of lane, either "main" or "alt"
} Traffic;

int main(int argc, char **argv)
{
    // Open the binary file "traffic.dat" in read-binary mode
    FILE *fp = fopen("traffic.dat", "rb");
    
    // Move the file pointer to the end of the file to determine its size
    fseek(fp, 0, SEEK_END);
    
    // Get the size of the file in bytes
    long fileSize = ftell(fp);
    
    // Reset the file pointer back to the start of the file
    fseek(fp, 0, SEEK_SET);

    // Calculate the number of Traffic records in the file
    int numRecords = fileSize / sizeof(Traffic);
    
    // Create an array to store the Traffic records
    Traffic t[numRecords];

    // Read the traffic records from the file into the array
    fread(t, sizeof(Traffic), numRecords, fp);

    // Loop through each Traffic record and print its lane type and duration
    for (int i = 0; i < numRecords; i++)
    {
        printf("%s %d\n", t[i].lane, t[i].duration);
    }
    
    // Close the file
    fclose(fp);

    return 0;
}

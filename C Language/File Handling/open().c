#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE *fptr;

    char data[] = "Jay Ganesh";

    fptr = fopen("demo.txt", "w");

    if (fptr == NULL)
    {
        printf("Error opening file\n");
        exit(EXIT_FAILURE);
    }

    fprintf(fptr, "%s", data);

    fclose(fptr);

    printf("Data written to demo.txt\n");

    return 0;
}

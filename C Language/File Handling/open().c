#include<stdio.h>
#include<stdlib.h>

# define ERR_FILE_NOT_EXIST -1
# define SUCCESS 0

int main()
{
    FILE *fptr;

    char data[] = "Jay Ganesh";

    fptr = fopen("demo.txt", "w");

    if (fptr == NULL)
    {
        printf("Error opening file\n");
        return ERR_FILE_NOT_EXIST;
    }

    fprintf(fptr, "%s", data);

    fclose(fptr);

    printf("Data written to demo.txt file\n");
    
    return SUCCESS;
}

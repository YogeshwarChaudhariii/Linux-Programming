#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include "FileHandlingFunction.h"

void FileHandling()
{

    FILE *fp;                               //File pointer
    FILE *SourceFile;                       //Source File
    FILE *DestinationFile;                  //Desination file

    int choice = 0;

    char FileName[20] = {'\0'};
    char SourFileName[100] = {'\0'};            //Source File
    char DesFileName[100] = {'\0'};             //Desination file

    char ch;

    printf("1. Create a new file...\n");
    printf("2. Delete the file...\n");
    printf("3. Write a content in file\n");
    printf("4. Check file or Directory exist or not\n");
    printf("5. Copy data from Source file to other file\n");
    printf("Enter your choice: \n");
    scanf("%d",&choice);

    switch (choice)
        {
        case 1:
            printf("Enter file name: \n");
            scanf("%s",&FileName);

            if (access(FileName, F_OK) == 0)
            {
                printf("File already exist\n");
            }
            else if (creat(FileName, 0777))
            {
                printf("File successfully created\n");
            }   
            break;

        case 2:
            printf("Enter file name: \n");
            scanf("%s",&FileName);

            if (remove(FileName) == 0)
            {
                printf("File deleted successfully\n");
            }
            else
            {
                printf("File not exist\n");
            }
            break;

        case 3:
            printf("Enter file name: \n");
            scanf("%s",&FileName);

            if(access(FileName, F_OK) == 0)
            {
                fp = fopen(FileName, "w");
                fprintf(fp, "Yogeshwar Chaudhari\n");
                fprintf(fp, "Prakash Chaudhari\n");
                printf("Content written succefuly\n");
            }
            else
            {
                printf("File not exist\n");
            }
            break;

        case 4:
            printf("Enter a file or Directory name: \n");
            scanf("%s",&FileName);

            if (access(FileName, F_OK) == 0)
            {
                printf("%s file exist",FileName);
            }
            else
            {
                printf("File Not exist");
            }
            break;

        case 5:
            printf("Enter Source file name: \n");
            scanf("%s",&SourFileName);

            printf("Enter Destination file name: \n");
            scanf("%s",&DesFileName);

            SourceFile = fopen(SourFileName, "r");
            DestinationFile = fopen(DesFileName, "w");

            if ((SourceFile == NULL) || (DestinationFile == NULL))
            {
                printf("File not exist");
                exit(EXIT_FAILURE);                 //if file not exit then exit 
            }
            else
            {
                while ((ch = fgetc(SourceFile)) != EOF)         //EOF = End of file
                {
                    fputc(ch, DestinationFile);
                }
                printf("Data copy sucessfully\n");
            }
            break;

                default:
                break;
            }
}

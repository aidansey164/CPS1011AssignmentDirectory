#include <string.h>//including standard libraries and datatable header file
#include <stdio.h>
#include <stdlib.h>
#include "Datatable.h"
#include <ctype.h>



// function to initialise the datatable structure with initial memory allocation
struct Datatable* initDT(struct Datatable *DT)

{
    int i, rows, length, z;
    int y=0;
    char userinput[MAXSTRING];
    DT->rowcounter=0;
    struct Datatable *ptr;
    ptr = (struct Datatable*)malloc((sizeof(struct Datatable))); //allocates the maximum needed memory
    if (ptr == 0){
        printf("Allocation of memory unsuccessful, Try again");
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("Allocation of memory successful\n");
        for(i=1; i<7; i++ ) { // get column name tags
            printf("Please enter name label for Column %d\n", i);
            scanf("%s", userinput);
            length = MAXSTRING - strlen(userinput);
            strcpy(DT->colnames[i-1], userinput);
            DT->colnames[i-1][length] = '\0';
             while (getchar() != '\n');//end of loop
            }
            printf("Enter No of Rows\n");
            scanf("%d", &rows);// enters maximum number rows

            for(int j=0; j<rows; j++)//populates until max number of rows is reached
            {

                printf("Columns 1-3 are float integers, 4-6 are Strings\n");
                printf("Enter data for Column 1 and Row %d\n", j + 1); //saves data into floatcols
                scanf("%lf", &DT->floatcols[j][y]);

                printf("Enter data for Column 2 and Row %d\n", j + 1);
                scanf("%lf", &DT->floatcols[j][y+1]);

                printf("Enter data for Column 3 and Row %d\n", j + 1);
                scanf("%lf", &DT->floatcols[j][y+2]);

                printf("Enter data for Column 4 and Row %d\n", j + 1); //saves data into cols containing strings
                scanf("%s", DT->scols[j][y]);

                printf("Enter data  for Column 5 and Row %d\n", j + 1);
                scanf("%s", DT->scols[j][y+1]);

                printf("Enter rdata for Column 6 and Row %d\n", j + 1);
                scanf("%s", DT->scols[j][y+2]);

                DT->rowcounter++; // increment rowcounter
            }

        }

    return (&*ptr);
}



//deallocates the structure
void deinitDT(struct Datatable *DT) {

    free(DT);
    DT = NULL;

}

void showDT(struct Datatable *DT)
{
    int j = 0;
    int i = 0;
    char c1[15], c2[15], c3[15], c4[15], c5[15], c6[15];


    strcpy(c1, DT->colnames[j]);
    strcpy(c2, DT->colnames[j+1]);
    strcpy(c3, DT->colnames[j+2]);
    strcpy(c4, DT->colnames[j+3]);
    strcpy(c5, DT->colnames[j+4]);
    strcpy(c6, DT->colnames[j+5]);



    printf("%8s   ,%8s   ,%8s   ,%8s   ,%8s   ,%8s   \n",
           c1, c2, c3, c4, c5, c6);

    //print first 15 rows
    while (i < 15)
    {
        printf("%8f   ,%8f   ,%8f   ,%8s   ,%8s   ,%8s   \n",
               DT->floatcols[i][j],
               DT->floatcols[i][j + 1], DT->floatcols[i][j + 2], DT->scols[i][j],
               DT->scols[i][j + 1], DT->scols[i][j + 2]);
        i++;
    }

    printf( "%8f   ,%8f   ,%8f   ,%8s   ,%8s   ,%8s   \n",
            DT->floatcols[DT->rowcounter][j],DT->floatcols[DT->rowcounter][j + 1],
            DT->floatcols[DT->rowcounter][j + 2], DT->scols[DT->rowcounter][j],
            DT->scols[DT->rowcounter][j + 1], DT->scols[DT->rowcounter][j + 2]);

}



struct Datatable projectDT (struct Datatable *DT, struct Datatable *DTcopy, int x , int y, int m, int n)

{
    int i = 0, j = 0;
    while(m<=n)
    {
        strcpy(DTcopy->colnames[i],DT->colnames[m-1]);
        while(x<=y)
        {
            // copying first 3 columns from original to new struct
            DTcopy->floatcols[j][i]=DT->floatcols[x-1][m-1];
            DTcopy->floatcols[j][i+1]=DT->floatcols[x-1][m];
            DTcopy->floatcols[j][i+2]=DT->floatcols[x-1][m+1];

            // copying columns 3-5 from original struct to new struct
            strcpy(DTcopy->scols[j][i],DT->scols[x-1][m-1]);
            strcpy(DTcopy->scols[j][i+1],DT->scols[x-1][m]);
            strcpy(DTcopy->scols[j][i+2],DT->scols[x-1][m+1]);
            x++;
            j++;
            DTcopy->rowcounter++;
        }
        m++;
        i++;
    }
    return *DTcopy; // return new data struct datatable with the constraints
}


void mutateDT(struct Datatable *DT, int num) {
    int choice;
    int j = 0;

    do {

        printf("-------Values Manipulation-------\n");
        printf("1. Multiply Float Numbers by number inputted in parameter \n");
        printf("2. Divide Float Numbers by number inputted in parameter\n");
        printf("-------String Manipulation-------\n");
        printf("3. Convert text to Uppercase\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                for (int i = 0; i < DT->rowcounter; i++)
                {
                    DT->floatcols[i][j] = ((DT->floatcols[i][j]) * num);
                    DT->floatcols[i][j + 1] = ((DT->floatcols[i][j + 1]) * num);
                    DT->floatcols[i][j + 2] = ((DT->floatcols[i][j + 2]) * num);
                }
                break;
            case 2:
                for (int c = 0; c < DT->rowcounter; c++)
                {
                    DT->floatcols[c][j] = ((DT->floatcols[c][j]) / num);
                    DT->floatcols[c][j + 1] = ((DT->floatcols[c][j + 1]) / num);
                    DT->floatcols[c][j + 2] = ((DT->floatcols[c][j + 2]) / num);
                }
                break;
            case 3:
                for (int b = 0; b < DT->rowcounter; b++)
                {
                    for(int w=0;DT->scols[b][j][w]!='\0';w++)
                    {
                        if(DT->scols[b][j][w]>='a' && DT->scols[b][j][w]<='z')
                        {
                            DT->scols[b][j][w] -= 32;
                        }
                    }
                    for(int u=0;DT->scols[b][j+1][u]!='\0';u++)
                    {
                        if(DT->scols[b][j+1][u]>='a' && DT->scols[b][j+1][u]<='z')
                        {
                            DT->scols[b][j+1][u] -= 32;
                        }
                    }
                    for(int p=0;DT->scols[b][j+2][p]!='\0';p++)
                    {
                        if(DT->scols[b][j+2][p]>='a' && DT->scols[b][j+2][p]<='z')
                        {
                            DT->scols[b][j+2][p] -= 32;
                        }
                    }
                }
                break;
            case 4:
                printf("EXITING MENU");
                break;
            default:
                printf("Wrong input, Try again\n");
                break;

        }


    } while(choice!=4);
}


void loadDT(char *fileinput, struct Datatable *DT ) {
//    FILE *f;
//    fclose(&fileinput);
    printf("File closed");
}


void exportDT(char *fileinput, struct Datatable *DT) {
    int j = 0;
    int i = 0;
    FILE *fp = fopen(fileinput, "a+");
    if (!fp) {
        printf("Error, file not opened\n");
    }

    //prints column names to file
    fprintf(fp,"%8s    ,%8s   ,%8s   ,%8s   ,%8s  ,%8s    \n", DT->colnames[j], DT->colnames[j + 1],
            DT->colnames[j+2], DT->colnames[j+3],
            DT->colnames[j+4],DT->colnames[j+5]);

    while (i < DT->rowcounter)
    {
        fprintf(fp,"%8f    ,%8f   ,%8f   ,%8s   ,%8s   ,%8s   \n", //write data table to the csv file
                DT->floatcols[i][j],
                DT->floatcols[i][j + 1], DT->floatcols[i][j + 2], DT->scols[i][j],
                DT->scols[i][j + 1], DT->scols[i][j + 2]);
        i++;
    }
    fclose(fp);//
}

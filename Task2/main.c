#include <stdlib.h>
#include <stdio.h>
#include "Datatable.h"


int x,y,m,n;
int choice;
char filename;



int main(void)
{



    //test driver for functions
    do
    {

        printf("1. Initialize Datatable \n");
        printf("2. DeInitialize Datatable\n");
        printf("3. Load File\n");
        printf("4. Export to File \n");
        printf("5. Show Datatable\n");
        printf("6. Project Datatable\n");
        printf("7. Mutate Datatable\n");
        printf("8. Exit Menu\n");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:initDT(&s);
                break;
            case 2:deinitDT(&s);
                break;
            case 3:
                printf("Specify name and path of file if needed or creaate new file\n");
                scanf("%s", &filename);
                loadDT(&filename,&s);
                break;
            case 4:
                printf("Specify name and path of file if needed or create new file\n");
                scanf("%s", &filename);
                exportDT(&filename, &s);
                break;
            case 5:showDT(&s);
                break;
            case 6: printf("Please enter start row\n");
                scanf("%d\n",&x);
                printf("Please enter end row\n");
                scanf("%d\n",&y);
                printf("Please enter start column\n");
                scanf("%d\n",&m);
                printf("Please enter end column\n");
                scanf("%d\n",&n);
                struct Datatable t = projectDT(&s,&t,x,y,m,n);
                showDT(&t);
                break;
            case 7: mutateDT(&s, 10);
                break;
            case 8: printf("Exiting menu\n");
                exit(0);

            default: printf("Wrong Choice. Enter again\n");
                break;
        }

    } while (choice != 8);


    return 0;
}
#include <stdio.h>
#include <stdlib.h>

#include "Task1Questions.h"

//Question B implementation
int main()
{

    int c[] = {1, 1, 1, 25};
    int freqarr[] = {4, 5, 5, 1};
    int choice;
    int ar[] = {};
    int ar2[] = {1, 2, 3, 4, 5};
    int a[] = {5, 4, 3, 2, 1};
    int b[] = {1, 1, 1, 1, 1};
    int size = 5;
    while(1)
    {
        printf("\n1. init array() \n");
        printf("2. display() \n");
        printf("3. reverse() \n");
        printf("4. frequency() \n");
        printf("5. display_frequency() \n");
        printf("6. Exit \n");
        printf("Enter your choice :  ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                init_array(ar,  size);
                break;

            case 2:
                 display( ar2,  size);
                break;

            case 3:
                 reverse(a, b, size);
                break;

            case 4:
                frequency(c, 4);
                break;

            case 5:
                 displayfrequency(freqarr);
                break;

            case 6:
                printf("\nEXITING MENU SUCCESSFUL\n");
                exit(0);    // terminate CLMdefault
            default: printf("Invalid input, Try again");
        }
    }
}
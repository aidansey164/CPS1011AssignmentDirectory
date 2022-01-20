#include <stdio.h>


#include "Task1Questions.h"

void init_array(int ar[], int size)
{
    int i;
    printf("Please enter %d values: \n", size);
    for (i = 0; i < size; i++) {
        scanf("%d", &ar[i]);

    }
    printf("Elements in array are:");
    for (i = 0; i < size; i++) {
        printf(" %d , ", ar[i]);
    }

    printf("Size of array is %d\n", size); //printing size of array

}


void display(int ar[], int size){
    int choice;
    FILE *fp2;
    printf("Press 1 to print to screen or 2 to print to a txt file\n");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            for (int i = 0; i < size; i++)
                printf("offset: '0%d' \n"
                       "value: '%d' \n\n", i, ar[i]);
            break;
        case 2:


            fp2 = fopen("display.txt","w");

            //write to file
            fwrite(ar,10,1,fp2);
            printf("\n");
//            fclose(fp2);
            break;
    }
}


void reverse(int a[], int b[], int size){
    int i;
    int j;
    int k;
    printf("\n\nCopying elements from array a to b, in the reverse order\n"); //important that a and b have the same size, regardless if array b has elements in or not,

    printf("Array B already has elements inside it");
    for(k = 0; k<size; k++){
        printf("%3d", b[k]);
    }
    // elements in it will be overturned by the copied reverse order of array a
    for(i = size - 1, j = 0; i >= 0; i--, j++)
        b[j] = a[i];

    printf("\nOriginal \t-->  Copy\n", size, size);
    for(i = 0; i < size; i++)
        printf("%4d\t\t-->%6d\n", a[i], b[i]);
}

void frequency(int const a [], int size){

    int i;
    int j;
    //declaring struct that will store frequencies and equivalent elements
    struct freqarr fr;
    for (i = 0; i < size; i++) {
        fr.arr[i] = a[i];  //copying array in parameter to array inside struct
    }

    for (i = 0; i < size; i++) {
        printf( " %d ", fr.arr[i]); //printing array inside struct to assure copying of array was done correctly
    }
    for (i = 0; i < size; i++) {
        int count = 1;  // Counter will be used and incremented accordingly
        for (j = i + 1; j < size; j++) {
            if (fr.arr[i] == fr.arr[j])    // checking for elements that are duplicates
            {
                count++;
                fr.freq[j] = 0;   // not counting frequency twice for same elements
            }
        }
        if (fr.freq[i] != 0)        // If frequency of current element is not counted
        {
            fr.freq[i] = count; // filling freq array with count values
        }
    }


    printf("\n The Frequency of the elements in this Array is : \n");
    for (i = 0; i < size; i++) {
        if (fr.freq[i] != 0) {
            printf("{%d , %d} ", fr.arr[i], fr.freq[i]); //printing frequencies pair
        }

    }

    //merging into one array
    int merge2[10];
    int k;
    printf("\nMerging two arrays in structure into single array\n");
    for (i = 0,  k = 0; i < size; i++, k += 2)
        if (fr.freq[i] != 0) {
            merge2[k] = fr.arr[i]; //copying contents in fr.arr into merge 2
        }

    for (i = 0, k = 1; i < size; i++, k += 2)
        if (fr.freq[i] != 0) {
            merge2[k] = fr.freq[i]; //copying contents in fr.freq into merge 2
        }


    int merge3[6];
    int g = 0;
    for (i = 0; i < 8; i++) {
        if (merge2[i] != 0) {
            merge3[g++] = merge2[i]; //removing all zero values to end up only with the number and frequencies
        }
    }
    for (i = 0; i < g; i++) {
        printf(" %d", merge3[i]);

    }
}

void displayfrequency(int a[]) {

    int choice;
    int i;
    int k;
    FILE *fp;
    printf("Press 1 to print to screen or 2 to print to a txt file\n");
    scanf("%d", &choice);
    switch (choice) {
        case 1:


                   for (i = 0 ; i <3; i++) {

                       printf(
                               "\n{ {Number: %d } \n {Frequency: %d} }\n", a[i], a[i + 1]);

                   }
                    break;
                    case 2:


                        fp = fopen("displayfrequency.txt", "w");

                    //write to file
                    fwrite(a, sizeof(a), 1, fp);
                    printf("\n");
                    break;
                }
            }


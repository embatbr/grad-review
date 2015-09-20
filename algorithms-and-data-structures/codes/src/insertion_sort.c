#include <stdio.h>

#define LENGTH 6


void print_sequence(int sequence[], int length)
{
    int i;
    for(i = 0; i < length; i++)
    {
        printf("%d%s", sequence[i], i < (length - 1) ? ", " : "\n");
    }
}


void insertion_sort()
{
    int sequence[LENGTH] = {5, 2, 4, 6, 1, 3};
    print_sequence(sequence, LENGTH);

    int j;
    for(j = 1; j < LENGTH; j++)
    {
        int key = sequence[j];
        int i = j - 1;
        while((i >= 0) && (sequence[i] > key))
        {
            sequence[i + 1] = sequence[i];
            i--;
        }

        sequence[i + 1] = key;
    }

    print_sequence(sequence, LENGTH);
}


int main()
{
    insertion_sort();
}
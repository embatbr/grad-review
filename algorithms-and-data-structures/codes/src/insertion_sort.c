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


void insertion_sort_asc()
{
    int sequence[LENGTH] = {31, 41, 59, 26, 41, 58};
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

void insertion_sort_desc()
{
    int sequence[LENGTH] = {31, 41, 59, 26, 41, 58};
    print_sequence(sequence, LENGTH);

    int j;
    for(j = 1; j < LENGTH; j++)
    {
        int key = sequence[j];
        int i = j - 1;
        while((i >= 0) && (sequence[i] < key))
        {
            sequence[i + 1] = sequence[i];
            i--;
        }

        sequence[i + 1] = key;
    }

    print_sequence(sequence, LENGTH);
}

void linear_search(int key)
{
    int sequence[LENGTH] = {31, 41, 59, 26, 41, 58};
    printf("searching for key %d in ", key);
    print_sequence(sequence, LENGTH);

    int i, pos;
    for(i = 0, pos = -1; i < LENGTH && pos < 0; i++)
    {
        if(sequence[i] == key)
        {
            pos = i;
        }
    }

    if(pos < 0)
    {
        printf("key %d was not found\n", key);
    }
    else
    {
        printf("key %d was found in position %d\n", key, pos);
    }
}


int main()
{
    printf("asc order:\n");
    insertion_sort_asc();
    printf("desc order:\n");
    insertion_sort_desc();
    linear_search(59);
    linear_search(10);
}
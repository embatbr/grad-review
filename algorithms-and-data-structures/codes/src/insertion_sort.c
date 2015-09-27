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


int higher(int a, int b)
{
    return a > b;
}

int lower(int a, int b)
{
    return a < b;
}


void insertion_sort(int *sequence, int (*test)(int, int))
{
    print_sequence(sequence, LENGTH);

    int j;
    for(j = 1; j < LENGTH; j++)
    {
        int key = sequence[j];
        int i = j - 1;
        while((i >= 0) && test(sequence[i], key))
        {
            sequence[i + 1] = sequence[i];
            i--;
        }

        sequence[i + 1] = key;
    }

    print_sequence(sequence, LENGTH);
}

void insertion_sort_asc()
{
    int sequence[LENGTH] = {31, 41, 59, 26, 41, 58};
    insertion_sort(sequence, &higher);
}

void insertion_sort_desc()
{
    int sequence[LENGTH] = {31, 41, 59, 26, 41, 58};
    insertion_sort(sequence, &lower);
}


void selection_sort(int *sequence, int (*test)(int, int))
{
    print_sequence(sequence, LENGTH);

    int j, jTest;
    for(j = 0; j < LENGTH; j++)
    {
        jTest = j;
        int i;
        for(i = j + 1; i < LENGTH; i++)
        {
            if(test(sequence[i], sequence[jTest]))
            {
                jTest = i;
            }
        }

        if(sequence[jTest] != sequence[j])
        {
            int temp = sequence[j];
            sequence[j] = sequence[jTest];
            sequence[jTest] = sequence[j];
        }
    }

    print_sequence(sequence, LENGTH);
}

void selection_sort_asc()
{
    int sequence[LENGTH] = {31, 41, 59, 26, 41, 58};
    insertion_sort(sequence, &higher);
}

void selection_sort_desc()
{
    int sequence[LENGTH] = {31, 41, 59, 26, 41, 58};
    insertion_sort(sequence, &lower);
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
    printf("INSERTION SORT\n");
    printf("ASC order:\n");
    insertion_sort_asc();
    printf("DESC order:\n");
    insertion_sort_desc();
    printf("\n");

    printf("SELECTION SORT\n");
    printf("ASC order:\n");
    selection_sort_asc();
    printf("DESC order:\n");
    selection_sort_desc();
    printf("\n");

    linear_search(59);
    linear_search(10);
}
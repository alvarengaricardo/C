#include <stdio.h>

void comb_sort(int *array, int n)
{
    int gap = n;
    int shrink = 1.3;
    int swapped = 1;

    while (gap > 1 || swapped)
    {
        if (gap > 1)
        {
            gap *= shrink;
            gap /= 2;
        }

        swapped = 0;
        for (int i = 0; i + gap < n; i++)
        {
            if (array[i] > array[i + gap])
            {
                int temp = array[i];
                array[i] = array[i + gap];
                array[i + gap] = temp;
                swapped = 1;
            }
        }
    }
}

int main(){
    printf("comb_sort\n");
    int array[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = sizeof(array) / sizeof(array[0]);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    comb_sort(array, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }

    printf("\n");

    return 0;
}

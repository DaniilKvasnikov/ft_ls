

#include "ft_ls.h"

void    swap(t_path_info *a, t_path_info *b)
{
    t_path_info tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

int     partition(t_path_info *arr, int low, int high)
{
    t_path_info pivot;
    int         i;
    int         j;

    pivot = arr[high];  
    i = (low - 1);
    j = low - 1;
    while (++j <= (high - 1))
    {
        if (ft_strcmp(arr[j].entry->d_name, pivot.entry->d_name) < 0)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void    ft_quicksort(t_path_info *arr, int low, int high)
{
    int pi;

    if (low < high)
    {
        pi = partition(arr, low, high);
        ft_quicksort(arr, low, pi - 1);
        ft_quicksort(arr, pi + 1, high);
    }
}
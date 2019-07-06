

#include "ft_ls.h"

void
    swap(t_path_info *a, t_path_info *b)
{
    t_path_info tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

static int
    ft_cmp(t_path_info *obj1, t_path_info *obj2, char *flag)
{
    long long cmp;

    cmp = 0;
    if (is_flag_ls(flag, 't'))
        cmp = obj2->time_all - obj1->time_all;
    if (cmp == 0)
        cmp = ft_strcmp(obj1->name, obj2->name);
    if (is_flag_ls(flag, 'r'))
        return (cmp > 0);
    else
        return (cmp < 0);
}

static int
    partition(t_path_info *arr, int low, int high, char *flag)
{
    t_path_info pivot;
    int         i;
    int         j;

    pivot = arr[high];  
    i = (low - 1);
    j = low - 1;
    while (++j <= (high - 1))
    {
        if (ft_cmp(&arr[j], &pivot, flag))
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void
    ft_quicksort(t_path_info *arr, int low, int high, char *flag)
{
    int pi;

    if (low < high)
    {
        pi = partition(arr, low, high, flag);
        ft_quicksort(arr, low, pi - 1, flag);
        ft_quicksort(arr, pi + 1, high, flag);
    }
}
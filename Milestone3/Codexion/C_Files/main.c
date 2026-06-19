#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "codexion.h"

int check_values(int argc, char **argv)
{
    int i;
    int n;

    i = 1;
    if (argc != 9)
        return (1);
    while (i != argc - 1)
    {
        n = atoi(argv[i]);
        if (n < 0)
            return (1);
        i++;
    }
    if (strcmp(argv[argc -1], "fifo") != 0 || strcmp(argv[argc -1], "edf") != 0)
        return (1);
    return (0);
}

int main(int argc, char **argv)
{
    if (check_values(argc, argv) == 1)
        return (1);
    if (strcmp(argv[argc -1], "fifo") == 0)
        fifo(argc, argv);
    if (strcmp(argv[argc -1], "edf") == 0)
        edf(argc, argv);
    return (0);
}
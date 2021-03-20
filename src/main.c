#include <stdio.h>
#include <stdlib.h>

#include "caesar.h"
#include "cli.h"

int main(int argc, char *argv[])
{
    struct Arguments args = parse_arguments(argc - 1, argv + 1);

    if (args.help == 1)
    {
        printf(get_help());
        exit(0);
    }

    int c;
    while ((c = getchar()) != EOF)
    {
        putchar(caesar(c, &args));
    }
}
#include <stdio.h>

#include "cli.h"

static int isSmall(int c)
{
    return c >= 'a' && c <= 'z';
}

static int isCapital(int c)
{
    return c >= 'A' && c <= 'Z';
}

int caesar(int c, struct Arguments *args)
{
    int normalize;
    if (isCapital(c))
    {
        normalize = 'A';
    }
    else if (isSmall(c))
    {
        normalize = 'a';
    }
    else if (args->normalize == 1)
    {
        return 0;
    }
    else
    {

        return c;
    }

    c = (c - normalize + args->shift) % 26;
    if (c < 0)
    {
        c += 26;
    }

    if (args->capitalize == 1)
    {
        c += 'A';
    }
    else
    {
        c += normalize;
    }
    return c;
}
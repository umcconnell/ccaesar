#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cli.h"

struct Arguments parse_arguments(int count, char *args[])
{
    struct Arguments arguments = {.shift = 1, .help = 0, .capitalize = 0, .normalize = 0};

    for (int i = 0; i < count; i++)
    {
        char *flag = args[i];

        if (strcmp(flag, "--shift") == 0 || strcmp(flag, "-s") == 0)
        {
            if (i + 1 < count)
            {
                arguments.shift = atoi(args[i + 1]);
            }
            else
            {
                printf("No argument for 'shift' given!\n");
                exit(1);
            }
        }
        else if (strcmp(flag, "--capitalize") == 0 || strcmp(flag, "-c") == 0)
        {
            arguments.capitalize = 1;
        }
        else if (strcmp(flag, "--normalize") == 0 || strcmp(flag, "-n") == 0)
        {
            arguments.normalize = 1;
        }
        else if (strcmp(flag, "--help") == 0 || strcmp(flag, "-h") == 0)
        {
            arguments.help = 1;
        }
    }

    return arguments;
}

const char *get_help()
{
    return "ccaesar 1.0.0\n"
           "Ulysse McConnell <ulysse.mcconnell+dev@protonmail.com>\n"
           "\n"
           "ccaesar applies the caesar cipher to the stdin stream.\n"
           "\n"
           "USAGE:\n"
           "    ccaesar\n"
           "    ccaesar [OPTIONS]\n"
           "\n"
           "OPTIONS:\n"
           "    -h, --help:\t\tshow this help\n"
           "    -s, --shift <NUM>:\tAmount to shift characters by\n"
           "    -c, --capitalize:\tWhether to capitalize all letters\n"
           "    -n, --normalize:\tWhether to remove all special characters\n"
           "\n"
           "EXAMPLES:\n"
           "    cat my_file.txt | caesar -s 5\n"
           "    cat my_file.txt | caesar -s 7 -n -c\n";
}

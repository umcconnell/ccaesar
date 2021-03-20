typedef struct Arguments
{
    int shift;
    int help;
    int capitalize;
    int normalize;
} Arguments;

extern struct Arguments parse_arguments(int count, char *args[]);
extern const char *get_help();
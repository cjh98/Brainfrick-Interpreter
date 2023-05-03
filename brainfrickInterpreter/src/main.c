#include "brainfrick.h"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        fprintf(stderr, "Not enough arguments");
        exit(-1);
    }

    char *source = load_source(argv[1]);

    puts("SOURCE: ");
    printf("%s\n", source);

    puts("\nOUTPUT: ");
    decode_execute(source);
}
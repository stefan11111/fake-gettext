#include <stdio.h>

int main(int argc, char **argv)
{
    if (argc < 2) {
        fprintf(stderr, "%s: missing arguments\n", argv[0]);
        return 0;
    }

    printf("%s", argv[argc - 1]);
    return 0;
}

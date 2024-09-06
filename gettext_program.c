#define _POSIX_C_SOURCE 200112L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    if(argc < 2) {
        return 0;
    }

    if(argc == 2 && !strncmp(argv[1], "--version", sizeof("--version") - 1)) {
        printf("%s (GNU gettext-tools) 0.22.4\n", argv[0]);
        return 0;
    }

#define CHECK_FOR_NOT_STD(str) ((str)[0] != '-' || (str)[1] != '\0')
#define FOPEN_OR_STD(str, mode, file) ((CHECK_FOR_NOT_STD(str)) ? fopen((str), (mode)) : (file))
#ifndef JUST_TOUCH_FILES
    FILE *g = NULL;
    char **output_idx = NULL;
    for(char **p = argv; *p; p++) {
        if (!strncmp(*p, "-o", sizeof("-o") - 1)) {
            g = FOPEN_OR_STD (*(p + 1), "w", stdout);
            output_idx = p + 1;
            break;
        }

        if (!strncmp(*p, "--output-file=", sizeof("--output-file=") - 1)) {
            g = FOPEN_OR_STD (*p + sizeof("--output-file=") - 1, "w", stdout);
            output_idx = p;
            break;
        }
    }

    if (!g) {
        return 0;
    }

    FILE *f = NULL;

    for(char **p = argv; *p; p++) {
        if (!strncmp(*p, "--template", sizeof("--template") - 1)) {
            f = fopen(*p + sizeof("--template=") - 1, "r");
        }
    }

    if (!f) {
        for(char **p = argv; *p; p++) {
            if(**p == '-' && (*p)[1] == '\0') {
                f = stdin;
            }
        }
    }

    if (!f) {
        for(char **p = argv + argc - 1; p != argv; p--) {
            if(p == output_idx) {
                continue;
            }
            if(**p != '-') {
                f = fopen(*p, "r");
                if (f) {
                   break;
                }
            }
        }
    }

    if (!f) {
        return 0;
    }

    int ifd = fileno(f);
    int ofd = fileno(g);
    char buf[8192];
    for(;;) {
        int nread = read(ifd, buf, sizeof(buf));
        if (nread <= 0) {
            return 0;
        }
        (void)!write(ofd, buf, nread);
    }
#else
    for(char **p = argv; *p; p++) {
        if (!strncmp(*p, "-o", sizeof("-o") - 1)) {
            if (CHECK_FOR_NOT_STD(*(p + 1))) {
                (void)!fopen(*(p + 1), "w");
            }
            return 0;
        }

        if (!strncmp(*p, "--output-file=", sizeof("--output-file=") - 1)) {
            if (CHECK_FOR_NOT_STD(*p + sizeof("--output-file=") - 1)) {
                (void)!fopen(*p + sizeof("--output-file=") - 1, "w");
            }
            return 0;
        }
    }
    return 0;
#endif
}

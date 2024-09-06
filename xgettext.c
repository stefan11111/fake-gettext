#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PATH_MAX 4096

int main(int argc, char **argv)
{
    if(argc < 2) {
        return 0;
    }

    if(argc == 2 && !memcmp(argv[1], "--version", sizeof("--version") - 1)) {
        printf("%s (GNU gettext-tools) 0.22.4\n", argv[0]);
        return 0;
    }

    for(char **p = argv; *p; p++) {
        if (!memcmp(*p, "-o", sizeof("-o") - 1)) {
            p++;
            (void)!fopen(*p, "w");
            return 0;
        }

        if (!memcmp(*p, "--output-file=", sizeof("--output-file=") - 1)) {
            (void)!fopen(*p + sizeof("--output-file=") - 1, "w");
            return 0;
        }

        if (!memcmp(*p, "-d", sizeof("-d") - 1)) {
            p++;
            char path[PATH_MAX + sizeof(".po")];
            int len = strlen(*p);
            if (len > PATH_MAX) {
                len = PATH_MAX;
            }
            memcpy(path, *p, len);
            memcpy(path + len, ".po", sizeof(".po"));
            (void)!fopen(path, "w");
            return 0;
        }

        if (!memcmp(*p, "--default-domain=", sizeof("--default-domain=") - 1)) {
            char path[PATH_MAX + sizeof(".po")];
            int len = strlen(*p + sizeof("--default-domain=") - 1);
            if (len > PATH_MAX) {
                len = PATH_MAX;
            }
            memcpy(path, *p + sizeof("--default-domain=") - 1, len);
            memcpy(path + len, ".po", sizeof(".po"));
            (void)!fopen(dst, "w");
            return 0;
        }
    }

    (void)!fopen("messages.po", "w");
    return 0;
}

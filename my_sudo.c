#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define SIZE_BUFFER 5*1024 

static char buf[SIZE_BUFFER];

int main(int argc, char**argv)
{
    if (argc <= 1) {
        printf("usage: %s PROGRAMM [ARG1] ... [ARGN]\n", argv[0]);
        return 0;
    }

    buf[0] = '\0';
    int i; for (i = 1; i<argc; i++) {
        strncat(buf, "\"",sizeof(buf));
        strncat(buf, argv[i],sizeof(buf));
        strncat(buf, "\"",sizeof(buf));
        strncat(buf, " ",sizeof(buf));
    }
    setreuid(geteuid(), getuid());
    system(buf);
    return 0;
}

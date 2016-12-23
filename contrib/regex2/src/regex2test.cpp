// Taken and changed for Windows from ../../posix/regexbug1.c

#include <regex.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    regex_t re;
    regmatch_t ma[2];
    int reerr;
    int res = 0;

    re_set_syntax(RE_DEBUG);
    reerr = regcomp(&re, "0*[0-9][0-9]", 0);
    if (reerr != 0)
    {
        char buf[100];
        regerror(reerr, &re, buf, sizeof buf);
        fprintf(stderr, "%s", buf);
        return EXIT_FAILURE;
    }

    if (regexec(&re, "002", 2, ma, 0) != 0)
    {
        fprintf(stderr, "\"0*[0-9][0-9]\" does not match \"002\"");
        res = 1;
    }
    puts("Succesful match with \"0*[0-9][0-9]\"");

    regfree(&re);

    reerr = regcomp(&re, "[0a]*[0-9][0-9]", 0);
    if (reerr != 0)
    {
        char buf[100];
        regerror(reerr, &re, buf, sizeof buf);
        fprintf(stderr, "%s", buf);
        return EXIT_FAILURE;
    }

    if (regexec(&re, "002", 2, ma, 0) != 0)
    {
        fprintf(stderr, "\"[0a]*[0-9][0-9]\" does not match \"002\"");
        res = 1;
    }
    puts("Succesful match with \"[0a]*[0-9][0-9]\"");

    regfree(&re);

    return res;
}

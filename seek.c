#include <stdio.h>
#include <ctype.h>

int isitint(char *p);

int main(int argc, char *argv[])
{
    int cur = 2;
    if (argc < 2)
    {
        printf("NOT ENOGH ARGUMENTS!");
        return -1;
    }
    int pos = (int)*argv[1];
    long int n=isitint(argv[1]);
    if (n == -1)
    {
        printf("INDEX NOT VALID");
        return -1;
    }

    while (cur < argc)
    {
    FILE *fp = fopen(argv[cur],"r");
    if (!fp)
    {
        printf("%s %s", argv[cur], "WOULDN'T OPEN\n");
        cur++;
        continue;
    }
    fseek(fp, n, SEEK_SET);
    if (getc(fp) == -1)
    printf("%s %s",argv[cur]," IS SHORTER THAN THE INDEX\n");
    else
    printf("%s %s %d\n", argv[cur], "ASCII CODE IS: ", getc(fp));
    fclose(fp);
   
    cur++;
    }
}

int isitint(char *p)
{
    long int n;
    n = 0;
    while (*p)
    {
        if (!(isdigit(*p)))
            return -1;
        n = n*10;
        n += *p++-'0';
    }
    return n;
}
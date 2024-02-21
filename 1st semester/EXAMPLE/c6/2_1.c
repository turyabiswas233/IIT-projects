#include <stdio.h>
int main(int argc, char const *argv[])
{

    void *vp;
    char *cp, ch;
    int *ip, i;
    float *fp, f;
    double *dp, d;
    long long *ldp, ld;
    vp = &vp;
    cp = &ch;
    ip = &i;
    fp = &f;
    dp = &d;
    ldp = &ld;

    // print the current values
    printf("%p %p %p %p %p %p\n", vp, cp, ip, fp, dp, ldp);

    vp++;
    ch++;
    ip++;
    fp++;
    dp++;
    ldp++;

    // print the new values
    printf("%p %p %p %p %p %p\n", vp, cp, ip, fp, dp, ldp);

    return 0;
}

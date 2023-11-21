#include <stdio.h>

int main(int argc, char const *argv[])
{
    float *fp, **mfp, val;

    fp = &val;
    mfp = &fp;

    **mfp = 3.1416;

    printf("%f %f\n", val, **mfp);
    return 0;
}

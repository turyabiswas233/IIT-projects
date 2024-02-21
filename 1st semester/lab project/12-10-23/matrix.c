#include <stdio.h>
int main() {
    int m1[2][2] ={{1 ,2},{3,4}},m2[2][2] = {{10 ,20},{3,4}};

    /*
    1 2 => (0,0) (0,1)
    3 4 => (1,0) (1,1)
    */
   int ans[2][2];

   for (int i = 0; i < 2; i++)
   {
    /* code */
    for (int j = 0; j < 2; j++)
    {
        /* code */
        ans[i][j] = m1[i][j] + m2[i][j];
        printf("%d ",ans[i][j]);
    }
    printf("\n");

    
   }

   
}
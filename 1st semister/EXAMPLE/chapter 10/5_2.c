#include<stdio.h>
#include<stdlib.h>

//structure
struct br
{
   unsigned a : 1;
   unsigned b : 1;
   unsigned c : 1;
   unsigned d : 1;
   unsigned e : 1;
   unsigned f : 1;
   unsigned g : 1;
   unsigned h : 1;
};

union c_typ
{
   char c;
   struct br t;
}s;

//main function
int main(){
    printf("enter a character:");
    scanf("%c",&s.c);
    printf("binary code is : ");
     printf("%u", s.t.h);
     printf("%u", s.t.g);
     printf("%u", s.t.f);
     printf("%u", s.t.d);
     printf("%u", s.t.e);
     printf("%u", s.t.c);
     printf("%u", s.t.b);
     printf("%u", s.t.a);

    return 0;
}
//this is the perfect code :)sir aivabe koraisilo mone ase

//eta kiser code? binary te je ase oita
//ki faltu code krsos :)oma taile millo kmne aita milbei to. but method ta faul boi e amn silo deklm pore oita diaia krsilo
//bujli?hmm vul ase
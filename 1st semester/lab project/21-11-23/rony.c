#include<stdio.h>
void commision_amount(float x){
    if(0<=x<=1000)
    printf("%lf is commision amount ",x*0.05);
    else if(1000<x<=2000)
    printf("%lf is the commision amount ",x*0.1);
    else if(x>2000)
    printf("%lf is the commision amoun",x*0.12);
    
    

}
int main(){
    float s=0;
    printf("Enter the sales amount is ");
    scanf("%f",&s);
    commision_amount(s);
    return 0;
}
#include <stdio.h>


int mcd(int x, int y, int res);


int main(){

     int x=0,y=0;
     int res=0;

     printf("\nIntroduzca un numero x → ");
     scanf("%i",&x);
     printf("\nIntroduzca un numero y → ");
     scanf("%i",&y);

     res = mcd(x,y,res);

     printf("\nEl maximo común divisor es %i\n",res);

     return 0;


}

int mcd(int x, int y, int res){

     if(y==0)

        return x;

    else

        res = mcd(y, x%y, res);

}

#include <stdio.h>
#include <math.h>

float original(float x,int poly[],int n)
{
    float result = 0;

    // Evaluacion del polinomio con el metodo de horner 
    for (int i=n; i>=0; i--)

            result = result*x + poly[i];

    return result;
}



float derivada(float  x,int poly[],int n)
{
    float  result = 0;
    int i;
    // Evaluacion del polinomio con el metodo de horner 
    for (i=n;i>0;i--){

            result += pow(x,i-1)*i*poly[i];
         }
    return result;
}





int main()
{

    int n,i;	
    float x0,x1,xn,xn1,error,tolerancia,fx0,fxn,f1;
   printf("Introduce el grado del polinomio:");
   scanf("%d",&n);
   int poly[n+1];

   printf("\nIntroduce los coeficientes del polinomio (a0 es el elemento de grado 0)\n");
   for(i=n;i>=0;i--){
   printf("a%d=",i);
   scanf("%d",&poly[i]);
   }

   printf("El polinomio ingresado fue\n");
   for(i=n;i>0;i--){
   printf("(%d)x^%d +",poly[i],i);
   }
   printf("(%d)x^0\n",poly[0]);

    printf("\nx0 = ");
    scanf("%f",&x0);
    
    fx0 = original(x0,poly,n);
    f1 = derivada(x0,poly,n);

    if(fx0 == 0){
		printf("%f es una raiz del polinomio\n",x0);
		}
		
		
	else{	
    
printf("Introduce el error:");
scanf("%f",&tolerancia);
printf("\n");
printf("Ite\txn+1\t\tf(xn)\t\tf'(xn)\t\terror\n");
printf("%d\t%f\t%f\t%f\t----\n",i++,x0,fx0,f1);
do{
   
    
         x1 = x0;             
	 xn1 = x1 - (fx0/f1);  
         fx0 = original(xn1,poly,n);
	 f1 = derivada(xn1,poly,n);
         error =fabs((xn1-x1)/xn1);
         printf("%d\t%f\t%f\t%f\t%f\n",i++,xn1,fx0,f1,error);
         x0 = xn1;
   
}while(error > tolerancia);

printf("Una posible raiz es: %f\n",xn1);
}    
    

   

    return 0;
}

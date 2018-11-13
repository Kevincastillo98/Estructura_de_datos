#include <stdio.h>
#include <math.h>

float horner(int poly[], float n, float  x)
{
    float result = 0;

    // Evaluacion del polinomio con el metodo de horner 
    for (int i=n; i>=0; i--)

            result = result*x + poly[i];

    return result;
}

int main()
{

    int n,i;	
    float fa,fb,a,b,fc,c,d;
    float error=0,tolerancia;

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
   printf("(%d)x^0",poly[0]);

    
 
    printf("\nIntroduce el valor de a:");
    scanf("%f",&a);
    fa = horner(poly,n,a);
    printf("f(%f) = %f",a,fa);
    printf("\nIntroduce el valor de b:");
    scanf("%f",&b);
    fb=horner(poly,n,b);
    printf("f(%f) = %f\n",b,fb);
    


if((fa*fb)>0){
        printf("Intervalo incorrecto\n");
     //   exit(1);
}
else if(fa==0 || fb==0){
        printf("una raiz es %f\n",fa== 0 ? a:b);
       // exit(0);
}
printf("Introduce el error:");
scanf("%f",&tolerancia);
printf("\n");
printf("Ite\ta\t\tb\t\tc\t\tf(c)\t\terror\n");
do{
        d=c;
        c=(((a*fb)-(b*fa))/(fb-fa));
        fc = horner(poly,n,c);
        
        printf("%d\t%f\t%f\t%f\t%f\t",i++,a,b,c,fc);
        
	
	if(fc==0){
            break;
        }else if(fa*fc<0){
                b=c;
        }else a=c;
                error=fabs((c-d)/c);
        if(i==1){
                printf("----\n");
        }else printf("%4.6f\n",error);


}while(error > tolerancia);
printf(" La raiz es: %f \n",c);


    return 0;
}

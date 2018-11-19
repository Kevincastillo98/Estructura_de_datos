/*
 * | Nombre:Castillo Roa Kevin
 * | Grupo:1302
 */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Dimension;
float ValorAbsoluto(float vectorx1[],float vectorx0[]);
float Jacobi(float Matriz[], float vector[], int componente);

int main(){

    int i,j,iteraciones=0;
    float error,epsilon;
    printf("\n JACOBI \n");

    printf("Dimensionension de la matriz : ");
    scanf("%d",&Dimension);
    float A[Dimension][Dimension],b[Dimension],x[Dimension],x_prev[Dimension],temp[Dimension];

    printf("\n Elementos de la matriz: \n");
    for(i=0;i<Dimension;i++) for(j=0;j<Dimension;j++){
        printf("A(%d,%d)=",i+1,j+1); scanf("%f",&A[i][j]);
    }

    printf("\n Elementos del vector b: \n");
    for(i=0;i<Dimension;i++){
        printf("b(%d)=",i+1); scanf("%f",&b[i]);
    }

    printf("\n Error\n");
    printf("E=");
    scanf("%f",&epsilon);
    error=epsilon+1;


    printf("\n Valor inicial: \n");
    for(i=0;i<Dimension;i++){
        printf("x0(%d)=",i+1);
        scanf("%f",&x_prev[i]);
    }
        
    while (error > epsilon){
        for(i=0;i<Dimension;i++){
            for(j=0;j<Dimension;j++) temp[j]=A[i][j];
            x[i]=(1/A[i][i])*(b[i]-Jacobi(temp,x_prev,i));
        }
        error=ValorAbsoluto(x,x_prev);

        printf("\n\n %d: ",iteraciones+1);
       	for(i=0;i<Dimension;i++){
            x_prev[i]=x[i];
            printf("x(%d)=%f\t",i,x[i]);
        }
        printf("error = %.6f",error);

        iteraciones++;
        if (iteraciones==101)  error=epsilon-1;


    }

    printf("\n\nSolucion del sistema\n");
    for(i=0;i<Dimension;i++){
        printf("x(%d)=%.6f\n",i+1,x[i]);
    }
    return 1;
}

//Se calcula el error 
float ValorAbsoluto(float vectorx1[],float vectorx0[]){
    float temp=0;
    int i;
    for(i=0;i<Dimension;i++){

        temp = fabs((vectorx1[0]-vectorx0[0])/(vectorx1[0]));
    }
    return temp;
}

//Despeja 
float Jacobi(float Matriz[], float vector[], int componente)
{
    float temp=0;
    int i;
    for(i=0;i<Dimension;i++){
        if (componente!=i){
            temp=temp+Matriz[i]*vector[i];
        }
    }
    return temp;
}

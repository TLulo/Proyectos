#include <stdio.h>
#include <stdbool.h>

int n,res;

void imprimeBooleano(bool x){
    if (x){
        printf("El resultado de la funcion es True\n");
    }
    else{
        printf("El resultado de la funcion es False\n");
    }
}

int pedirEntero(char let){
    int a;
    printf("Ingrese el valor de %c :",let);
    scanf("%d",&a);
    return a;
}

void pedirArreglo(int a[],int n_max){
    int i;
    i = 0;
    while (i < n_max){
        printf("Ingrese el valor del arreglo en la posicion %d: ",i+1);
        scanf("%d",&a[i]);
        i=i+1;
    }
}

bool existe_positivo(int a[],int tam){
    int i;
    i = 0;
    while (i < tam){
        if (a[i]>=0){
            return 1;
        }
        else{
            i=i+1;
        }
    }    
    return 0;
}

bool todos_positivos(int a[],int tam){
    int i;
    i = 0;
    while (i<tam){
        if (a[i]<0){
            return 0;
        }else{
            i = i+1;
        }
    }
    return 1;
}

void menu(int a[],int tam){
    int i;
    i = 1;
    while (i !=0){
        printf("**********************************************************************************\n");
        printf("Ingrese 1 si desea utilizar la funcion existe positivo.\nIngrese 2 si desea utilizar la funcion todos positivos.\nIngrese 0 si desea cerrar el menu\n");
        printf("**********************************************************************************\n");
        i = pedirEntero('i');
        if (i == 1){
            res = existe_positivo(a,tam);
            imprimeBooleano(res);
        }else if( i == 2){
            res = todos_positivos(a,tam);
            imprimeBooleano(res);
        }else if(i == 0){
            printf("Termina el programa\n");
        }else{
            printf("Ingrese un valor valido\n");
        }
    }
}

int main(void){
    n = pedirEntero('n');
    int a[n];
    pedirArreglo(a,n);
    menu(a,n);
}
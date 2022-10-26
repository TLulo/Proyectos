#include <stdio.h>

int x, y, z, min, absoluto;

int pedirEntero(char let){
    int a;
    printf("Ingrese el valor de %c :",let);
    scanf("%d",&a);
    return a;
}

void imprimeEntero(int x,char let){
    printf("El valor de %c es: %d\n",let,x);
}

int minimo(int a, int b){
    int res;
    if (a <= b){
        res = a;
    }
    else if (a > b){
        res = b;
    }
    return res; 
}

int valor_Absoluto(int a){
    int res;
    if (a >= 0){
        res = a;
    }
    else if (a < 0){
        res = -a;
    }
    return res;
}

void intercambio(int a, int b,int c){
    int aAux,bAux,cAux;
    aAux= a;
    bAux = b;
    cAux = c;
    a= bAux;
    b = cAux;
    c = aAux;
    imprimeEntero(a,'x');
    imprimeEntero(b,'y');
    imprimeEntero(c,'z');
}

int main(void){
    x = pedirEntero('x');
    y = pedirEntero('y');
    z = pedirEntero('z');

    min = minimo(x,y);
    printf("El resultado del minimo entre x e y se mostrara a continuacion.\n");
    imprimeEntero(min,'x');
    absoluto = valor_Absoluto(x);
    printf("El resultado del Valor Absoluto de x se mostrara a continuacion.\n");
    imprimeEntero(absoluto,'x');
    printf("Los intercambios son:\n");
    intercambio(x,y,z);
}


//----------------------------------- ASI LO RESUELVE AL 1 B UN GIGACHAD DE VERDAD ----------------------------------------------------------
#include<stdio.h>
#include<assert.h>


int pedirEntero(void){
    int i;
    assert (i>0 || i< 0);
    printf("Introduzca el numero:\n");
    scanf("%d",&i);
    return i;
}

int imprimeEntero(int x){
    printf("El numero es: %d\n",x);
}

int minimo (int a, int b) {
    int res;
    if (a > b) {
        res = b;
    } else {
        res = a;
    }    
    return res;
}

int main(void) {
    int x,y,min;
    x = pedirEntero();
    y = pedirEntero();
    min= minimo(x,y);
    printf("El minimo entre %d y %d es %d", x, y, min);
    assert (min>0 || min< 0);
}

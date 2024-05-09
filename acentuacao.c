#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main(){
    // permite uso de acentuação
    setlocale(LC_ALL,"");
    printf("Olá!");
}


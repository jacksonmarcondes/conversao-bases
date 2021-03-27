#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void opcoes_menu(){
        system("clear");
        printf("Escolha a opção de conversão:");
        printf("\n1 - Decimal para binário");
        printf("\n2 - Decimal para octal");
        printf("\n3 - Decimal para outra base (digite a base)");
        printf("\n4 - Binario para decimal");
        printf("\n5 - Binario para octal");
        printf("\n6 - Binario para outra base (digite a base)");
        printf("\n7 - Sair");
        printf("\n");
}

void converter_decimal(int base, long numero = 0) {
    long resultado = 0;
        int i = 1;
    if(numero == 0){
        printf("\nDigite o número: ");
        scanf("%ld", &numero);
    }
    printf("\n%ld na base %d: ", numero, base);

    while (numero != 0) {
        resultado += (numero % base) * i;
        numero /= base;
        i *= 10;
    }
    printf("%ld(%d)\n", resultado, base);
}

void converter_binario(int base) {
    long resultado = 0, i = 0, resto;
    long numero = 0;
    long numeroOriginal = 0;
    printf("\nDigite o número: ");
    scanf("%ld", &numero);
    numeroOriginal = numero;

    while (numero != 0) {
        resto = numero % 10;
        numero /= 10;
        resultado += resto * pow(2, i);
        i++;
    }
    if(base != 10)
            converter_decimal(base,resultado);
    else{
            printf("\n%ld na base %d: ", numeroOriginal, base);
            printf("%ld(%d)\n", resultado, base);
    }
}


int main() {
    int opcao = 0;
    int base = 0;
    while (opcao != 7) {
        opcoes_menu();
        printf("\nDigite o número da conversão escolhida: ");
        if (!scanf("%d", &opcao))
            scanf("%*[^\n]");
        fflush(stdin);
        system("clear");
        switch (opcao) {
        case 1:
            printf("1 - Decimal para binário");
            converter_decimal(2);
            return 0;
            break;
        case 2:
            printf("2 - Decimal para octal");
            converter_decimal(8);
            return 0;
            break;
        case 3:
            printf("3 - Decimal para outra base");
            printf("\nDigite a base: ");
            scanf("%d", &base);
            converter_decimal(base);
            return 0;
            break;
        case 4:
            printf("4 - Binario para decimal");
            converter_binario(10);
            return 0;
            break;
        case 5:
            printf("5 - Binario para octal");
            converter_binario(8);
            return 0;
            break;
        case 6:
            printf("6 - Binario para outra base");
            printf("\nDigite a base: ");
            scanf("%d", &base);
            converter_binario(base);
            return 0;
            break;
        case 7:
            printf("O programa será encerrado.\n");
            return 0;
            break;
        default:
            printf("Opção inválida, tente novamente.\n");
            break;
        }
    }
    return 0;
}
#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

int decimal_binario(int num);
int decimal_octal(int num);
int hexadecimal_decimal(char *hexadecimal);
int binario_decimal(int num);
int octal_decimal(int num);
//char *decimal_hexadecimal(int decimal);

int main(){
    setlocale(LC_ALL,"");

    int base, num, binario, decimal, octal;
    char *hexadecimal = malloc(50 * sizeof(char));

    printf("\n\tSelecione uma base\n\n 1 - Binário\n 2 - Octal\n 3 - Decimal\n 4 - Hexadecimal\n>");
    scanf("%i", &base);

    printf("Digite um número na base ");
    switch(base){
        case 1: printf("binária: ");
        scanf("%i", &num);

        decimal = binario_decimal(num);
        octal = decimal_octal(decimal);
        //strcpy(hexadecimal, decimal_hexadecimal(decimal));

        printf("\n Binário: %i\n Decimal: %i\n Octal: %i\n Hexadecimal: %o\n", num, decimal, octal, decimal);

        break;

        case 2: printf("octal: ");
        scanf("%i", &num);

        decimal = octal_decimal(num);
        binario = decimal_binario(decimal);
        //strcpy(hexadecimal, decimal_hexadecimal(decimal));

        printf("\n Binário: %i\n Decimal: %i\n Octal: %i\n Hexadecimal: %o\n", binario, decimal, num, decimal);

        break;

        case 3: printf("decimal: ");
        scanf("%i", &num);

        binario = decimal_binario(num);
        octal = decimal_octal(num);
        //strcpy(hexadecimal, decimal_hexadecimal(num));

        printf("\n Binário: %i\n Decimal: %i\n Octal: %i\n Hexadecimal: %o", binario, num, octal, num);
        break;

        case 4: printf("hexadecimal: ");
        fflush(stdin);
        gets(hexadecimal);

        decimal = hexadecimal_decimal(hexadecimal);
        binario = decimal_binario(decimal);
        octal = decimal_octal(decimal);

        printf("\n Binário: %i\n Decimal: %i\n Octal: %i\n Hexadecimal: %s", binario, decimal, octal, hexadecimal);
        break;
    }

    return 0;
}

int decimal_binario(int num){
    int resto, binario = 0, i;

    for(i = 0; num > 0; i++){
        resto = num % 2;
        binario += (resto * pow(10, i));
        num /= 2;
    }
    
    binario += (num * pow(10, i));

    return binario;
}

int decimal_octal(int num){
    int resto, octal = 0, i;

    for(i = 0; num > 7; i++){
        resto = num % 8;
        octal += (resto * pow(10, i));
        num /= 8;
    }
    octal += (num * pow(10, i));

    return octal;
}

int binario_decimal(int num){
    int resto, decimal = 0;

    for(int i = 0; num > 0; i++){
        resto = num % 10;
        decimal += (resto * pow(2, i));
        num /= 10;
    }

    return decimal;
}

int octal_decimal(int num){
    int resto, decimal = 0;

    for(int i = 0; num > 0; i++){
        resto = num % 10;
        decimal += (resto * pow(8, i));
        num /= 10;
    }

    return decimal;
}

int hexadecimal_decimal(char *hexadecimal){
    int decimal = 0, i, total = strlen(hexadecimal) - 1, test;

    for (i = 0; total >= 0; i++)
    {
        if (hexadecimal[i] == 'A' || hexadecimal[i] == 'a')
        {
            test = 10;
        }
        else if (hexadecimal[i] == 'B' || hexadecimal[i] == 'b')
        {
            test = 11;
        }
        else if (hexadecimal[i] == 'C' || hexadecimal[i] == 'c')
        {
            test = 12;
        }
        else if (hexadecimal[i] == 'D' || hexadecimal[i] == 'd')
        {
            test = 13;
        }
        else if (hexadecimal[i] == 'E' || hexadecimal[i] == 'e')
        {
            test = 14;
        }
        else if (hexadecimal[i] == 'F' || hexadecimal[i] == 'f')
        {
            test = 15;
        }
        else if (hexadecimal[i] >= 0 || hexadecimal[i] < 10)
        {
            test = hexadecimal[i];
            test -= 48;
        }
        else{
            return 0;
        }
        decimal += (test * pow(16,total));
        total--;
    }
    
    return decimal;
}

/*char *decimal_hexadecimal(int decimal){
    char *hexadecimal = malloc(50 * sizeof(char));
    int resto, i;

    for (i = 0; decimal > 15; i++)
    {
        printf("%i", resto);
        resto = decimal % 16;
        switch(resto){
            case 10:
            resto = 'A';
            break;

            case 11:
            resto = 'B';
            break;

            case 12:
            resto = 'C';
            break;

            case 13:
            resto = 'D';
            break;

            case 14:
            resto = 'E';
            break;

            case 15:
            resto = 'F';
            break;

            default:
            break;
        }
        hexadecimal[i] = resto;
        printf("%i %s",resto, hexadecimal);
        decimal /= 16;
    }
    printf("%i", decimal);
    hexadecimal[i] = decimal;
    return hexadecimal;
}*/

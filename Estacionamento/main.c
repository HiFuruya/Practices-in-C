#include <stdio.h>
#include <stdlib.h>
#include "parkif.h"

int main()
{
    veiculo x;
    int a = 10, retorno;
    char *placa = malloc(50 * sizeof(char));

    init();

    while(a != 0){
        system("cls");

	    printf("\n--------------------------");
	    printf("\n- 1) Entrada de Veiculo  -");
	    printf("\n- 2) Saida de Veiculo    -");
	    printf("\n- 3) Visualizar Veiculos -");
	    printf("\n- 0) Sair                -");
	    printf("\n--------------------------");
	    printf("\n>> ");
	    scanf("%i", &a);

	    switch(a){
	    	case 1:

	    	printf("\n- Entrada de Veiculo");
		    printf("\n- Marca: ");
		    fflush(stdin);
		    gets(x.marca);
		    printf("- Modelo: ");
		    fflush(stdin);
		    gets(x.modelo);
		    printf("- Cor: ");
		    fflush(stdin);
		    gets(x.cor);
		    printf("- Placa: ");
		    fflush(stdin);
		    gets(x.placa);

	    	add(x);
	    	printf("\n[OK]\n");
	    	fflush(stdin);
	    	break;

	    	case 2:
	    	printf("\n- Saida de Veiculo");
	    	printf("\n- Placa: ");
	    	fflush(stdin);
	    	gets(placa);

	    	retorno = rem(placa);

	    	if (retorno == 1)
	    	{
	    		printf("\n[Veiculo removido]\n");
	    	}
	    	else if (retorno == -1)
	    	{
	    		printf("\n[Erro - Placa nao encontrada]\n");
	    	}
	    	else{
	    		printf("\n[Estacionamento vazio]\n");
	    	}
    		placa = realloc(NULL, 50 * sizeof(char));
	    	fflush(stdin);
	    	break;

	    	case 3:
	    	view();
	    	printf("\n");
	    	fflush(stdin);
	    	break;

	    	case 0:
	    	break;

	    	default:
	    	printf("\nNenhuma opcao foi escolhida");
	    	break;
	    }
	    sleep(2);
	}
    return 0;
}

#ifndef _PARKIF_
#define _PARKIF_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

FILE *fp, *au;
int ret;

typedef struct {

    char marca[50];
    char modelo[50];
    char cor[20];
    char placa[10];

}veiculo;

veiculo x;

int pos = 0;
void init() {
    fp = fopen("db.bin", "a+b");
    fclose(fp);
}

void add(veiculo v) {
	fp = fopen("db.bin", "a+b");

    if(fp != NULL) {
        fwrite(&v, sizeof(veiculo), 1, fp);
    }
	else{
		printf("Erro ao abrir o arquivo");
	}
	fclose(fp);
	pos++;
}

int rem(char *placa) {
    int retorno = -1, cont = 0;
    fp = fopen("db.bin", "a+b");
    au = fopen("db2.bin", "a+b");
    do {
            ret = fread(&x, sizeof(veiculo), 1, fp);
            if(ret == 1) {
                if (strcmp(placa, x.placa) != 0)
                {
                    fwrite(&x, sizeof(veiculo), 1, au);
                }
                else{
                    retorno = 1;
                }
            }
            cont++;
        } while(ret == 1);

         if (cont == 1)
        {
            fclose(au);
            remove("db2.bin");
            return 2;
        }

        fclose(au);
        fclose(fp);
        remove("db.bin");
        rename("db2.bin", "db.bin");


        if (retorno == -1)
        {
            fclose(au);
            remove("db2.bin");
            return -1;
        }
        if (retorno == 1)
        {
            return 1;
        }
}

void view() {
    int pos = 0;

    printf("\n- Visualizacao de Veiculo");

  	fp = fopen("db.bin", "a+b");

    if(fp != NULL) {

        do {
            ret = fread(&x, sizeof(veiculo), 1, fp);
            if(ret == 1) {
                pos++;
                printf("\n%s - %s - %s - %s", x.marca, x.modelo, x.cor, x.placa);
            }
        } while(ret == 1);

        fclose(fp);
    }
	else{
		printf("Erro ao abrir o arquivo");
	}

    Sleep(pos * 3000);
}

#endif

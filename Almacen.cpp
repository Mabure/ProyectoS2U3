#include <stdio.h>
#include <stdlib.h>

int main(){
	int koy = 1;
	int pos, caco, prod[10][2];	bool PExistir[10];


	printf("ALMACEN\n");
	printf("Cuando quiera dejar de ingresar productos ingrese una posicion no disponible");							

	do{
		while(1){
/*GOTO SELECTPOS*/SelectPos:

			printf("Seleccione la posicion donde se encontrara su producto (0-9) \n");
			scanf("%i", &pos);
			if(pos < 0 || pos > 9){
				goto AlmacenExit;
			}
			else if(PExistir[pos] == false){
	/*GOTO SUS*/SUS:

				printf("Cuanto valdra su producto?:  ");
				scanf("%i", &caco);

				prod[pos][0] = caco;

				printf("Cuanto de este producto tiene?:  ");
				scanf("%i", &caco);

				prod[pos][1] = caco;

				PExistir[pos] = true;
			}
			else{
				printf("Esta posicion esta siendo ocupada por otro producto, Decea sustituarla?\n 	seleccione 1 para sustituir o  0 para escoger otra posicion\n ");
				scanf("%i", &koy);
			}
			if(koy == 0){
				goto SelectPos;
			}
			else if(koy == 1){
				goto SUS;
			}

		}
		AlmacenExit:

		printf("seleccione 1 para continuar o 0 para salir\n");
		scanf("%i", &koy);
	}while(koy != 0);
		
	return 0;
}

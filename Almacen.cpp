#include <stdio.h>
#include <stdlib.h>

int main(){
	int koy = 1;
	int pos, caco, prod[10][2];	bool PExistir[10] = {false, false, false, false, false, false, false, false, false, false};

	printf("ALMACEN\n");
	printf("Cuando quiera dejar de ingresar productos, ingrese una posiscion no disponible");							
/*GOTO SELECTPOS*/		SelectPos:

	printf("\nSeleccione la posicion donde se encontrara su producto (0-9) \n");
	scanf("%i", &pos);

	if(pos < 0 || pos > 9){
		goto AlmacenExit;
	}

	if(PExistir[pos] == false){
/*GOTO SUS*/			SUS:

		printf("Cuanto valdra su producto?:  ");
		scanf("%i", &cost);

		prod[pos][0] = cost;

		printf("Cuanto de este producto tiene?:  ");
		scanf("%i", &cant);

		prod[pos][1] = cant;

		PExistir[pos] = true;
	}
	else{
		printf("Esta posicion esta siendo ocupada por otro producto, Decea sustituarla?\n 	seleccione 0 para sustituir o  1 para escoger otra posicion\n ");
		scanf("%i", &koy);
	}

	if(koy == 0){
		goto SUS;
	}
	else{
		goto SelectPos;
	}

	goto SelectPos;

/*GOTO 	ALMACENEXIT*/			AlmacenExit:
	printf("\nEstas seguro? \n");
	printf("Seleccione 1 para volver a ingresar productos o 0 para salir\n");
	scanf("%i", &koy);

	if(koy != 0){
		goto SelectPos;
	}

	return 0;
}

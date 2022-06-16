#include<stdio.h>
#include<stdlib.h>

int main(){
	int GdelDia = 0, pago, venta = 0, caco, koy = 1;
//											0		1		 2	  	   3							
	int pos, cant, cost, prod[10][2] = {{30, 5}, {20, 7}, {15, 10}, {25, 8}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}};
	bool PExistir[10] = {true, true, true, true, true, false, false, false, false, false};
	
	printf("Cuando quiera dejar de ingresar productos a la lista, ingrese un producto no existente o una posicion \nno disponible en el almacen (posisciones disponibles en el almacen 0-9)");
/*GOTO VENTASTART*/			VentaStart:
	
	printf("\nCodigo de producto:  ");
	scanf("%i", &pos);
	
	if(PExistir[pos] == true && prod[pos][1] > 0){
/*GOTO CANTPROD*/			CantProd:		
		printf("Cuanto del producto se va a vender?   ");
		scanf("%i", &caco);
		
		if(caco > prod[pos][1]){
			printf("La cantidad de productos a vender y la cantidad en el almacen no coincide \n");
			printf("Desea continuar a pesar de esto? \nSelccione 1 si desea conitnuar o 0 si desea reingresar la cantidad de productos  ");
			scanf("%i", &koy);
			
			if(koy == 0){
				goto CantProd;
			}
		}else{
			koy = 1;
		}		
		
		prod[pos][1] -= caco;
		caco *= prod[pos][0];
		venta += caco;
		
	}
	else{
		printf("Este producto no se encuentra en el almacen o se a agotado \nQuiere continuar con la factura o quiere cerrar la factura? \n");
		printf("Sleccione 1 para continuar con la factura o 0 para cerrar la factura  ");
		scanf("%i", &koy);
	}
	
	if(koy == 0){
		goto FacturaExit;
	}
	
	goto VentaStart;
/*GOTO FACTURAEXIT*/			FacturaExit:
	printf("\nEsta es la factura:  %i \n", venta);
/*GOTO PAGARBIEN*/				PagarBien:
	printf("Con cuanto se va a pagar?  ");
	scanf("%i", &pago);
	
	if(pago < venta){
		printf("No es suficiente dinero \n");
		printf("Seleccione 1 para continuar o 0 para volver a pagar");
		scanf("%i", &koy);
		
		if(koy == 0){
			goto PagarBien;
		}
		GdelDia += pago;
	}
	
	printf("El cambio es %i", pago - venta);
	printf("\nSeleccione 0 para quedarse con el cambio o 1 para darle el cambio al cliente ");
	scanf("%i", &caco);
	if(caco == 0){
		GdelDia += pago;
	}
	else{
		GdelDia += venta;
	}
	
	printf("Seleccione 1 para realizar otra factura o 0 para salir ");
	scanf("%i", &koy);
	
	if(koy != 0){
		goto VentaStart;
	}
	
	return 0;	
}

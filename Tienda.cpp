#include <stdio.h>
#include <stdlib.h>
int main(){
//variables, constantes y arreglos
  //Variables del menu
	int selecc = 0, cont = 1, key = 0, koy = 1;
  //Matrizes de almacen
	int pos, cant, cost, prod[10][2]; /*En [x][0] se encontrara el precio, en [x][1] la cantidad*/	
	bool PExistir[10];
  //Variables de la venta
	int caco, pago, venta = 0, cambio;
  //Variable de la ganancia del dia
	int GdelDia = 0;	
  //Variable de la meta del dia
  	int Meta;	
	
	
	
//Codigo
	printf("Cual es su meta de ganancia del dia?"  );
	scanf("%i", &Meta);
	
	//Menu
	while(cont != 0){
		koy = 1;
		
		if(key!=1){
			printf("Abarrotes CBTIS\n");
			printf("MENU\n");
			printf("1.almacen\n2.ventas\n3.ganancias del dia\n4.bono y metas\n5.salir\n");
			scanf("%i", &selecc);
		}
		
		switch(selecc){
			//si eligen almacen
//																																	INICIO DE ALMACEN

			case 1:
				printf("ALMACEN\n");
				printf("Cuando quiera dejar de ingresar productos, ingrese una posiscion no disponible");							
		/*GOTO SELECTPOS*/		SelectPos:
				koy = 1;
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
				
				goto SelectPos;

		/*GOTO 	ALMACENEXIT*/			AlmacenExit:
				printf("\nEstas seguro de querer salir del almacen? \n");
				printf("Seleccione 1 para volver a ingresar productos o 0 para salir\n");
				scanf("%i", &koy);
				
				if(koy != 0){
					goto SelectPos;
				}

			break;																													//FIN DE ALMACEN
//																																	INICIO DE VENTAS
			//si eligen ventas
			case 2:
				printf("VENTAS");
				
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
			break;
			
			//si eligen ganancias del dia
			case 3:
				printf("GANANCIAS DEL DIA \n");
				printf("		%i  \n", GdelDia);
			break;
			
			//si eligen bono y metas
			case 4:
				printf("La meta de hoy es %i\n Falta %i \n", Meta, Meta - GdelDia);
				if(GdelDia >= Meta){
					printf("Felicidades, ojala el siguiente dia tambien alcances tu meta");
				}
				else{
					printf("Una pena que aun no llegues a tu meta, pero en algun momento se podra  (nunca paso TwT) \n");
				}
			break;
			
			//si eligen salida
			case 5:
				cont=-1;
			break;
			
			//disable
			default:
				while(key!=1){
					printf("porfavor seleccione una de las opciones disponibles\n");
					printf("1.almacen\n2.ventas\n3.ganancias del dia\n4.bono y metas\n5.salir\n");
					scanf("%i",&selecc);
					
					if(selecc > 0){
						if(selecc < 6){
							key++;
						}
					}
					if(cont == selecc){
						cont =- 1;
					}
				}
			break;
		}
		cont++;
	}
	return 0;
}

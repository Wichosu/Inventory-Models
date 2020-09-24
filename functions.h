/*ENG: Aditional file only for functions to be used in inventario.c
 ESP: Archivo adicional con funciones para usarse en el archivo inventario.c*/
#include <stdio.h>
#include <math.h>
/*ENG: Receives a value and check for the correct message to be display
  ESP: Recibe un valor y revisa que el mensaje correcta se muestre en pantalla
void messageForChosenOption(int option){
	switch(option){
		case 1: printf("\nHas seleccionado modelo de compra SIN deficit\n");
				break;
		case 2: printf("\nHas seleccionado modelo de compra CON deficit\n");
				break;
		default:printf("\nSaliendo...\n");
				break;
	}
}*/

void calculateData(double demand, double orderingCost, double maintenanceCost){
	double totalOrderingCost = 0, totalMaintenanceCost = 0, totalCost = 0, optimalQuantity = 0;
	optimalQuantity = sqrt(((2*demand*orderingCost)/maintenanceCost));
	totalOrderingCost = (demand/optimalQuantity) * orderingCost;
	totalMaintenanceCost = (optimalQuantity/2) * maintenanceCost;
	totalCost = totalOrderingCost + totalMaintenanceCost;
}

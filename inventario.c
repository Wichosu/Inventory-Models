#include <stdio.h>
#include <math.h>


int main(){
	int option = 0;
	double demand = 0, orderingCost = 0, maintenanceCost = 0, totalOrderingCost = 0, totalMaintenanceCost = 0, totalCost = 0, optimalQuantity = 0;
	do{
		printf("Proyecto Investigacion de operaciones II");
		printf("\n\nModelos de Inventario\n\nPor favor Seleccione la opcion que desee");
		printf("\n\n1.Modelo de compra SIN deficit\n2.Modelo de compra CON deficit\n\nIngrese cualquier otro numero para salir\n");
		scanf("%d", &option);
		switch(option){
			case 1: printf("\nHas seleccionado modelo de compra SIN deficit\n\nPor favor ingrese los siguentes datos:\n\n");
					printf("Demanda: ");
					scanf("%lf", &demand);
					printf("\n\nCosto por ordenar el pedido: ");
					scanf("%lf", &orderingCost);
					printf("\n\nCosto de mantener una unidad: ");
					scanf("%lf", &maintenanceCost);
					//good at this point
					optimalQuantity = sqrt(((2*demand*orderingCost)/maintenanceCost));
					totalOrderingCost = (demand/optimalQuantity) * orderingCost;
					totalMaintenanceCost = (optimalQuantity/2) * maintenanceCost;
					totalCost = totalOrderingCost + totalMaintenanceCost;
					printf("\n\nLa cantidad optima es de: %.2lf unidades por pedido", optimalQuantity);
					printf("\n\nEl costo total por ordenar un pedido es de: $%.2lf por pedido", totalOrderingCost);
					printf("\n\nEl costo total de mantenimiento es de: $%.2lf por unidad de tiempo\n\n", totalMaintenanceCost);
					break;
			case 2: printf("\nHas seleccionado modelo de compra CON deficit\n");
					break;
			default:printf("\nSaliendo...\n");
					break;
		}
	}
	while(option >= 1 && option <= 2);
	return 0;
}

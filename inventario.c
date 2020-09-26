#include <stdio.h>
#include <math.h>
#include "functions.h"

int main(){
	int option = 0;
	/*TODO: add functions, 
			Separate variables declarations in general use, case 1 use and case 2 use,
			add more details,
			check case 2 missing information,
	*/
	double demand = 0, orderingCost = 0, maintenanceCost = 0, totalOrderingCost = 0, totalMaintenanceCost = 0, totalCost = 0, optimalQuantity = 0;
	double daysWorked = 0, deliveryTerm = 0, expectNumberOfOrders = 0, expectTimeBetweenOrders = 0, orderingPoint = 0, dailyDemand =0;
	double variableCost = 0, penaltyCost = 0, averageTotalCost = 0;
	do{
		printf("Proyecto Investigacion de operaciones II");
		printf("\n\nModelos de Inventario\n\nPor favor Seleccione la opcion que desee");
		printf("\n\n1.Modelo de compra SIN deficit\n2.Modelo de compra CON deficit\n\nIngrese cualquier otro numero para salir\n");
		scanf("%d", &option);
		switch(option){
			case 1: printf("\nHas seleccionado modelo de compra SIN deficit\n\nPor favor ingrese los siguientes datos en una unidad de tiempo ANUAL:\n\n");
					printf("Demanda: ");
					scanf("%lf", &demand);
					printf("\nCosto por ordenar el pedido: ");
					scanf("%lf", &orderingCost);
					printf("\nCosto de mantener una unidad: ");
					scanf("%lf", &maintenanceCost);
					printf("\nDias laborados: ");
					scanf("%lf", &daysWorked);
					printf("\nPlazo de entrega: ");
					scanf("%lf", &deliveryTerm);
					optimalQuantity = sqrt(((2*demand*orderingCost)/maintenanceCost));
					totalOrderingCost = (demand/optimalQuantity) * orderingCost;
					totalMaintenanceCost = (optimalQuantity/2) * maintenanceCost;
					totalCost = totalOrderingCost + totalMaintenanceCost;
					expectNumberOfOrders = demand/optimalQuantity;
					expectTimeBetweenOrders =  daysWorked/expectNumberOfOrders;
					dailyDemand = demand/daysWorked;
					orderingPoint = dailyDemand * deliveryTerm; 
					printf("\n\nLa cantidad optima es de: %.2lf unidades por pedido", optimalQuantity);
					printf("\n\nEl numero esperado de pedidos anual es de: %.2lf pedidos anuales", expectNumberOfOrders);
					printf("\n\nEl tiempo esperado entre pedidos es de: %.2lf dias entre pedido", expectTimeBetweenOrders);
					printf("\n\nEl punto de pedido o reorden es de: %.2lf unidades", orderingPoint);
					printf("\n\nEl costo total por ordenar un pedido es de: $%.2lf por pedido", totalOrderingCost);
					printf("\n\nEl costo total de mantenimiento es de: $%.2lf por unidad de tiempo\n\n", totalMaintenanceCost);
					break;
			case 2: printf("\nHas seleccionado modelo de compra CON deficit\n\nPor favor ingrese los siguientes datos en una unidad de tiempo ANUAL:\n\n");
					//Demand, ordering cost and maintenance cost printf and scanf lines can be in a function to be used in case 1 and case 2
					printf("Demanda: ");
					scanf("%lf", &demand);
					printf("\nCosto por ordenar el pedido: ");
					scanf("%lf", &orderingCost);
					printf("\nCosto de mantener una unidad: ");
					scanf("%lf", &maintenanceCost);
					printf("\nCosto variable por unidad: ");
					scanf("%lf", &variableCost);
					printf("\nCosto unitario de penalizacion: ");
					scanf("%lf", &penaltyCost);
					optimalQuantity = sqrt(((2*demand*orderingCost*(penaltyCost + maintenanceCost))/(maintenanceCost*penaltyCost)));
					//totalOrderingCost, totalMaintenanceCost formulas can be in a function, also check if this values are even necessaries for this case
					//totalOrderingCost = (demand/optimalQuantity) * orderingCost;
					//totalMaintenanceCost = (optimalQuantity/2) * maintenanceCost;
					averageTotalCost = sqrt((2*demand*orderingCost*maintenanceCost*penaltyCost)/(penaltyCost + maintenanceCost));
					totalCost = averageTotalCost + variableCost;
					//some of the print messages can be in a function
					printf("\n\nLa cantidad optima es de: %.2lf unidades por pedido", optimalQuantity);
					//totalOrderingCost and totalMaintenanceCost may not be neccesary
					//printf("\n\nEl costo total por ordenar un pedido es de: $%.2lf por pedido", totalOrderingCost);
					//printf("\n\nEl costo total de mantenimiento es de: $%.2lf por unidad de tiempo", totalMaintenanceCost);
					printf("\n\nEl costo total promedio por unidad es de: $%2.lf por unidad de tiempo", averageTotalCost);
					printf("\n\nEl costo total es de: $%.2lf por unidad de tiempo\n\n", totalCost);
					break;
			default:printf("\nSaliendo...\n");
					break;
		}
	}
	while(option >= 1 && option <= 2);
	return 0;
}

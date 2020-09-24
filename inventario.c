#include <stdio.h>
#include <math.h>
#include "functions.h"

int main(){
	int option = 0;
	double demand = 0, orderingCost = 0, maintenanceCost = 0, totalOrderingCost = 0, totalMaintenanceCost = 0, totalCost = 0, optimalQuantity = 0;
	double daysWorked = 0, deliveryTerm = 0, expectNumberOfOrders = 0, expectTimeBetweenOrders = 0, orderingPoint = 0, dailyDemand =0;
	do{
		printf("Proyecto Investigacion de operaciones II");
		printf("\n\nModelos de Inventario\n\nPor favor Seleccione la opcion que desee");
		printf("\n\n1.Modelo de compra SIN deficit\n2.Modelo de compra CON deficit\n\nIngrese cualquier otro numero para salir\n");
		scanf("%d", &option);
		switch(option){
			case 1: printf("\nHas seleccionado modelo de compra SIN deficit\n\nPor favor ingrese los siguentes datos en una unidad de tiempo ANUAL:\n\n");
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
			case 2: printf("\nHas seleccionado modelo de compra CON deficit\n");
					
					break;
			default:printf("\nSaliendo...\n");
					break;
		}
	}
	while(option >= 1 && option <= 2);
	return 0;
}

#include <stdio.h>

void main ()
{
    int hs; //hours spent
    int car_rate = 2; //car rate per hour
    int bus_rate = 4; //bus rate per hour
    int truck_rate = 6; //truck rate per hour
    int parkingCharge;
    char vt; //vehicle type

    printf("enter a vehicle type (c/b/t):");
    scanf("%c", &vt);
    
    printf("number of hours spent:");
    scanf("%d", &hs); 

    if (vt == 'c'){
        parkingCharge = hs * car_rate;
    } else if (vt == 'b'){
        parkingCharge = hs * bus_rate;
    } else if (vt == 't'){
        parkingCharge = hs * truck_rate;
    }
    printf("Hours spent = %d \n", hs);
    printf("Vehicle Type = %c \n", vt);
    printf("Parking Charge = %d \n", parkingCharge);
}
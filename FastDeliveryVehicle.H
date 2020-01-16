#ifndef FASTDELIVERYVEHICLE_H_
#define FASTDELIVERYVEHICLE_H_

#include "DeliveryVehicle.H"

class FastDeliveryVehicle : public DeliveryVehicle {
public:
	
	//c'tor
	FastDeliveryVehicle(const char* ID, Quality quality);
	
	//d'tor
	~FastDeliveryVehicle();

    /*********************************************************************************
    Function name: performDeliveryDay
    Description:
    performs all possible deliveries for one day
	output example
	Starting deliveries for vehicle riksha
	Delivering parcel hot_air to position 3
	Fuel consumed: 3 Revenue is: 4
	Delivering parcel mice to position 2
	Fuel consumed: 9 Revenue is: 4
	Total travel distance is 9
	Total revenue is -4
	if no parcels present:
	No parcels to deliver for vehicle riksha
    Parameters: adds parcel to vehicle returns false if add failed
    Return value: boolean value
    **********************************************************************************/
	int performDeliveryDay(int* numberOfDeliveries);

    /*********************************************************************************
    Function name: WhatAmI
    Description: return vehicle type according to dynamic type
    Parameters: -
    Return value: VehicleType
    **********************************************************************************/
    VehicleType WhatAmI();
};
#endif /* FASTDELIVERYVEHICLE_H_ */

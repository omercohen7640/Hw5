#ifndef PROFESSIONALDELIVERYVEHICLE_H_
#define PROFESSIONALDELIVERYVEHICLE_H_

#include "DeliveryVehicle.H"
class ProfessionalDeliveryVehicle : public DeliveryVehicle{
public:
	//c'tor
	ProfessionalDeliveryVehicle(const char* ID, Quality quality);
	
	//d'tor
	~ProfessionalDeliveryVehicle();
	
	//adds parcel to vehicle returns false if add failed
    bool addParcel(Parcel *parcel, bool *deleted);

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

#endif /* PROFFESSIONALDELIVERYVEHICLE_H_ */

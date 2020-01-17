#ifndef DELIVERYVEHICLE_H_
#define DELIVERYVEHICLE_H_

#include "Parcel.H"
#include <deque>
#define PARCEL_NUM 5

typedef enum quality{good = 3, ok = 4, bad = 5} Quality;
typedef enum _result{FAIL=0, SUCCESS=1} Result;
typedef enum _vehicle_type{VEHICLE=0,FASTVEHICLE=1,PROFESSIONALVEHICLE=2} VehicleType;
using namespace std;
class DeliveryVehicle{
public:
    /*********************************************************************************
    Function name: DeliveryVehicle
    Description: constructor
    Parameters: non-parameters
    Return value: -
    **********************************************************************************/
	DeliveryVehicle();

    /*********************************************************************************
    Function name: DeliveryVehicle
    Description: constructor
    Parameters: non-parameters
    Return value: -
    **********************************************************************************/
	DeliveryVehicle(const char* ID, Quality quality);

    /*********************************************************************************
    Function name: ~DeliveryVehicle
    Description: d'tor
    Parameters: non-parameters
    Return value: -
    **********************************************************************************/
	~DeliveryVehicle();
    /*********************************************************************************
    Function name: getQuality
    Description: getter
    Parameters: non-parameters
    Return value: Quality
    **********************************************************************************/
	Quality getQuality();

    /*********************************************************************************
    Function name: getID
    Description: getter
    Parameters: non-parameters
    Return value: char*
    **********************************************************************************/
    char* getID() const;

    /*********************************************************************************
    Function name: getNext
    Description: getter
    Parameters: non-parameters
    Return value: Delivery*
    **********************************************************************************/
    DeliveryVehicle* getNext() const;

    /*********************************************************************************
    Function name: setNext
    Description: setter
    Parameters: non-parameters
    Return value: -
    **********************************************************************************/
    void setNext(DeliveryVehicle* next_vehicle);

    /*********************************************************************************
    Function name: addParcel
    Description: adds parcel to vehicle returns false if add failed
    Parameters: parcel's pointer
    Return value: boolean value
    **********************************************************************************/
    virtual bool addParcel(Parcel *parcel, bool *deleted);

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
	virtual int performDeliveryDay(int* numberOfDeliveries);


	//TODO: add virtual function- WhatAmI() - return string according to the dynamic type
    /*********************************************************************************
    Function name: WhatAmI
    Description: return vehicle type according to dynamic type
    Parameters: -
    Return value: VehicleType
    **********************************************************************************/
	virtual VehicleType WhatAmI();
protected:
    char* _vehicle_id;
    deque<Parcel*> parcel_queue;
    Quality _vehicle_quality;
    int _current_station;
    DeliveryVehicle* _next_vehicle;
};


#endif /* DELIVERYVEHICLE_H_ */

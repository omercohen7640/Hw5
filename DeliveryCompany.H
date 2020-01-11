#ifndef DELIVERYCOMPANY_H_
#define DELIVERYCOMPANY_H_
#include "DeliveryVehicle.H"
#include "DeliveryVehicleList.H"

class DeliveryCompany{
    public:
/*********************************************************************************
Function name: DeliveryCompany
Description: constructor
Parameters: money - initial fortune
Return value: None
**********************************************************************************/
	    DeliveryCompany(int money);

/*********************************************************************************
Function name: ~DeliveryCompany
Description: destructor
Parameters: None
Return value: None
**********************************************************************************/
	    ~DeliveryCompany();

/*********************************************************************************
Function name: addVehicle
Description: adds vehicle to vehicle queue
             if vehicle exists - output is:
	         "Can't add vehicle, it already exists"
Parameters: None
Return value: returns false if not possible and deletes vehicle
**********************************************************************************/
	    bool addVehicle(DeliveryVehicle* vehicle);
/*********************************************************************************
Function name: receiveParcel
Description: receives parcel if possible
Parameters: parcel - a parcel object pointer
Return value: returns false if not possible and deletes parcel
**********************************************************************************/
	    bool receiveParcel(Parcel* parcel);
/*********************************************************************************
Function name: performDeliveryDay
Description: performs all deliveries possible for one day
Parameters: None
Return value: returns false if no vehicles are present
    //output example:
	//Starting days deliveries:
	//<here comes output for each vehicle>
	//Total revenue for company is -2
	//Company balance is now 123
**********************************************************************************/
	    bool performDeliveryDay();
/*********************************************************************************
Function name: displayFunds
Description: displays company funds
Parameters: None
Return value: None
    //output example:
	//Company balance is now 148
**********************************************************************************/
	    void displayFunds();
/*********************************************************************************
Function name: displayNumberOfDeliveries
Description: displays number of deliveries company has done so far
Parameters: None
Return value: None
    //output example:
	//Till now company has delivered 3 parcels
**********************************************************************************/
	    void displayNumberOfDeliveries();

    protected:
        int funds_;
        int numberOfDeliveries_;
        DeliveryVehicleList DV_List_;
        list<DeliveryVehicle>::iterator lastReceivedAParcel_;
};

#endif /* DELIVERYCOMPANY_H_ */

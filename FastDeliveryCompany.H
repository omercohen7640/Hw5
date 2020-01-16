#ifndef FASTDELIVERYCOMPANY_H_
#define FASTDELIVERYCOMPANY_H_

#include "DeliveryCompany.H"

class FastDeliveryCompany : public DeliveryCompany{
public:
/*********************************************************************************
Function name: FastDeliveryCompany
Description: constructor
Parameters: money - initial fortune
Return value: None
**********************************************************************************/
	FastDeliveryCompany(int money);

/*********************************************************************************
Function name: ~FastDeliveryCompany
Description: destructor
Parameters: None
Return value: None
**********************************************************************************/
	~FastDeliveryCompany();

/*********************************************************************************
Function name: addVehicle
Description: adds vehicle to vehicle queue if it's of type FastDeliveryCar
             if vehicle exists - output is:
	         "Can't add vehicle, it already exists"
Parameters: None
Return value: returns false if not possible and deletes vehicle
**********************************************************************************/
	bool addVehicle(DeliveryVehicle* vehicle);

};

#endif /* FASTDELIVERYCOMPANY_H_ */

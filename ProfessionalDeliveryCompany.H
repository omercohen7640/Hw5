#ifndef PROFESSIONALDELIVERYCOMPANY_H_
#define PROFESSIONALDELIVERYCOMPANY_H_

#include "DeliveryCompany.H"

class ProfessionalDeliveryCompany : public DeliveryCompany{
public:
/*********************************************************************************
Function name: 	ProfessionalDeliveryCompany
Description: constructor
Parameters: money - initial fortune
Return value: None
**********************************************************************************/
	ProfessionalDeliveryCompany(int money);

/*********************************************************************************
Function name: ~ProfessionalDeliveryCompany
Description: destructor
Parameters: None
Return value: None
**********************************************************************************/
	~ProfessionalDeliveryCompany();

/*********************************************************************************
Function name: addVehicle
Description: adds vehicle to vehicle queue if it's of type ProfessionalDeliveryCar
             if vehicle exists - output is:
	         "Can't add vehicle, it already exists"
Parameters: None
Return value: returns false if not possible and deletes vehicle
**********************************************************************************/
	bool addVehicle(DeliveryVehicle* vehicle);
};

#endif /* PROFESSIONALDELIVERYCOMPANY_H_ */

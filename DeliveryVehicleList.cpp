//
// Created by amitm on 11/01/2020.
//

#include "DeliveryVehicleList.h"

/*********************************************************************************
Function name: DeliveryVehicleList
Description: constructor
Parameters: <> //TODO: complete
Return value: Result - None
**********************************************************************************/
DeliveryVehicleList();
/*********************************************************************************
Function name: ~DeliveryVehicleList
Description: destructor
Parameters: None
Return value: None
**********************************************************************************/
~DeliveryVehicleList();
/*********************************************************************************
Function name: pushVehicle
Description: add a new vehicle to the queue
Parameters: DV - a pointer to vehicle object
Return value: Result - SUCCESS if added, else FAIL
**********************************************************************************/
Result pushVehicle (DeliveryVehicle *DV);
/*********************************************************************************
Function name: popVehicle
Description: remove a vehicle from the queue
Parameters: DV - a pointer to vehicle object
Return value: Result - SUCCESS if removed, else FAIL
**********************************************************************************/
Result popVehicle (DeliveryVehicle *DV);
/*********************************************************************************
Function name: getQlen
Description: returns the length of the queue
Parameters: DV - None
Return value: int - the length of the queue
**********************************************************************************/
int getQlen();
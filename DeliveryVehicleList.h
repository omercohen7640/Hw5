//
// Created by amitm on 11/01/2020.
//

#ifndef HW5_DELIVERYVEHICLELIST_H
#define HW5_DELIVERYVEHICLELIST_H

#include "DeliveryVehicle.H"
#include <list>

class DeliveryVehicleList {

    public:
/*********************************************************************************
Function name: DeliveryVehicleList
Description: constructor
Parameters: None
Return value: None
**********************************************************************************/
        DeliveryVehicleList();
/*********************************************************************************
Function name: ~DeliveryVehicleList
Description: destructor
Parameters: None
Return value: None
**********************************************************************************/
        virtual ~DeliveryVehicleList();
/*********************************************************************************
Function name: pushVehicle
Description: add a new vehicle to the queue
Parameters: DV - a pointer to vehicle object
Return value: Result - SUCCESS if added, else FAIL
**********************************************************************************/
        Result pushVehicle (DeliveryVehicle* const DV);
/*********************************************************************************
Function name: getTopVehicle
Description: returns an iterator pointing to the first vehicle on the list
Parameters: None
Return value: list<DeliveryVehicle>::iterator - an iterator
**********************************************************************************/
        list<DeliveryVehicle*>::iterator getTopVehicle();
/*********************************************************************************
Function name: getBottomVehicle
Description: returns an iterator pointing to the last vehicle on the list
Parameters: None
Return value: list<DeliveryVehicle>::iterator - an iterator
**********************************************************************************/
        list<DeliveryVehicle*>::iterator getBottomVehicle();
/*********************************************************************************
Function name: isEmpty
Description: returns whether the list is empty or not
Parameters: None
Return value: bool - true if empty, else false
**********************************************************************************/
        bool isEmpty();
/*********************************************************************************
Function name: listSize
Description: returns the size of the list
Parameters: None
Return value: int - size of list
**********************************************************************************/
        int listSize();

    protected:
        list<DeliveryVehicle*> DV_List_;

};


#endif //HW5_DELIVERYVEHICLELIST_H

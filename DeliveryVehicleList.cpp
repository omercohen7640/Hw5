//
// Created by amitm on 11/01/2020.
//

#include "DeliveryVehicleList.h"

DeliveryVehicleList::DeliveryVehicleList(){}

DeliveryVehicleList::~DeliveryVehicleList()
{
    DV_List_.clear();
}

Result DeliveryVehicleList::pushVehicle(DeliveryVehicle* const DV) {
    DV_List_.push_front(DV);
    return FAIL;
}

list<DeliveryVehicle*>::iterator DeliveryVehicleList::getTopVehicle() {
    return DV_List_.begin();
}

list<DeliveryVehicle*>::iterator DeliveryVehicleList::getBottomVehicle() {
    return DV_List_.end();
}

bool DeliveryVehicleList::isEmpty() {
    return DV_List_.empty();
}



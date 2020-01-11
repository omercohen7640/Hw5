//
// Created by amitm on 11/01/2020.
//
#include "DeliveryVehicle.H"

DeliveryVehicle(){}


DeliveryVehicle::DeliveryVehicle() {}

DeliveryVehicle::DeliveryVehicle(const char *ID, Quality quality): _vehicle_quality(quality) {
    strcpy(_vehicle_id,ID);
}

DeliveryVehicle::~DeliveryVehicle() {
    delete _vehicle_id;
    dele
}




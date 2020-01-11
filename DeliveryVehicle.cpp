//
// Created by amitm on 11/01/2020.
//
#include "DeliveryVehicle.H"

DeliveryVehicle::DeliveryVehicle() {
    _next_vehicle = NULL;
}

DeliveryVehicle::DeliveryVehicle(const char *ID, Quality quality): _vehicle_quality(quality) {
    strcpy(_vehicle_id,ID);
    _next_vehicle = NULL;
}

DeliveryVehicle::~DeliveryVehicle() {
    delete _vehicle_id;
}

Quality DeliveryVehicle::getQuality() {
    return _vehicle_quality;
}

char *DeliveryVehicle::getID() const {
    return _vehicle_id;
}

DeliveryVehicle *DeliveryVehicle::getNext() const {
    return _next_vehicle;
}

void DeliveryVehicle::setNext(DeliveryVehicle *next_vehicle) {
    _next_vehicle = next_vehicle;
}

int DeliveryVehicle::performDeliveryDay(int *numberOfDeliveries) {

}









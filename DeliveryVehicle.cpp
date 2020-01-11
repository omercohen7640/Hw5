//
// Created by amitm on 11/01/2020.
//
#include "DeliveryVehicle.H"

DeliveryVehicle::DeliveryVehicle() {
    for (int i = 0; i < PARCEL_NUM; ++i) {
        parcel_arrey[i] = NULL;
    }
    _next_vehicle = NULL;
}

DeliveryVehicle::DeliveryVehicle(const char *ID, Quality quality): _vehicle_quality(quality) {
    strcpy(_vehicle_id,ID);
    for (int i = 0; i < PARCEL_NUM; ++i) {
        parcel_arrey[i] = NULL;
    }
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

bool DeliveryVehicle::addParcel(Parcel *parcel) {
    for (int i = 0; i < PARCEL_NUM; ++i) {
        if (parcel_arrey[i]->getDest() == -1){
            parcel_arrey[i] = parcel;
            return true;
        }
    }
    return false;
}

int DeliveryVehicle::performDeliveryDay(int *numberOfDeliveries) {

}










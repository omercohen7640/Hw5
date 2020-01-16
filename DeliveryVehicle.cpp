//
// Created by amitm on 11/01/2020.
//
#include "DeliveryVehicle.H"

DeliveryVehicle::DeliveryVehicle() {
    _next_vehicle = NULL;
}

DeliveryVehicle::DeliveryVehicle(const char *ID, Quality quality): _vehicle_quality(quality), _current_station(0) {
    _vehicle_id = new char [strlen(ID) +1 ];
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

bool DeliveryVehicle::addParcel(Parcel *parcel) {
     if (parcel_queue.size() == PARCEL_NUM) return false;
     deque<Parcel*>::iterator i;
     i = parcel_queue.begin();
    while (i != parcel_queue.end())
    {
        if (strcmp((**i).getID(),parcel->getID()) == 0){
            delete parcel;
            return false;
        }
        i++;
    }
     parcel_queue.push_back(parcel);
     return true;
}

int DeliveryVehicle::performDeliveryDay(int *numberOfDeliveries) {
    if (!parcel_queue.empty()){
        cout << "No parcels to deliver for vehicle " << _vehicle_id << endl;
        *numberOfDeliveries = 0;
        return 0;
    }
    cout << "Starting deliveries for vehicle" << _vehicle_id << endl;
    int station_counter = 0;
    int distance;
    int delivery_counter=0;
    int total_revenue;
    int next_station;
    while (!parcel_queue.empty()){
        next_station = parcel_queue.front()->getDest();
        if (next_station >= _current_station)
            distance = next_station-_current_station;
        else
            distance = 10-_current_station + next_station;
        if (station_counter + distance > 12)
        {
            *numberOfDeliveries = delivery_counter;
            total_revenue= 4*delivery_counter - _vehicle_quality -station_counter;
            cout << "Total revenue is " << total_revenue;
            return total_revenue;
        }

        station_counter+= distance;
        delivery_counter++;

        cout << "Delivering parcel " << parcel_queue.front()->getID() << " to position " << next_station << endl;
        cout << "Fuel consumed: " << distance << " Revenue is: 4";
        parcel_queue.pop_front();
    }
    *numberOfDeliveries = station_counter;
    total_revenue= 4*delivery_counter - _vehicle_quality -station_counter;
    cout << "Total revenue is " << total_revenue;
    return total_revenue;
}

VehicleType DeliveryVehicle::WhatAmI() {
    return VEHICLE;
}










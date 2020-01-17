//
// Created by amitm on 11/01/2020.
//

#include "FastDeliveryVehicle.H"

FastDeliveryVehicle::FastDeliveryVehicle(const char *ID, Quality quality ) : DeliveryVehicle(ID,
        quality){

}

FastDeliveryVehicle::~FastDeliveryVehicle() {

}


int FastDeliveryVehicle::performDeliveryDay(int *numberOfDeliveries) {
    if (parcel_queue.empty()){
        cout << "No parcels to deliver for vehicle " << _vehicle_id << endl;
        *numberOfDeliveries = 0;
        return 0;
    }
    cout << "Starting deliveries for vehicle " << _vehicle_id << endl;
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
            break;
            /*
            *numberOfDeliveries = delivery_counter;
            total_revenue= station_counter - _vehicle_quality -station_counter;
            cout << "Total revenue is " << total_revenue << endl;
            return total_revenue;
             */
        }
        _current_station = next_station;

        station_counter+= distance;
        delivery_counter++;

        cout << "Delivering parcel " << parcel_queue.front()->getID() << " to position " << next_station << endl;
        cout << "Fuel consumed: " << distance << " Revenue is: " << distance*2 << endl;
        parcel_queue.pop_front();
    }
    *numberOfDeliveries = delivery_counter;
    total_revenue= station_counter - _vehicle_quality ;
    cout << "Total travel distance is " << station_counter << endl;
    cout << "Total revenue is " << total_revenue << endl;
    return total_revenue;
}

VehicleType FastDeliveryVehicle::WhatAmI() {
    return FASTVEHICLE;
}


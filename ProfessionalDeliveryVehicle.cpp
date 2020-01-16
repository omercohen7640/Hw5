//
// Created by amitm on 11/01/2020.
//

#include "ProfessionalDeliveryVehicle.H"

ProfessionalDeliveryVehicle::ProfessionalDeliveryVehicle(const char *ID, Quality quality) : DeliveryVehicle(ID,
                                                                                                            quality) {

}

ProfessionalDeliveryVehicle::~ProfessionalDeliveryVehicle() {

}

int ProfessionalDeliveryVehicle::performDeliveryDay(int *numberOfDeliveries) {
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
            total_revenue= station_counter - _vehicle_quality -station_counter;
            cout << "Total revenue is " << total_revenue;
            return total_revenue;
        }

        station_counter+= distance;
        delivery_counter++;

        cout << "Delivering parcel " << parcel_queue.front()->getID() << " to position " << next_station << endl;
        cout << "Fuel consumed: " << distance << " Revenue is: " << distance*2 <<endl;
        parcel_queue.pop_front();
    }
    *numberOfDeliveries = station_counter;
    total_revenue= station_counter - _vehicle_quality ;
    cout << "Total revenue is " << total_revenue << endl;
    if (delivery_counter == 0)
        cout << "Revenue per parcel: no parcels" << endl;
    else
        cout << "Revenue per parcel: " << total_revenue/delivery_counter;
    if (station_counter == 0) {
        cout << "Revenue per distance: no distance" << endl;
    }else{
        cout << "Revenue per distance: " << total_revenue / station_counter << endl;
    }
    return total_revenue;
}

bool ProfessionalDeliveryVehicle::addParcel(Parcel *parcel) {
    int dest = parcel_queue.back()->getDest();
    int source = parcel->getDest();
    if (dest >= source && (dest-source) <= 4) {
        return DeliveryVehicle::addParcel(parcel);
    }
    if (dest < source && (10 - source + dest) <= 4 ){
        return DeliveryVehicle::addParcel(parcel);
    }
    return false;
}

VehicleType ProfessionalDeliveryVehicle::WhatAmI() {
    return PROFESSIONALVEHICLE;
}




//
// Created by amitm on 11/01/2020.
//

#include "FastDeliveryCompany.H"

FastDeliveryCompany::FastDeliveryCompany(int money) : DeliveryCompany(money) {}

//TODO: no implementation needed???
FastDeliveryCompany::~FastDeliveryCompany() {}

bool FastDeliveryCompany::addVehicle(DeliveryVehicle *vehicle) {

    return DeliveryCompany::addVehicle(vehicle);
}




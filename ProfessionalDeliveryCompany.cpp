//
// Created by amitm on 11/01/2020.
//

#include "ProfessionalDeliveryCompany.H"

ProfessionalDeliveryCompany::ProfessionalDeliveryCompany(int money) : DeliveryCompany(money) {}

ProfessionalDeliveryCompany::~ProfessionalDeliveryCompany() {}

bool ProfessionalDeliveryCompany::addVehicle(DeliveryVehicle *vehicle) {
    if (vehicle->WhatAmI() != PROFESSIONALVEHICLE) return false;
    else {
        if (DeliveryCompany::addVehicle(vehicle) == false) return false;
    }
    return true;
}




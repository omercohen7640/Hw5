//
// Created by amitm on 11/01/2020.
//

#include "DeliveryCompany.H"

DeliveryCompany::DeliveryCompany(int money) : initFortune_(money), lastReceivedAParcel_(DV_List_.getTopVehicle()){}

DeliveryCompany::~DeliveryCompany() {}

bool DeliveryCompany::addVehicle(DeliveryVehicle *vehicle) {
    if (DV_List_.pushVehicle(*vehicle) == SUCCESS) return true;
    return false;
}

bool DeliveryCompany::receiveParcel(Parcel *parcel) {
        list<DeliveryVehicle>::iterator current;
        bool flag_parcelAdded;
        if (DV_List_.isEmpty()) return false;
        else
        {
            if (lastReceivedAParcel_ == DV_List_.getBottomVehicle())
            {
                current = DV_List_.getTopVehicle();
                flag_parcelAdded = (*current).addParcel(parcel);
                while (flag_parcelAdded == false)
                {
                    ++current;
                    flag_parcelAdded = (*current).addParcel(parcel);
                    if (current == lastReceivedAParcel_) return false;
                }
            }
        }
    return false;
}


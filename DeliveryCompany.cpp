//
// Created by amitm on 11/01/2020.
//

#include "DeliveryCompany.H"

DeliveryCompany::DeliveryCompany(int money) : balance_(money), revenue_(0), lastReceivedAParcel_(DV_List_.getTopVehicle()), numberOfDeliveries_(0){}

DeliveryCompany::~DeliveryCompany() {}

bool DeliveryCompany::addVehicle(DeliveryVehicle *vehicle) {
    if (DV_List_.pushVehicle(*vehicle) == SUCCESS) return true;
    return false;
}

bool DeliveryCompany::receiveParcel(Parcel *parcel) {
        list<DeliveryVehicle>::iterator current;
        bool flag_parcelAdded;
        if (DV_List_.isEmpty()) return false;

        current = lastReceivedAParcel_;
        if (current == DV_List_.getBottomVehicle())
        {
            current = DV_List_.getTopVehicle();
            flag_parcelAdded = (*current).addParcel(parcel);
            if (flag_parcelAdded == true) return true;
        }
        ++current;
        while (current != lastReceivedAParcel_)
        {
            if (current != DV_List_.getBottomVehicle())
            {
                ++current;
                flag_parcelAdded = (*current).addParcel(parcel);
                if (flag_parcelAdded == true) return true;
            }
            else
            {
                current = DV_List_.getTopVehicle();
                flag_parcelAdded = (*current).addParcel(parcel);
                if (flag_parcelAdded == true) return true;
            }
        }
    return false;
}

bool DeliveryCompany::performDeliveryDay() {
    if (DV_List_.isEmpty() == true) return false;
    cout << "Starting days deliveries:" << endl;
    list<DeliveryVehicle>::iterator it;
    revenue_ = 0;
    for (it = DV_List_.getTopVehicle(); it != DV_List_.getBottomVehicle() ; ++it)
    {
        int numberOfDeliveries = 0;
        revenue_ += (*it).performDeliveryDay(&numberOfDeliveries);
        numberOfDeliveries_ += numberOfDeliveries;
    }
    cout << "Total revenue for company is " << revenue_ << endl;
    displayFunds();
    displayNumberOfDeliveries();
    return true;
}

void DeliveryCompany::displayFunds() {
    cout << "Company balance is now " << balance_ << endl;
}

void DeliveryCompany::displayNumberOfDeliveries() {
    cout << "Till now company has delivered " << numberOfDeliveries_ << " parcels" << endl;
}


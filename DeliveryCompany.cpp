//
// Created by amitm on 11/01/2020.
//

#include "DeliveryCompany.H"

DeliveryCompany::DeliveryCompany(int money) : balance_(money), revenue_(0), numberOfDeliveries_(0), lastReceivedAParcel_(DV_List_.getBottomVehicle()){}

DeliveryCompany::~DeliveryCompany(){}

bool DeliveryCompany::addVehicle(DeliveryVehicle *vehicle) {
    list<DeliveryVehicle*>::iterator current;
    current = DV_List_.getTopVehicle();
    while (current != DV_List_.getBottomVehicle())
    {
        if (vehicle->getID() == (*current)->getID())
        {
            delete vehicle;
            return false;
        }
        ++current;
    }
    if (DV_List_.pushVehicle(vehicle) == SUCCESS) return true;
    return false;
}

bool DeliveryCompany::receiveParcel(Parcel *parcel) {
    if (DV_List_.isEmpty()) return false;
    list<DeliveryVehicle *>::iterator current; //current is a pointer to pointer, because an iterator is a pointer to an element, and the elements in this list are pointers

    bool flag_parcelAdded;
    bool deleted = false;

    current = lastReceivedAParcel_;

    //increment current to the object after lastReceiveParcel
    lastReceivedAParcel_increment(current);

//    cout << "last received parcel: "  << (**lastReceivedAParcel_).getID() << endl;
    // cout << "current: "  << (**current).getID() << endl;
    for (int i = 0; i < DV_List_.listSize(); ++i) {
        //try to add parcel
        flag_parcelAdded = (**current).addParcel(parcel, &deleted);

        //if parcel added successfully then change lastReceivedAParcel_ to this vehicle and end function
        if (flag_parcelAdded == true) {
            lastReceivedAParcel_ = current;
            return true;
        }

        //if parcel wasn't added to vehicle and parcel was deleted then end function
        if (deleted == true) return false;

        //if parcel wasn't added to vehicle but still exists, try to find another vehicle
        lastReceivedAParcel_increment(current); //function does ++current
        //cout << "last received parcel: "  << (**lastReceivedAParcel_).getID() << endl;
        //cout << "current: "  << (**current).getID() << endl;
    }

    delete parcel;
    return false;
}

bool DeliveryCompany::performDeliveryDay() {
    if (DV_List_.isEmpty() == true) return false;
    cout << "Starting days deliveries:" << endl;
    list<DeliveryVehicle*>::iterator it;
    revenue_ = 0;
    for (it = DV_List_.getTopVehicle(); it != DV_List_.getBottomVehicle() ; ++it)
    {
        int numberOfDeliveries = 0;
        revenue_ += (**it).performDeliveryDay(&numberOfDeliveries);
        numberOfDeliveries_ += numberOfDeliveries;
    }
    cout << "Total revenue for company is " << revenue_ << endl;
    balance_ += revenue_;
    return true;
}

void DeliveryCompany::displayFunds() {
    cout << "Company balance is now " << balance_ << endl;
}

void DeliveryCompany::displayNumberOfDeliveries() {
    cout << "Till now company has delivered " << numberOfDeliveries_ << " parcels" << endl;
}

void DeliveryCompany::lastReceivedAParcel_increment(list<DeliveryVehicle *>::iterator &current) {
    if (++current == DV_List_.getBottomVehicle()) {
        current = DV_List_.getTopVehicle();
    }
}



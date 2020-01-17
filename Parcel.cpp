//
// Created by amitm on 11/01/2020.
//

#include "Parcel.H"

Parcel::Parcel(const char *ID , int dest ): _dest(dest) {
    _id = new char [strlen(ID) + 1 ];
    strcpy(_id,ID);
}

Parcel::~Parcel() {
    delete[] _id;
}

int Parcel::getDest() const{
    return _dest;
}

char* Parcel::getID() const{
    return _id;
}

Parcel::Parcel(const Parcel &parcel): _dest(parcel.getDest()) {
    _id = new char [strlen(parcel.getID()) + 1 ];
    strcpy(_id,parcel.getID());
}

Parcel& Parcel::operator=(const Parcel& parcel_to_copy) {
    if (this != &parcel_to_copy) {
        _dest = parcel_to_copy.getDest();
        delete _id;
        strcpy(_id, parcel_to_copy.getID());
    }
    return *this;
}







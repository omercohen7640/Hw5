//
// Created by amitm on 11/01/2020.
//

#include "Parcel.H"

Parcel::Parcel(const char *ID , int dest ): _dest(dest) {
    strcpy(_id,ID);
}

Parcel::~Parcel() {
    delete _id;
}

int Parcel::getDest(){
    return _dest;
}

char* Parcel::getID() {
    return _id;
}







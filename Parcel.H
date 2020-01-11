#ifndef PARCEL_H_
#define PARCEL_H_
#include <string.h>

class Parcel{
public:
    /*********************************************************************************
    Function name: Parcel
    Description: adds parcel to vehicle returns false if add failed
    Parameters: parcel's pointer
    Return value: boolean value
    **********************************************************************************/
	Parcel(const char* ID ="", int dest = -1);

    /*********************************************************************************
    Function name: ~Parcel
    Description: d'tor
    Parameters: -
    Return value: -
    **********************************************************************************/
	~Parcel();

    /*********************************************************************************
    Function name: getDest
    Description: getter
    Parameters: -
    Return value: int
    **********************************************************************************/
    int getDest();

    /*********************************************************************************
    Function name: getID
    Description: getter
    Parameters: -
    Return value: char*
    **********************************************************************************/
    char* getID();

protected:
    char* _id;
    int _dest;
};

#endif /* PARCEL_H_ */

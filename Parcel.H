#ifndef PARCEL_H_
#define PARCEL_H_
#include <string.h>



class Parcel{
public:
    /*********************************************************************************
    Function name: Parcel
    Description: c'tor
    Parameters:
    ID - pacel id
    dest - parcel destenetion
    Return value: -
    **********************************************************************************/
	Parcel(const char* ID ="", int dest = -1);


    /*********************************************************************************
    Function name: Parcel
    Description: copy c'tor
    Parameters: parcel's pointer
    Return value: -
    **********************************************************************************/
    Parcel(const Parcel& parcel);

    /*********************************************************************************
    Function name: = overload
    Description: -
    Parameters: parcel's pointer
    Return value: -
    **********************************************************************************/
    Parcel& operator=(const Parcel& parcel_to_copy);

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
    int getDest() const;

    /*********************************************************************************
    Function name: getID
    Description: getter
    Parameters: -
    Return value: char*
    **********************************************************************************/
    char* getID() const;

protected:
    char* _id;
    int _dest;
};

#endif /* PARCEL_H_ */

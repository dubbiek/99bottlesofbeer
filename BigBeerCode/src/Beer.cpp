//Beer.cpp

#include "Beer.hpp"


//Beer()
//Constructor that populates all fields of the Beer object with default values.
//It is possible that this constructor could be changed to generate random Beer
//objects.
Beer::Beer()
{
	//Set member variable to a default value, preceded by >> because why the hell not
	//This could later be replaced by random number, name, brewer, and activity generation
	//if desired.
	setBeerNumber(">>NONUMBER");
	setBeerName(">>NONAME");
	setBeerBrewer(">>NOBREWER");
	setBeerActivity(">>NOACTIVITY");
}


//Beer(string,string,string,bool)
//Constructor that populates all fields of the
//Beer object.
Beer::Beer(string number, string name, string brewer, string activity)
{
	//Set member variables as specified by the inputs to the constructor.
	setBeerNumber(number);
	setBeerName(name);
	setBeerBrewer(brewer);
	setBeerActivity(activity);
}


//Destructor
//Doesn't really do anything special. How exciting.
Beer::~Beer()
{

}//~Beer


/*********
Accessors
*********/


//getBeerNumber()
//Accessor for beerNumber
string Beer::getBeerNumber()
{
	return beerNumber;
}//getBeerNumber


//getBeerName()
//Accessor for beerName
string Beer::getBeerName()
{
	return beerName;
}//getBeerName


//getBeerBrewer()
//Accessor for beerBrewer
string Beer::getBeerBrewer()
{
	return beerBrewer;
}//getBeerBrewer


//getBeerActive()
//Accessor for beerActive
bool Beer::getBeerActivity()
{
	return beerActivity;
}//getBeerActivity

/****************************************************
Mutators
Used by the constructor and for testing only;
these fields should be populated by the constructor.
****************************************************/


//setBeerNumber(string)
//Sets the beerNumber
void Beer::setBeerNumber(string newNumber)
{
	beerNumber = newNumber;
}//setBeerNumber


//setBeerName(string)
//Sets the beerName
void Beer::setBeerName(string newName)
{
	beerName = newName;
}//setBeerName


//setBeerBrewer(string)
//Sets the beerBrewer
void Beer::setBeerBrewer(string newBrewer)
{
	beerBrewer = newBrewer;
}//setBeerBrewer


//setBeerActivity(bool)
//Sets the beerActivity
bool Beer::setBeerActivity(string newActivity)
{
    bool flag = false;
    if (newActivity[0] == 'Y')
        flag = true;
    return flag;
}//setBeerActivity

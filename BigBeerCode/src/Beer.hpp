//Beer.hpp

#ifndef BEER_HPP_
#define BEER_HPP_


using namespace std;

class Beer
{
	private:
		string beerNumber; //Pete's unique beer number
		string beerName; //The name of the beer
		string beerBrewer; //The brewer of the beer
		bool beerActivity; //Whether beer is currently active


	public:
		//Default constructor
		Beer();
		//Constructor that populates all fields of the
		//Beer object.
		Beer(string, string, string, bool);

		//Destructor
		virtual ~Beer();


		//Accessors
		string getBeerNumber();
		string getBeerName();
		string getBeerBrewer();
		bool getBeerActivity();


		//Mutators
		//Used by the constructor and for testing only;
		//these fields should be populated by the constructor.
		void setBeerNumber(string);
		void setBeerName(string);
		void setBeerBrewer(string);
		void setBeerActivity(bool);

};

#endif /* BEER_HPP_ */

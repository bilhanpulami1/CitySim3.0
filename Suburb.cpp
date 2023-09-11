#include "Suburb.h"
#include <iostream>
#include <cstdlib> // For rand()

Suburb::Suburb()
{
    suburbName = "";
    suburbID = 0;
    suburbPopulation = 0;
    populationWorker = 0;
    populationTeacher = 0;
    populationArtist = 0;
    suburbType = e_SuburbType::e_Mainland; // You can change the default value if needed
    vector<int> suburbNeighbours = {};
    suburbFerry = false;     // You can change the default value if needed
    hasDisaster = false;
}

Suburb::Suburb(string name, int id, int worker, int artist, int teacher, e_SuburbType type, vector<int> neighbours, bool ferry)
	: suburbName(name)
	, suburbID(id)
	, suburbPopulation(worker + artist + teacher) // Set the total population here
	, populationWorker(worker)
	, populationTeacher(teacher)
	, populationArtist(artist)
	, suburbType(type)
	, suburbNeighbours(neighbours)
	, suburbFerry(ferry)
	, hasDisaster(false)
{
}

Suburb::~Suburb()
{
}

void Suburb::DisplaySuburbInformation() const
{
	system("cls");
	cout << "Suburb Name: " << suburbName << endl;
	//cout << "No. of Workers: " << suburb.populationWorker << endl;
	//cout << "No. of Teachers: " << suburb.populationArtist << endl;
	//cout << "No. of Artists: " << suburb.populationTeacher << endl;
	cout << "Original Population: " << populationWorker + populationArtist + populationTeacher << endl;
	cout << "Access to Ferry: ";
	if (suburbFerry == true)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}

	cout << "Suburb Area: "; //whether type is coastal, island or mainland
	if (suburbType == e_SuburbType::e_Coastal)
	{
		cout << "Coastal" << endl;
	}
	else if (suburbType == e_SuburbType::e_Island)
	{
		cout << "Island" << endl;
	}
	else
	{
		cout << "Mainland" << endl;
	}
}

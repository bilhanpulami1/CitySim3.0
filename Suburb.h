#pragma once
#include "Disaster.h"

#include <string>
#include <vector>

using namespace std;

enum class e_SuburbType { e_Mainland, e_Island, e_Coastal };

class Suburb
{
//member variables
public:
    string suburbName;
    int suburbID;
    int suburbPopulation;
    int populationWorker;
    int populationArtist;
    int populationTeacher;
    e_SuburbType suburbType;
    vector<int> suburbNeighbours;
    bool suburbFerry;
    bool hasDisaster;
    Disaster disaster;

//constructors
    Suburb();
    Suburb(string name, int id, int worker, int artist, int teacher, e_SuburbType type, vector<int> neighbours, bool ferry);

//desctructors
    ~Suburb();

//member functions
    void DisplaySuburbInformation() const;

};

//make an instance for the function above and etc. SuburbInformationSelection
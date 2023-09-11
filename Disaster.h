#pragma once

#include <string>
using namespace std;

enum e_Disasters { e_hurricane, e_flood, e_earthquake, e_forestFire, e_tsunami, e_lizardPeople };

class Disaster
{
//member variables
public:
	string m_name;
	int m_damagePercent;

	//constructors
	Disaster();
	Disaster(string name, int damagePercent);

	//destructors
	~Disaster();
	
};


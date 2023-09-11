#include <iostream>
#include <string>
#include <time.h>
#include <vector>
#include "Disaster.h"
#include "Suburb.h"

using namespace std;

void SuburbInformationSelection();
void SHIPASCII();
void TRAINASCII();
void WELCOMEASCII();
void Transport(Suburb& transport1, Suburb& transport2);

int g_suburbSelectionInput;
int g_choice1;
int g_choice2;

Suburb suburb1("Pallet", 1, 1 + (rand() % 1000), 1 + (rand() % 1000), 1 + (rand() % 1000), e_SuburbType::e_Coastal, { 2, 3, 4, 5, 8 }, true);
Suburb suburb2("Viridian", 2, 1 + (rand() % 1000), 1 + (rand() % 1000), 1 + (rand() % 1000), e_SuburbType::e_Coastal, { 1, 3, 6, 8 }, true);
Suburb suburb3("Pewter", 3, 1 + (rand() % 1000), 1 + (rand() % 1000), 1 + (rand() % 1000), e_SuburbType::e_Mainland, { 1, 2, 4, 6 }, false);
Suburb suburb4("Cerulean", 4, 1 + (rand() % 1000), 1 + (rand() % 1000), 1 + (rand() % 1000), e_SuburbType::e_Mainland, { 1, 3, 5, 6 }, false);
Suburb suburb5("Vermilion", 5, 1 + (rand() % 1000), 1 + (rand() % 1000), 1 + (rand() % 1000), e_SuburbType::e_Mainland, { 1, 4, 6, 7 }, false);
Suburb suburb6("Lavender", 6, 1 + (rand() % 1000), 1 + (rand() % 1000), 1 + (rand() % 1000), e_SuburbType::e_Coastal, { 2, 3, 4, 5, 8 }, true);
Suburb suburb7("Fuschia", 7, 1 + (rand() % 1000), 1 + (rand() % 1000), 1 + (rand() % 1000), e_SuburbType::e_Mainland, { 5 }, false);
Suburb suburb8("Cinnabar", 8, 1 + (rand() % 1000), 1 + (rand() % 1000), 1 + (rand() % 1000), e_SuburbType::e_Island, { 1, 2, 6 }, true);
Suburb InvalidSuburb("Invalid Suburb", -1, 0, 0, 0, e_SuburbType::e_Mainland, {}, false);
Suburb suburbArray[8];

int main()
{
	srand(static_cast<unsigned int>(time(0)));
	int turnCounter = 0;

	suburbArray[0] = suburb1; //assign populated suburbs to indexes
	suburbArray[1] = suburb2;
	suburbArray[2] = suburb3;
	suburbArray[3] = suburb4;
	suburbArray[4] = suburb5;
	suburbArray[5] = suburb6;
	suburbArray[6] = suburb7;
	suburbArray[7] = suburb8;

	Disaster hurricane("Hurricane", 30);
	Disaster flood("Flood", 20);
	Disaster earthquake("Earthquake", 70);
	Disaster forestFire("Forest Fire", 40);
	Disaster tsunami("Tsunami", 80);
	Disaster lizardPeople("Lizard People Invasion", 100);

	cout << "Are you ready?" << endl; //WELCOME!!
	system("pause");
	system("cls");
	WELCOMEASCII();
	system("pause");
	bool cityLoop = true; //start of simulation loop

	int random = rand();

	while (cityLoop)
	{
		turnCounter++; //adds to turn counter
		system("cls");
		cout << "Turn " << turnCounter << endl;
		cout << "Seed = " << time(0) << endl; //randomiser debugging
		cout << "Random number = " << random << endl; //randomiser debugging
		cout << "What would you like to do?" << endl; //menu and options
		cout << "1) View Original Suburb Stats" << endl;
		cout << "2) Test your luck and transport people" << endl;
		cout << "3) Quit" << endl;

		int startMenuSelection;
		cin >> startMenuSelection;

		//handle user choices
		if (startMenuSelection == 1) //view suburb stats (need to fix, currently only shows original stats)
		{
			bool tempLoop = true;

			while (tempLoop)
			{
				cout << "\nWe have 8 Suburbs in this city" << endl;
				cout << "Which Suburb would you like to view?: " << endl;
				cout << "1) Pallet" << endl;
				cout << "2) Viridian" << endl;
				cout << "3) Pewter" << endl;
				cout << "4) Cerulean" << endl;
				cout << "5) Vermilion" << endl;
				cout << "6) Lavender" << endl;
				cout << "7) Fuschia" << endl;
				cout << "8) Cinnabar" << endl;

				cin >> g_suburbSelectionInput;

				SuburbInformationSelection();

				cout << "\nWould you like to view another Suburb?" << endl;
				cout << "1) Yes" << endl;
				cout << "2) No" << endl;
				int inMenuSelection;
				cin >> inMenuSelection;

				if (inMenuSelection == 1)
				{
					tempLoop = true;
				}
				else
				{
					tempLoop = false;
				}
			}
			system("pause");
		}
		else if (startMenuSelection == 2) //tranporting people, sets flag for disasters to occur between each turn
		{
			cout << "Be careful, disaster may strike..." << endl;

			cout << "\nPopulation of all suburbs before transport:" << endl;
			for (int i = 0; i < 8; ++i)
			{
				cout << i + 1 << ") " << suburbArray[i].suburbName << ": " << suburbArray[i].suburbPopulation << endl;
			}

			cout << "Please enter a Suburb to transport people from (1-8): ";
			cin >> g_choice1;
			cout << endl;
			cout << "And a Suburb to transport people to (1-8): ";
			cin >> g_choice2;

			if (g_choice1 >= 1 && g_choice1 <= 8 && g_choice2 >= 1 && g_choice2 <= 8 && g_choice1 != g_choice2) {
				// Perform the transportation here
				Transport(suburbArray[g_choice1 - 1], suburbArray[g_choice2 - 1]);
			}
			else {
				cout << "Invalid suburb selection. Transportation aborted." << endl;
			}

			if (rand() % 100 < 70)  // 70% chance of disaster
			{
				int randomSuburbIndex = rand() % 8; // Choose a random suburb index
				Suburb& randomSuburb = suburbArray[randomSuburbIndex];

				//generate random disaster type
				int randomDisasterType = rand() % 6; // +1 because enums start from 0
				Disaster randomDisaster;

				//assign disaster based on random disaster type
				switch (randomDisasterType)
				{
				case e_Disasters::e_hurricane:
					randomDisaster = hurricane;
					break;
				case e_Disasters::e_flood:
					randomDisaster = flood;
					break;
				case e_Disasters::e_forestFire:
					randomDisaster = forestFire;
					break;
				case e_Disasters::e_earthquake:
					randomDisaster = earthquake;
					break;
				case e_Disasters::e_tsunami:
					randomDisaster = tsunami;
					break;
				case e_Disasters::e_lizardPeople:
					randomDisaster = lizardPeople;
					break;
				}

				// Check if the disaster can affect the suburb's type
				if ((randomDisasterType == e_Disasters::e_tsunami && (randomSuburb.suburbType == e_SuburbType::e_Coastal || randomSuburb.suburbType == e_SuburbType::e_Island)) //tsunami's can only affect coastal and island type
					|| (randomDisasterType != e_Disasters::e_tsunami))
				{
					randomSuburb.hasDisaster = true; //mark the suburb as having a disaster and assign disaster type and damage
					randomSuburb.disaster = randomDisaster;

					int damage = randomSuburb.suburbPopulation * randomDisaster.m_damagePercent / 100; //calculate damage based on population and disaster damage percentage
					randomSuburb.suburbPopulation -= damage;

					cout << "\nOh no! A " << randomDisaster.m_name << " has struck " << randomSuburb.suburbName << "!" << endl; //message about disaster
					cout << randomSuburb.suburbName << " lost " << damage << " population due to the disaster." << endl;
				}
			}
			system("pause");
		}
		else if (startMenuSelection == 3) //exit simulation
		{
			system("cls");
			cout << "Thanks for playing!" << endl;
			cout << "You played for " << turnCounter << " turns!" << endl;
			cityLoop = false;
		}
		else //invalid option
		{
			cout << "That's an invalid option!" << endl;
			cout << "Please try again..." << endl;
			system("pause");
		}
	}
}

//function to allow user to select a suburb for detailed information
void SuburbInformationSelection()
{
	//create and array of pre-defined suburbs for access in this 
	Suburb suburbArray[] = { suburb1, suburb2, suburb3, suburb4, suburb5, suburb6, suburb7, suburb8 };

	if (g_suburbSelectionInput >= 1 && g_suburbSelectionInput <= 8) //checks if user input is within valid range
	{
		suburbArray[g_suburbSelectionInput - 1].DisplaySuburbInformation(); //display detailed information about selected suburb, -1 due to nature of arrays (1 = 0)
	}
	else //error for invalid input
	{
		cout << "Invalid Input!" << endl;
		cout << "Please select an option 1 - 8..." << endl;
	}
}

void Transport(Suburb& transport1, Suburb& transport2)
{
	// Check if transport1 and transport2 are neighbors
	bool areNeighbors = false;

	for (int neighborID : transport1.suburbNeighbours) //iterate through the ID's of transport1 to determine if transport2 is neighbour
	{
		if (neighborID == transport2.suburbID) //checks array to see if valid
		{
			areNeighbors = true; //if neighbours set to true and end loop
			break;
		}
	}

	if (!areNeighbors) //if transport2 is not a neighbour of transport1, display error message and exit
	{
		cout << "Suburbs are not neighbors. Population cannot be transferred..." << endl;
		return;
	}

	// Check if either of the suburbs has a disaster and apply effects
	if (transport1.hasDisaster)
	{
		int damage = transport1.suburbPopulation * transport1.disaster.m_damagePercent / 100;
		transport1.suburbPopulation -= damage;
		transport1.hasDisaster = false;
	}
	if (transport2.hasDisaster)
	{
		int damage = transport2.suburbPopulation * transport2.disaster.m_damagePercent / 100;
		transport2.suburbPopulation -= damage;
		transport2.hasDisaster = false;
	}

	// Perform the population transport
	int g_travel = rand() % transport1.suburbPopulation + 1; //generates random number in between 1 and suburb population for transportation

	cout << "\nPopulation of " << transport1.suburbName << " before: " << transport1.suburbPopulation << endl; //shows population before transport
	cout << "Population of " << transport2.suburbName << " before: " << transport2.suburbPopulation << endl;

	cout << "\nTransporting " << g_travel << " people from " << transport1.suburbName << " to " << transport2.suburbName << endl;

	if (transport1.suburbType == e_SuburbType::e_Island || transport2.suburbType == e_SuburbType::e_Island)
	{
		SHIPASCII();
	}
	else
	{
		TRAINASCII();
	}

	transport1.suburbPopulation -= g_travel; //update population after transport
	transport2.suburbPopulation += g_travel;

	cout << "\nPopulation of " << transport1.suburbName << " after: " << transport1.suburbPopulation << endl; //shows population after transport
	cout << "Population of " << transport2.suburbName << " after: " << transport2.suburbPopulation << endl;
}

//function to handle user's suburb choice
Suburb SuburbChoice(int choice)
{
	if (choice >= 1 && choice <= 8) //check if the user is withing the valid range (1-8)
	{
		return suburbArray[choice - 1]; // -1 because choices are 1-based
	}
	else
	{
		cout << "Invalid input!" << endl; //displays an error message and returns 'InvalidSuburb' for an out of range choice
		return InvalidSuburb;
	}
}

void SHIPASCII()
{
	cout << "" << endl;
	cout << "                           _" << endl;
	cout << "                          (_)" << endl;
	cout << "           --""-------   0/      ^^" << endl;
	cout << " .___...../ /__| |__| |_/H__,      ^^" << endl;
	cout << "  |                        /" << endl;
	cout << "#####^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~\O/~~\Q/~^~^~rr" << endl;
}

void TRAINASCII()
{
	cout << "" << endl;
	cout << "    o o o o o o o . . .   ______________________________ _____=======_||____" << endl;
	cout << "   o      _____           ||                            | |                 |" << endl;
	cout << " .][__n_n_|DD[  ====_____  |                            | |                 |" << endl;
	cout << ">(________|__|_[_________]_|____________________________|_|_________________|" << endl;
	cout << "_/oo OOOOO oo`  ooo   ooo  'o!o!o                  o!o!o` 'o!o         o!o`" << endl;
	cout << "-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-" << endl;
}

void WELCOMEASCII()
{
	cout << "" << endl;
	cout << " __        _______ _     ____ ___  __  __ _____  " << endl;
	cout << " | |      / / ____| |   / ___/ _ ||  |/  | ____| " << endl;
	cout << "  | | /| / /|  _| | |  | |  | | | | ||/| |  _|   " << endl;
	cout << "   | V  V / | |___| |__| |__| |_| | |  | | |___  " << endl;
	cout << "    |_/|_/  |_____|_____|____|___/|_|  |_|_____| " << endl;
	cout << "                  _____ ___                      " << endl;
	cout << "                 |_   _/ _ |                     " << endl;
	cout << "  _____ _____ _____| || | | |_____ _____ _____   " << endl;
	cout << " |_____|_____|_____| || |_| |_____|_____|_____|  " << endl;
	cout << "                   |_| |___/                     " << endl;
	cout << "  ____ ___ ____    _    ____ _____ _____ ____    " << endl;
	cout << " |  _ |_ _/ ___|  / |  / ___|_   _| ____|  _ |   " << endl;
	cout << " | | | | ||___ | / _ | |___ | | | |  _| | |_) |  " << endl;
	cout << " | |_| | | ___) / ___ | ___) || | | |___|  _ <   " << endl;
	cout << " |____/___|____/_/   |_|____/ |_| |_____|_| |_|  " << endl;
	cout << "               ____ ___ _______   __             " << endl;
	cout << "              / ___|_ _|_   _| | / /             " << endl;
	cout << "  _____ _____| |    | |  | |  | V /____ _____    " << endl;
	cout << " |_____|_____| |___ | |  | |   | |_____|_____|   " << endl;
	cout << "              |____|___| |_|   |_|               " << endl;
	cout << "                                                 " << endl;
}

#include "pk.h"
#include <iostream>
using std::cout;

Liwanze::Liwanze(const std::string& n, const Region& r) : name{ n }, loc{ r }, connectsTo{}, connectedFrom{}
{}

std::string Liwanze::get_name() const
{
	return name;
}

Liwanze::Region Liwanze::get_loc() const
{
	return loc;
}

vector<std::string>& Liwanze::getConnectsTo() 
{
	return connectsTo;
}

vector<std::string>& Liwanze::getConnectedFrom() 
{
	return connectedFrom;
}


void Liwanze::print() const
{
	vector<std::string> locationVec { "ndef", "amer", "apac", "emea" };
	std::string location{locationVec.at(loc-1)};

	cout << name << ": " << location << std::endl;
}

//Task 2 functions 

bool Liwanze::connects(const std::string& n) const
{
	for (unsigned int i{}; i < connectsTo.size(); i++)
	{
		if(n == connectsTo.at(i)) return true;
	}
	return false;
}

bool Liwanze::connected(const std::string& n) const
{
	for (unsigned int i{}; i < connectedFrom.size(); i++)
	{
		if (n == connectedFrom.at(i)) return true;
	}
	return false;
}

void Liwanze::print_tierone() const
{
	cout << name << " connects to: ";
	for (unsigned int i{}; i < connectsTo.size(); i++) cout << connectsTo.at(i) << ", ";
	cout << "connects from: ";
	for (unsigned int i{}; i < connectedFrom.size(); i++) cout << connectedFrom.at(i) << ", ";
}

void Liwanze::add_connTo(const std::string& n)
{
	connectsTo.push_back(n);
}

void Liwanze::add_connFrom(const std::string& n)
{
	connectedFrom.push_back(n);
}


//Helper functions task 2

void init_connections(vector<Liwanze>& vL)
{
	for (unsigned int i{}; i < vL.size(); i++)
	{
		if (vL.at(i).get_name() == "Joey")
		{
			make_connection(vL, "Joey", "Johnny");
			make_connection(vL, "Joey", "Sheena");
		}
		if (vL.at(i).get_name() == "Johnny")
		{
			make_connection(vL, "Johnny", "Joey");
		}
		if (vL.at(i).get_name() == "DeeDee")
		{
			make_connection(vL, "DeeDee", "Joey");
		}
		if (vL.at(i).get_name() == "Suzy")
		{
			make_connection(vL, "Suzy", "Joey");
			make_connection(vL, "Suzy", "Johnny");
			make_connection(vL, "Suzy", "DeeDee");
			make_connection(vL, "Suzy", "Tommy");
		}
		if (vL.at(i).get_name() == "Sheena")
		{
			make_connection(vL, "Sheena", "Joey");
		}
	}
}

void make_connection(vector<Liwanze>& vL, std::string nFrom, std::string nTo)
{

	int i{}; //i is nTo element in vector
	int j{}; //j is nFrom element in vector

	while (i < vL.size()+1)
	{
		if (vL.at(i).get_name() == nTo) break;
		else i++;
	}
	while (j < vL.size()+1)
	{
		if (vL.at(j).get_name() == nFrom) break;
		else j++;
	}

	vL.at(i).add_connTo(vL.at(j).get_name());
	vL.at(j).add_connFrom(vL.at(i).get_name());

	/*temp_nTo->add_connFrom(temp_nFrom->get_name());
	temp_nFrom->add_connTo(temp_nTo->get_name());*/

	//check if added correctly and in both members' lists
	/*unsigned int i{ temp_nTo->getConnectsTo().size() };

	bool temp_nFrom_set{ false };
	bool temp_nTo_set{ false };

	for (unsigned int i{}; i < temp_nTo->getConnectsTo().size(); i++)
	{
		std::string nameTo{ temp_nTo->getConnectsTo().at(i) };
		std::string nameFrom{ temp_nFrom->get_name() };
		if (temp_nTo->getConnectsTo().at(i) == temp_nFrom->get_name()) temp_nTo_set = true;
	}
	for (unsigned int i{}; i < temp_nFrom->getConnectsTo().size(); i++)
	{
		if (temp_nFrom->getConnectsTo().at(i) == temp_nTo->get_name()) temp_nFrom_set = true;
	}
	if (temp_nTo_set == false || temp_nFrom_set == false) throw std::runtime_error("incorrect allocation of connections at make_connection()");*/

}


//Helper functions task 1

void populate(vector<Liwanze>& vL) 
{
	vL.push_back(Liwanze{ "Joey", Liwanze::Region::amer });
	vL.push_back(Liwanze{ "Johnny", Liwanze::Region::amer });
	vL.push_back(Liwanze{ "DeeDee", Liwanze::Region::amer });
	vL.push_back(Liwanze{ "Tommy", Liwanze::Region::emea });
	vL.push_back(Liwanze{ "Suzy", Liwanze::Region::apac });
	vL.push_back(Liwanze{ "Sheena", Liwanze::Region::amer });
}

void print_LVZMembers(vector<Liwanze>& vL)
{
	for (unsigned int i{}; i < vL.size(); i++)
	{
		vL.at(i).print();
	}
}

void add_Liwanze(vector<Liwanze>& vL)
{
	std::string input{};
	bool isInVector{};
	cout << "You may add as many members by name as you wish. Please exit with 'q'.\n";

	do
	{
		isInVector = false; //reset boolean value to false

		cout << '>';
		std::cin >> input;
		if (!std::cin) throw std::runtime_error("faulty input at add_Liwanze()");

		for (unsigned int i{}; i < vL.size(); i++)
		{
			if (vL.at(i).get_name() == input) isInVector = true;
		}
	
		if (input == "q") //this line ensures that q is not added as a member to the vector vL
			continue; 
		else if (isInVector == true) //if name is already in vector, reject name and notify user
			cout << "The member you want to add is already stored in the system and will not be added again. You may continue adding members or exit with 'q'\n";
		else //if name is not in vector
		{
			vL.push_back(Liwanze{ input, Liwanze::Region::ndef }); //add name to vector
			cout << "\nThe system currenty holds the following members: \n";
			print_LVZMembers(vL);
			cout << std::endl;
		}

	} while (input != "q");
}

void add_connection(vector<Liwanze>& vL)
{
	std::string inputTo{};
	std::string inputFrom{};
	bool toIsInVector{};
	bool fromIsInVector{};
	cout << "You may add as many connections of two members.\nPlease type in first the member to be connected from, followed by a space seperator or by pressing enter, and than the member to be connected to. \nPlease exit with 'q'.\n";

	do
	{
		cout << std::endl; 

		toIsInVector = false; //reset boolean value to false
		fromIsInVector = false;

		cout << '>';
		std::cin >> inputTo;
		if (inputTo == "q") break;
		if (!std::cin) throw std::runtime_error("faulty input at add_connection()");

		std::cin >> inputFrom;
		if (!std::cin) throw std::runtime_error("faulty input at add_connection()");

		if (inputTo == inputFrom)
		{
			cout << "You have added the same name twice. Establishing such a recursive connection is not necessary. The step was skipped and you may add other connections or exit by entering 'q'" << std::endl;
			continue;
		}

		//check if names in vector. throw error if not
		for (unsigned int i{}; i < vL.size(); i++)	if (vL.at(i).get_name() == inputTo) toIsInVector = true;
		for (unsigned int i{}; i < vL.size(); i++)  if (vL.at(i).get_name() == inputFrom) fromIsInVector = true;
		if (toIsInVector == false || fromIsInVector == false) throw std::runtime_error("name not in vector at add_connection().");

		make_connection(vL, inputFrom, inputTo);
		cout << "The connection was established." << std::endl;
		printDetails(vL, inputFrom);
		printDetails(vL, inputTo);

	} while (inputTo != "q");

}


void printDetails(vector<Liwanze>& vL, std::string n)
{
	Liwanze* temp_n{};

	for (unsigned int i{}; i < vL.size(); i++) if (vL.at(i).get_name() == n) temp_n = &vL.at(i);

	vector<std::string> locationVec{ "ndef", "amer", "apac", "emea" };
	std::string location{ locationVec.at(temp_n->get_loc() - 1) };

	cout << temp_n->get_name() << ": " << location << ", conntects to: " << temp_n->getConnectsTo().size() << " members, connects from: " << temp_n->getConnectedFrom().size() << " members" << std::endl;
	cout << temp_n->get_name() << " is connected to: ";
	for (unsigned int i{}; i < temp_n->getConnectsTo().size(); i++) cout << temp_n->getConnectsTo().at(i) << ", ";
	cout << " and connected from: ";
	for (unsigned int i{}; i < temp_n->getConnectedFrom().size(); i++) cout << temp_n->getConnectedFrom().at(i) << ", " << std::endl; 
}

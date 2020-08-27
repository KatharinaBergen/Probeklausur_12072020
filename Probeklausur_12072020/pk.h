#include <string>

#include<vector>
using std::vector;

#ifndef H
#define H

class Liwanze
{
public:

	enum Region { ndef = 1, amer, apac, emea }; //enumerated Regions
	Liwanze(const std::string&, const Region&);
	std::string get_name() const;
	Region get_loc() const;  
	void print() const;

	bool connects(const std::string&) const;
	bool connected(const std::string&) const;
	void print_tierone() const;
	void add_connTo(const std::string&);
	void add_connFrom(const std::string&);

	//my added methods
	vector<std::string>& getConnectsTo();
	vector<std::string>& getConnectedFrom();
	

private:
	std::string name;
	Region loc;
	Liwanze() = delete;

	vector<std::string> connectsTo;
	vector<std::string> connectedFrom;
};

void populate(vector<Liwanze>&);
void print_LVZMembers(vector<Liwanze>&);
void add_Liwanze(vector<Liwanze>&);

void init_connections(vector<Liwanze>&);
void make_connection(vector<Liwanze>&, std::string, std::string);
void add_connection(vector<Liwanze>&); //user to add connections

//my added methods
void printDetails(vector<Liwanze>&, std::string);

#endif // !H
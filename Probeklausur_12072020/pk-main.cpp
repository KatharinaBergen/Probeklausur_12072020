#include <iostream>
#include "pk.h"

int main() try 
{
	vector<Liwanze> vL{};
	populate(vL);
	print_LVZMembers(vL);
	add_Liwanze(vL);
	init_connections(vL);
	add_connection(vL);

	return 0;
}
catch (std::exception& e)
{
	std::cerr << e.what();
	return -1;
}
catch(...)
{
	std::cerr << "unknown error";
	return -2;
}
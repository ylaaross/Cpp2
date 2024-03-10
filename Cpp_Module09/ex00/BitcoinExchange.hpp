#include <iostream>
#include <string>
#include <fstream>
#include <sstream>


enum date_components {
    YEAR = 4,
    MONTH = 5,
	DAY = 6
};


void read_database();
void read(std::string fileName);
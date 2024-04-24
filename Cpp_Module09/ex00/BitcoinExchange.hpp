#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
class BitcoinExchnage
{
    private:
        std::map <std::string, double> dbmap;
    public:
    BitcoinExchnage();
    ~BitcoinExchnage();
    void read_database();
    void read(std::string fileName);
    void display();
    double returnValue(std::string value);
};
enum date_components {
    YEAR = 4,
    MONTH = 5,
	DAY = 6
};



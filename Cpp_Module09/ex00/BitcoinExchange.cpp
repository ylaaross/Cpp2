#include "BitcoinExchange.hpp"
#include <map>

void find_delete(std::string &str)
{
    size_t found = str.find("-");
    while(found != std::string::npos)
    {
        str[found] = ' ';
        found = str.find("-");
    }
}

int test_length(std::string str, int date_component)
{
    if(str.length() > 4 && date_component == YEAR)
        return (0);
    if(str.length() > 2 && date_component == MONTH)
        return (0);
    if(str.length() > 2 && date_component == DAY)
        return (0);
    return (1);
}

int store(std::string str, int *var, int date_component)
{
    char *reminder;

    reminder = 0;
    const char *strc = str.c_str();
    *var = strtod(strc , &reminder);
    if (strlen(reminder) != 0)
        return (0);
    return (1);
}   
int store(std::string str, double *var)
{
    char *reminder;

    reminder = 0;
    if (str.length() > 4)
    {
        std::cout << "hnaaaaaaa" << std::endl;
        return (0);
    }
    const char *strc = str.c_str();
    *var = strtod(strc , &reminder);

    if (strlen(reminder) != 0)
    {
        std::cout<< "lbts akhouya" << std::endl;
        return(0);
    }
    return(1);
}   
bool isLeapYear(int year) {
    if (year % 400 == 0) {
        return true;
    } 
    else {
        return false;
    }
}
int max_days_month(int month, int year)
{
    
    if(month == 2 && isLeapYear(year))
        return(29);
    else if(month == 2 && !isLeapYear(year))
        return(28);
    else if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        return(31);
    else
        return(30);
}

int valid_date(std::string str)
{
    std::string syear;
    std::string smonth;
    std::string sday;
    char *rest;
    int year;
    int month;
    int day;

    rest = 0;
    find_delete(str);   
    std::stringstream ss(str);
    ss >> syear >> smonth >> sday;
    if(!test_length(syear, YEAR) || !test_length(smonth, MONTH) || !test_length(sday, DAY))
        return (0);
    if(!store(syear, &year, YEAR) || !store(smonth , &month, MONTH) || !store(sday , &day, DAY))
        return(0);
    if (year > 2024 || year < 2009)
        return(0);
    if (month > 12 || month < 1)
        return (0);
    if((day > max_days_month(month, year) || day < 1))
        return (0);
    return((year * 365) + max_days_month(month, year) + day);
}

double get_value(std::string str)
{
    double var = 0;
    char *reminder;

    reminder = 0;
    const char *strc = str.c_str();
    var = strtod(strc , &reminder);
    return (var);
}

int fulldate_days(std::string   str)
{
    std::string syear;
    std::string smonth;
    std::string sday;
    char *rest;
    int year;
    int month;
    int day;

    rest = 0;
    find_delete(str);   
    std::stringstream ss(str);

    ss >> syear >> smonth >> sday;
    store(syear, &year, YEAR);  
    store(smonth , &month, MONTH); 
    store(sday , &day, DAY);
    return((year * 365) + (month * 30) + day);
}
// 2001-12-31
// 2001-2-31
double valid_value(std::string str)
{
    double value = 0;

    if (!store(str, &value))
        return (-1);
    if (value > 1000)
        return (-2);
    if (value < 0)
        return (-3);

    std::cout << "value        --" << value;
    return (value);
}


void read_database()
{
    std::string date;
    std::string tmp;
    std::string value;
    double dvalue;
    int idate;

    std::map<int, double> myMap;
    std::ifstream inputFile("test.txt");

    if (!inputFile) 
	{
        std::cerr << "Failed to open the file." << std::endl;
        return ;
    }





    int i = 1;
    std::string line;
    std::string pline;
    while (std::getline(inputFile, line)) 
    {
        std::stringstream ss(line);
        ss >> date >> tmp >> value;
        idate = fulldate_days(date);
        // std::cout << "--    "  << value  << "-----";
        dvalue = get_value (value);
        // std::cout << dvalue << std::endl;
        std::cout << i << std::endl;    
        // std::cout << "idate" << idate;
        // std::cout << " dvalue" << dvalue << std::endl;
        // std::cout << line << std::endl;
        myMap.insert(std::pair<int, double>(idate, dvalue));
        i++;
    }
        
    for (std::map<int , double>::iterator it = myMap.begin(); it != myMap.end(); ++it) 
    {
        std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
    }

    inputFile.close();
}

void read(std::string fileName)
{
    double dvalue;
    std::string tmp;
    std::string date;
    std::string value;
    int idate;
 	std::ifstream inputFile(fileName);

    if (!inputFile) 
	{
        std::cerr << "Failed to open the file." << std::endl;
        return ;
    }

    std::string line;
    std::string pline;
    while (std::getline(inputFile, line)) 
    {
        // std::cout << line << std::endl;
        
        std::stringstream ss(line);

        ss >> date >> tmp >> value;
        if(!(idate = valid_date(date)) && (dvalue = valid_value(value)) < 0)
        {
        }
        else
        {
        }
        std::cout << line << std::endl; 
    }
    
    inputFile.close();
}
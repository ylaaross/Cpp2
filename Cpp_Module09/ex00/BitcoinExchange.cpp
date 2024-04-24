#include "BitcoinExchange.hpp"
#include <map>

BitcoinExchnage::BitcoinExchnage()
{

}


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
   
    const char *strc = str.c_str();
    *var = strtod(strc , &reminder);
     if (str.length() > 4 && strlen(reminder) == 0)
     {
        std::cout << "Error: too large a number." << std::endl;
        return (0);
     }
    if (strlen(reminder) != 0)
        return(0);
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

int diplay_error(std::string str)
{
    std::cout << "Error: bad input => "  << str << std::endl;
    return (0);
}

int valid_date(std::string str)
{
    std::string syear;
    std::string smonth;
    std::string sday;
    std::string ostr;
    char *rest;
    int year;
    int month;
    int day;

    ostr = str;
    rest = 0;
    if (str == "")
    {
        std::cout << "Error: Empty date" << std::endl;
        return (0);
    }
    find_delete(str);   
    std::stringstream ss(str);
    ss >> syear >> smonth >> sday;
    if(!test_length(syear, YEAR) || !test_length(smonth, MONTH) || !test_length(sday, DAY))
        return (diplay_error(ostr));
    if(!store(syear, &year, YEAR) || !store(smonth , &month, MONTH) || !store(sday , &day, DAY))
        return(diplay_error(ostr));
    if (year > 2024 || year < 2009)
        return(diplay_error(ostr));
    if (month > 12 || month < 1)
        return (diplay_error(ostr));
    if((day > max_days_month(month, year) || day < 1))
        return (diplay_error(ostr));
    return (1);
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

double valid_value(std::string str)
{
    double value = 0;
    if(str == "")
    {
        std::cout << "Error: Empty value" << std::endl;
        return(0);
    }
    if (!store(str, &value))
        return (0);
    if (value > 1000)
    {
        std::cout << "Error: too large a number." << std::endl;
        return (0);
    }
    if (value < 0)
        return (0);
    return (value);
}

void change_char(std::string &str)
{
    size_t pos = str.find(',');
    if (pos != std::string::npos) {
        str[pos] = ' ';
    }
}
void BitcoinExchnage::read_database()
{
    std::string date;
    std::string tmp;
    std::string value;
    double dvalue;
    int idate;

  
    std::ifstream inputFile("data.csv");

    if (!inputFile) 
	{
        std::cerr << "Failed to open the file." << std::endl;
        return ;
    }
    std::string line;
    std::string pline;
    while (std::getline(inputFile, line)) 
    {
        change_char(line);
        std::stringstream ss(line);
        ss >> date >> value;
        dvalue = get_value (value);
        dbmap.insert(std::pair<std::string, double>(date, dvalue));
    }
    inputFile.close();
}
void BitcoinExchnage::display()
{
    std::map<std::string, double>::iterator it;
    for(it = dbmap.begin() ; it != dbmap.end(); ++it)
    {
        std::cout << it->first <<" " << it->second << std::endl;
    }
}
BitcoinExchnage::~BitcoinExchnage()
{

}
double BitcoinExchnage::returnValue(std::string value)
{
    std::map<std::string, double>::iterator it = dbmap.lower_bound(value);
    if (it != dbmap.end()) 
    {
       if(it == dbmap.begin() && it->second != dbmap.begin()->second)
            return (-1);
        if(it != dbmap.begin() && it->first != value)
            it--;
        return (it->second);
    } 
    else
        return (-1);
} 
void BitcoinExchnage::read(std::string fileName)
{
    bool b = 0;
    double dvalue;
    int idate;

    std::string tmp;
    std::string date;
    std::string value;
    
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
        std::stringstream ss(line);
        ss >> date >> tmp >> value;
        if(date == "date" && value == "value" && b == 0)
            continue;
        else if((idate = valid_date(date)) && (dvalue = valid_value(value)))
        {
            b = 1;
            std::cout << date << " " << value << " " << "=>";
            std::cout << " " << returnValue(date) * dvalue << std::endl;
        }

        date = "";
        value = "";
    }
    inputFile.close();
}

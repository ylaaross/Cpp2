#include <iostream>
#include <vector>
#include <algorithm>

void display_vector(std::vector<std::vector<int> > &matrix,std::string str)
{
	int i, j;

	std::cout << str << std::endl;
	for(i = 0; i < matrix.size() ; i++)
	{
		for(j=0; j < matrix[i].size(); j++)
		{
			std::cout << matrix[i][j];	
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

int convert(std::string str, bool *boolean)
{
	double var;
	char *reminder;

    reminder = 0;
   
    const char *strc = str.c_str();
    var = strtod(strc , &reminder);
	if(str.length() > 11)
	{
		*boolean = 0;
		return var;
	}
	if(var >= -2147483648  && var <= 2147483647)
	{
		*boolean = 1;
		return var;
	}
	else
	{
		*boolean = 0;
		return var;
	}
}

void	store_numbers(std::vector<std::vector<int> > &matrix, char **argv)
{
	int i;
	bool b;

	i = 1;
	int nbr = 0;
	while(argv[i])
	{
		b = 0;
		nbr = convert(argv[i], &b);
		if(b)
		{
			std::vector<int> row;
			row.push_back(nbr);
			matrix.push_back(row);
		}
		else
		{
			std::cout << "Error : argument error" << std::endl;
			exit(1);

		}
		i++;
	}
}
// int lower_boundd()
// {
// 	int i = 0;

// 	while()
// 	{

// 	}
// }
std::vector<std::vector<int> > copy_vector(std::vector<std::vector<int> > &matrix)
{
	std::vector<std::vector<int> > copy;
	int i = 0;
    std::vector<std::vector<int> >::iterator it;
	for (it = matrix.begin(); it != matrix.end(); ++it, i++) 
	{
		if(!(i != 0 && i % 2 != 0))
			copy.push_back(*it);
    }
	return (copy);
}

void group_phase(std::vector<std::vector<int> > &matrix, std::vector<std::vector<int> > &reminder)
{
	int number = 0;
	int i;
	bool r;

	while (matrix.size() > 1)
	{
		r = 0;
		i = 0;
		while(i <= matrix.size() - 2)
		{
			if (matrix.size() % 2 != 0)
			{
				reminder.push_back(matrix[matrix.size() - 1]);
				matrix.erase(matrix.begin() + matrix.size() - 1);
			}
				if(matrix[i].back() > matrix[i + 1].back())
					std::swap(matrix[i], matrix[i + 1]);
				matrix[i].insert(matrix[i].end(), matrix[i + 1].begin(), matrix[i + 1].end());
			i = i + 2;
		}
		int i = 0;
		int j = 0;
		
		matrix = copy_vector(matrix);
		std::cout << "grouping number" << number << std::endl;
		for(i = 0; i < matrix.size() ; i++)
		{
			for(j=0; j < matrix[i].size(); j++)
			{
				std::cout << matrix[i][j];	
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}	
}

void insert_reminder(std::vector<std::vector<int> > &pd, std::vector<std::vector<int> > &reminder)
{
	int size;
	int i;
	int j;
	bool b = 0;
	int place;

	size = pd[0].size();

	for (i = 0; i < reminder.size(); i++)
	{
		if (size == reminder[i].size())
		{
			std::cout << "dipslay"<< std::endl;
			display_vector(pd, "pd");
			std::cout << "pd size"<< pd[0].size() <<std::endl;
			std::cout << "reminder size"<< reminder[i].size() <<std::endl;
			display_vector(reminder, "reminder");
			pd.push_back(reminder[i]);
			reminder.erase(reminder.begin() + i);
			break ;
		}
	}
}
void clear_vectore(std::vector<std::vector<int> > &matrix)
{
	for (std::vector<std::vector<int> >::iterator it = matrix.begin(); it != matrix.end(); ++it) 
		{
       		(*it).clear();
		}
	matrix.clear();
}

void iterate_pd(std::vector<std::vector<int> > &ch,std::vector<std::vector<int> > &pd)
{
	std::vector<std::vector<int> >::iterator it = ch.begin();
	
	for (it = pd.begin(); it != pd.end(); ++it)
	{
		
    }
}

void insert_phase(std::vector<std::vector<int> > &matrix, std::vector<std::vector<int> > &reminder)
{

	int i=10;
	int j;
	int i1 = 0;
	int j1 = 0;
	int insert;
	std::vector<int> numbers;
	std::vector<std::vector<int> > mc;
	std::vector<std::vector<int> > pd;

	while (matrix[0].size() > 1)
	{
		for (i1 = 0; i1 < matrix.size(); i1++)
		{
			numbers.insert(numbers.end(), matrix[i1].begin(), matrix[i1].begin() + matrix[i1].size() / 2);
			pd.push_back(numbers);
			numbers.clear();
			numbers.insert(numbers.end(), matrix[i1].begin() +matrix[i1].size() / 2  , matrix[i1].end());
			mc.push_back(numbers);
			numbers.clear();
		}
		
		insert_reminder(pd, reminder);
		display_vector(pd, "pd");
		display_vector(mc, "mc");
		clear_vectore(matrix);
		matrix.insert(matrix.end(),pd.begin(),pd.end());
		matrix.insert(matrix.end(),mc.begin(),mc.end());
		clear_vectore(pd);
		clear_vectore(mc);
    

		std::cout << "lbts akhouya" << std::endl;
		j1++;
	}
}

int main(int argc,char **argv) 
{
	
    std::vector<std::vector<int> > matrix;
   	std::vector<std::vector<int> > reminder;
	std::vector<std::vector<int> > matrix1;
   if (argc > 1)
   {
		store_numbers(matrix, argv);
		group_phase(matrix, reminder);
		insert_phase(matrix,reminder);
		display_vector(matrix, "matrix");
		
   }
   else
   		std::cout << "Error" << std::endl;

	return (0);
}
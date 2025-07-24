#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>

enum cards{
	2 = 0,
	3,
	4,
	5,
	6,
	7,
	8,
	9,
	10,
	T,
	J,
	Q,
	K
}

std::vector<std::string> split(std::string text, char delim){
	std::vector<std::string> ret_vec;
	std::string line;
	std::stringstream ss(text); 
	while(std::getline(ss, line, delim)) {
		ret_vec.push_back(line);
	}
	return ret_vec;
}

int count(std::string string, char c)
{
	int ret = 0; 
	for (int i = 0; i < string.size(); i++)
	{
		if (string[i] == c)
			ret++;
	}
	return (ret);
}

std::vector<std::string> sort_array(std::vector<std::string> array)
{
	std::string cards = "23456789TJQK";
	std::vector<int> hand_ranks;
	std::vector<std::string> temp;
	std::vector<int> vals = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	for (auto i : array)
	{
		temp = split(i, ' ');
		for (int j = 0; j < cards.size(); j++)
		{
			vals[j] = count(temp[0], cards[j]);
		}
	std::cout << "vals: ";
	for (auto i: vals)
		std::cout << " "<< i;
	std::cout << std::endl;
	}
	return (array);
}

int main (void)
{
	std::ifstream ifs;
	std::string buffer;
	std::vector<std::string> array;
	int rank = 0;
	ifs.open("input2.txt");
	while(!ifs.eof()){
		std::getline(ifs, buffer);
		array.push_back(buffer);
	}
	std::cout << "length of the array is: " << array.size() << std::endl;
	array = sort_array(array);
}

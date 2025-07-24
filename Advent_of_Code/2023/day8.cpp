#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>


std::vector<std::string> split(std::string text, char delim){
	std::vector<std::string> ret_vec;
	std::string line;
	std::stringstream ss(text); 
	while(std::getline(ss, line, delim)) {
		ret_vec.push_back(line);
	}
	return ret_vec;
}


int main(void)
{
	std::ifstream ifs;
	std::string buffer;
	std::vector<std::string> input;
	std::vector<std::string> temp;
	std::string route;
	std::string found;
	std::string next;
	int pos = 0;
	int round = 0;
	int foundpos = 0;
	int steps = 0;
	ifs.open("input.txt");
	std::getline(ifs, route);
	std::getline(ifs, buffer);
	buffer.clear();
	//exit (0);
	std::cout << "route: " << route << std::endl;
	while(!ifs.eof()){
		std::getline(ifs, buffer);
		if (!buffer.empty()){
			buffer.erase(remove(buffer.begin(), buffer.end(), '('), buffer.end());
			buffer.erase(remove(buffer.begin(), buffer.end(), ')'), buffer.end());
			buffer.erase(remove(buffer.begin(), buffer.end(), ','), buffer.end());
			temp = split(buffer, ' ');
			temp.erase(temp.begin()+1);
			for (auto j : temp)
			{
				input.push_back(j);
			}
		}
		buffer.clear();
	}
	pos = 0;
	while (found != "ZZZ")
	{
		for (int c = 0; c < route.size(); c++)
		{
			if(route[c] == 'L')
				next = input[pos + 1];
			if(route[c] == 'R')
				next = input[pos + 2];
			for (int p = 0; p < input.size(); p += 3){
				foundpos = input[p].find(next);
				if (foundpos != std::string::npos){
					found = input[p];
					pos = p;
					steps++;
					if (found == "ZZZ"){
						std::cout << "steps: " << steps << std::endl;
						exit (0);
					}
				}
			}	
		}
		round++;
		std::cout << "round: " << round << std::endl;
	}
}
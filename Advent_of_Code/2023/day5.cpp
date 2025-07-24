#include <string> 
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>

#define NUMSEED 20
 
std::vector<std::string> split(std::string text, char delim) {
    std::string line;
    std::vector<std::string> vec;
    std::stringstream ss(text);
    while(std::getline(ss, line, delim)){
        vec.push_back(line);
    }
    return vec;
}

std::vector<double> calc_seed(std::vector<double>seed, int sd, std::vector<std::string>lines, int line, int start)
{
	std::vector<std::string> row;
	std::vector<double> ret_list;
	std::cout << "start: " << start << std::endl;
	std::cout << "line: " << line << std::endl;
	for (int i = 0; i < seed.size(); i++)
		ret_list.push_back(seed[i]);
	while(start < line)
	{
		row = split(lines[start], ' ');
		if (seed[sd] >= std::stod(row[1]) && seed[sd] <= std::stod(row[1]) + std::stod(row[2]))
		{
			seed[sd] += (std::stod(row[0]) - std::stod(row[1]));
			std::cout << "row[0]: " << row[0] << std::endl
					  << "row[0].stod: " << std::stod(row[0]) << std::endl
					  << "row[1]: " << row[1] << std::endl
					  << "row[2]: " << row[2] << std::endl;
			std::cout << "new val: " << seed[sd] << std::endl;
			start = line;
		}
		row.clear();
		start++;
	}
	return seed;
}

int main (void)
{
	std::ifstream ifs;
	std::string input;
	std::string buffer;
	std::vector<std::string> lines;
	std::vector<double> seeds;
	std::vector<std::string> temp;
	std::string throwaway;
	int start = 0;
	double val = 0;

	ifs.open("input.txt");
	std::getline(ifs, input);
	temp = split(input, ' ');
	temp.erase(temp.begin());
	for (int i = 0; i < temp.size(); i += 2)
	{
		// std::cout << "val[i]:" << temp[i] << std::endl;
		// std::cout << "val[i + 1]" << temp[i + 1] << std::endl; 
		while(val < std::stod(temp[i + 1])){
			//std::cout << val << std::endl;
			seeds.push_back(std::stod(temp[i]) + val);
			val++;
		}
		val = 0;
	}
	std::cout << seeds.size() << std::endl;
	exit(0);
	std::getline(ifs, throwaway);
	std::getline(ifs, throwaway);
	while(!ifs.eof())
	{
		std::getline(ifs, buffer);
		//std::cout << buffer << std::endl;
		if (buffer.empty())
			std::getline(ifs, buffer);
		if (buffer[0] - '0' < 0 || buffer[0] - '0' > 9)
		{
			lines.push_back("<0>");
			//seeds = get_next(seeds, lines);
			//continue;
		}
		else
			lines.push_back(buffer);
	}
	lines.push_back("<0>");
	for (auto i : seeds)
		std::cout << "seed: " << i << std::endl;
	for (auto i : lines)
		std::cout << i << std::endl;
	for (int sd = 0; sd < seeds.size(); sd++)
	{
		for(int line = 0; !lines[line].empty(); line++)
		{
			if (lines[line] == "<0>")
			{
				seeds = calc_seed(seeds, sd, lines, line, start);
				std::cout << "return list: ";
				for (auto i : seeds)
					std::cout << " " << i << " ";
				std::cout << std::endl;
				start = line + 1;
			}
		}
		start = 0;
	}
	double answer = seeds[0];
	for (auto i : seeds)
	{
		std::cout << "seed: " << i << std::endl;
		if (i < answer)
			answer = i;
	}
	std::cout << "Answer: " << std::to_string(answer) <<std::endl;
	ifs.close();
}
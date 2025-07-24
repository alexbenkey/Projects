#include <string>
#include <iostream> 
#include <fstream>
#include <vector>
#include <sstream>

int node = 0;


std::vector<std::string> split(std::string text, char delim) {
    std::string line;
    std::vector<std::string> vec;
    std::stringstream ss(text);
    while(std::getline(ss, line, delim)) {
        vec.push_back(line);
    }
    return vec;
}


int main (void)
{
	std::ifstream ifs;
	std::string buffer;
	std::vector<std::string> data;
	std::vector<std::string> my_nums;
	std::vector<std::string> winning;
	int hits = 0;
	int total= 0;
	int temp = 0;
	int arr[196];

	for (int i = 0; i < 196; i++)
		arr[i] = 1;
	ifs.open("input.txt");
	while(std::getline(ifs, buffer)){
		data = split(buffer, ':');
		data = split(data[1], '|');
		my_nums = split(data[0], ' ');
		winning = split(data[1], ' ');
		my_nums.erase(my_nums.begin());
		winning.erase(winning.begin());
		for (int i = 0; i < my_nums.size(); i++){
			if (my_nums[i].empty())
				my_nums.erase(my_nums.begin()+i);
			//std::cout << "mynums, position " << i << ": " << my_nums[i] <<std::endl;
		}
		for (int i = 0; i < winning.size(); i++){
			if (winning[i].empty())
				winning.erase(winning.begin()+i);
			//std::cout << "mynums, position " << i << ": " << my_nums[i] <<std::endl;
		}
		// for (auto i : my_nums){
		// 	if (i.empty()){
		// 		std::cout << "found space: [" << i << "], iterator: " << iterator << std::endl; 
		// 		my_nums.erase(my_nums.begin()+iterator);
		// 	}
		// 	iterator++;
		// }
		// iterator = 0;
		// for (auto j : my_nums){
		// 	if (j == " ")
		// 		my_nums.erase(my_nums.begin()+iterator);
		// 	iterator++;
		// }
		int p = 0;
		while (p < arr[node])
		{
			for (auto i : my_nums){
				for (auto j : winning){
					if (i == j){
						hits++;
					}
				}
			}
			int k = 0;
			while (hits)
			{
				k++;
				arr[node + k] += 1;
				hits--;
			}
			p++;
		}
		temp = 0;
		node++;
	}
	for (auto i : arr)
	{
		std::cout << i << std::endl;
		total += i;
	}
	std::cout << "total: " << total << std::endl;
	ifs.close();
	return 0;
}	
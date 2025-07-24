#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>

std::ifstream ifs("intput.txt");

int main (void){
	std::string digits = "123456789";
	std::string words[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	int first;
	int firstval = 0;
	int second;
	int store = 0;
	int total = 0;
	std::string buffer;
	while (std::getline(ifs, buffer)){
		first = buffer.length();
		for (int i = 0; i < 9; i++){
			if (first > buffer.find(digits[i])){
				first = buffer.find(digits[i]);
				firstval = (i + 1);
			}
		}
		for (int j = 0; j < 9; j++){
			if (first > buffer.find(words[j])){
				first = buffer.find(words[j]);
				firstval = (j + 1);
			}
		}
		first = firstval * 10;
		for (int i = 0; i < 9; i++)
			std::reverse(words[i].begin(), words[i].end());
		std::reverse(buffer.begin(), buffer.end());
		second = buffer.length();
		for (int i = 0; i < 9; i++){
			if (second > buffer.find(digits[i])){
				second = buffer.find(digits[i]);
				firstval = (i + 1);
			}
		}
		for (int j = 0; j < 9; j++){
			if (second > buffer.find(words[j])){
				second = buffer.find(words[j]);
				firstval = (j + 1);
			}
		}
		second = firstval;
		std::cout << std::to_string(first + second) << std::endl;
		total += (first + second);
		for (int i = 0; i < 9; i++)
			std::reverse(words[i].begin(), words[i].end());
	}
	std::cout << "total: " << total << std::endl;
}
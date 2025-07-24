#include <string>
#include <iostream>
#include <cstring>

int main (void)
{
	std::string string1 = "eightwothree";
	std::string subst = "two";
	std::string test = "one";

	std:: cout << string1.find_first_of(subst)<< std::endl;
	std:: cout << string1.find_first_of(test)<< std::endl;
}
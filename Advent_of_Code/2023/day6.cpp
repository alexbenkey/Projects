#include <iostream>
#include <fstream>
#include <string>

int main (int argc, char **argv){
	long time = std::stol(argv[1]);
	long  winning = std::stol(argv[2]);
	long vict = 0;
	long racing = 0;
	for  (int j = 0; j < time; j++)
	{
		racing = time - j;
		if (racing * j > winning)
			vict++;  
	}
	std::cout << "vict: " << std::to_string(vict) << std::endl;
}
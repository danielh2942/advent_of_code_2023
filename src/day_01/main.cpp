#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char** argv) {
	if(argc == 1) {
		std::cout << "You need to pass a filename!" << std::endl;
		return 1;
	}

	std::ifstream inp{argv[1]};
	if(!inp.is_open()) {
		std::cout << "Error!" << std::endl;
		return 1;
	}
	
	std::string buff;
	while(std::getline(inp, buff)) {
		// Do something with buff here
	}

	inp.close();
}

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

size_t split(std::string const& txt, std::vector<std::string> & vec, char delim) {
	size_t pos = txt.find(delim);
	size_t initialPos = 0;
	vec.clear();

	while(pos != std::string::npos) {
		vec.push_back(txt.substr(initialPos, pos - initialPos));
		initialPos = pos + 1;
		pos = txt.find(delim, initialPos);
	}

	vec.push_back(txt.substr(initialPos, std::min(pos, txt.size()) - initialPos));

	return vec.size();
}

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
	
	// Part A:
	// 12 red 13 green 14 blue
	int id = 1;
	int id_sum = 0;
	// Part B
	// Get A * B * C and add it to each
	int pow_sum = 0;
	std::string buff;
	std::vector<std::string> vector{};
	while(std::getline(inp, buff)) {
		int minA = 0;
		int minB = 0;
		int minC = 0;
		split(buff, vector, ' ');
		// Part A
		bool success = true;
		for(size_t i = 2; (i < vector.size() - 1); i += 2) {
			int num = std::stoi(vector[i]);
			switch(vector[i+1][0]) {
				case 'r':
					if(num > 12) {
						success = false;
					}
					minA = std::max(minA, num);
					break;
				case 'g':
					if(num > 13) {
						success = false;
					}
					minB = std::max(minB, num);
					break;
				case 'b':
					if (num > 14) {
						success = false;
					}
					minC = std::max(minC, num);
					break;
			}	
		}
		if(success) id_sum += id;
		id++;
		pow_sum += (minA * minB * minC);
	}

	inp.close();
	std::cout << "Part A: " << id_sum << std::endl;
	std::cout << "Part B: " << pow_sum << std::endl;
	return 0;
}

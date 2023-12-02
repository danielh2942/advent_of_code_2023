#include <algorithm>
#include <charconv>
#include <fstream>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

size_t split_view(std::string_view const& txt, std::vector<std::string_view> & vec, char delim) {
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
	unsigned long id_sum = 0;
	// Part B
	// Get A * B * C and add it to each
	unsigned long pow_sum = 0;
	std::string buff;
	std::vector<std::string_view> vector{};
	while(std::getline(inp, buff)) {
		int minA = 0;
		int minB = 0;
		int minC = 0;
		split_view(buff, vector, ' ');
		for(size_t i = 2; (i < vector.size() - 1); i += 2) {
			int num = 0;
			std::from_chars(vector[i].data(), vector[i].data() + vector[i].size(),num);
			switch(vector[i+1][0]) {
				case 'r':
					minA = std::max(minA, num);
					break;
				case 'g':
					minB = std::max(minB, num);
					break;
				case 'b':
					minC = std::max(minC, num);
					break;
			}	
		}
		if((minA <= 12) && (minB <= 13) && (minC <= 14)) id_sum += id;
		id++;
		pow_sum += (minA * minB * minC);
	}

	inp.close();
	std::cout << "Part A: " << id_sum << std::endl;
	std::cout << "Part B: " << pow_sum << std::endl;
	return 0;
}

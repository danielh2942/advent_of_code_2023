#include <cstddef>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int get_num(std::string const& inp) {
	int val = 0;
	for(size_t i = 0; i < inp.length(); i++) {
		if(inp[i] >= '0' && inp[i] <='9') {
			val += ((inp[i] - '0') * 10);
			break;
		}
	}
	for(size_t i = inp.length() - 1; i >= 0; i--) {
		if(inp[i] >= '0' && inp[i] <='9') {
			val += ((inp[i] - '0'));
			break;
		}
	}
	return val;
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
	// TLDR: get first digit in line and last digit in line then make
	// two digit number 00-99 comprised of (first * 10) + last
	//
	// Part B:
	// replace one, two, three ,with 1,2,3 etc.
	// do the same calculation
	std::string buff;
	int count = 0;

	std::vector<std::string> a{"zero","one","two","three","four","five","six","seven","eight","nine"};
	std::vector<std::string> b{"0","1","2","3","4","5","6","7","8","9"}; 

	size_t lowest_idx = 9999999999;
	int count_b = 0;
	while(std::getline(inp, buff)) {
		count += get_num(buff);
		

		// Part B
		bool modifications = true;
		while(modifications) {
			lowest_idx = SIZE_MAX;
			modifications = false;
			for(size_t i = 0; i < 10; i++) {
				auto found = buff.find(a[i]);
				if(found != std::string::npos) {
					lowest_idx = std::min(lowest_idx, found);
				}
			}

			if(lowest_idx == std::string::npos) continue;

			for(size_t i = 0; i < 10; i++) {
				auto found = buff.find(a[i]);
				if(found == std::string::npos) continue;
				if(found == lowest_idx) {
					std::string tmp = b[i] + a[i][a[i].length() - 1];
					buff.replace(found, a[i].size(), tmp);
					modifications = true;
				}
			}
		}
		
		count_b += get_num(buff);
	}

	std::cout << "Part A: " << count << std::endl;
	std::cout << "Part B: " << count_b << std::endl;
	inp.close();
	return 0;
}

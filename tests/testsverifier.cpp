#include <iostream>
#include <filesystem>
#include <string>
#include <vector>

namespace fs = std::filesystem;

size_t split(std::vector<std::string>& elems, const std::string& str, char delim) {
	std::size_t previous = 0;
	std::size_t current = str.find(delim);
	while (current != std::string::npos) {
		if (current > previous) {
			elems.push_back(str.substr(previous, current - previous));
		}
		previous = current + 1;
		current = str.find(delim, previous);
	}
	if (previous != str.size()) {
		elems.push_back(str.substr(previous));
	}
	return elems.size();
}

const std::string prefix
#if    defined(_DEBUG)
= "Debug\\"
#elif  defined(_RELEASE)
= "Release\\"
#endif
;
const std::string suffix
#ifdef _WIN32
= ".exe"
#endif
;

int main(int argc, char* argv[]) {

	if (argc<=1) {
		std::cout << "Usage: testverifier <test executables;...>" << std::endl;
		return 0;
	}

	std::cout << fs::current_path() << std::endl;
	std::vector<std::string> elems;
	if (split(elems, argv[1], ';')) {
		for (auto& exe : elems) {
			if (exe.empty()) continue;
			std::string path = prefix + exe + suffix;
			int r = system(path.c_str());
			if (r == 0) {
				std::cout << "PASS: ";
			}
			else {
				std::cout << "FAIL: ";
			}
			std::cout << path << std::endl;
		}
	}
	return 0;
}


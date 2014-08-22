#pragma once

#include <vector>
#include <fstream>
#include <streambuf>

inline std::vector<char> file2vector(const std::string& fileName) {
	std::ifstream f(fileName.c_str(), std::ios::binary);
	return std::vector<char>(std::istreambuf_iterator<char>(f), std::istreambuf_iterator<char>());
}

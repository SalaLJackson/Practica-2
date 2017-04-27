#include <fstream>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <vector>
#include "Element_List.h"

int main()
{
	Elements llistat;

	std::string str = "Meet the new boss...";
	std::hash<std::string> hash_fn;
	size_t str_hash = hash_fn(str);
	std::cout << str_hash << '\n';

	return 0;
}
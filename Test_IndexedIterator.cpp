//--------------------------------------------------------------------
//
//	Indexed iterator library for modern C++
//
//	Copyright (C) 2017 Ryo Suzuki <reputeless@gmail.com>
//
//	For the license information refer to IndexedIterator.hpp.
//
//--------------------------------------------------------------------

# include <iostream>
# include <vector>
# include <string>
# include <map>
# include "IndexedIterator.hpp"

using namespace siv;

int main()
{
	const std::vector<int> v = { 0, 100, 200, 300, 400, 500 };
	
	for (auto [i, n] : Indexed(v))
	{
		std::cout << i << ": " << n << "\n"; 
	}  
	
	const std::string s = "Hello, world!";
	
	for (auto [i, ch] : Indexed(s))
	{
		std::cout << i << ": " << ch << "\n"; 
	}
	
	const std::map<std::string, std::string> m = { {"aaa", "AAA" }, {"bbb", "BBB" }, {"ccc", "CCC" } };
	
	for (auto [i, p] : Indexed(m))
	{
		std::cout << i << ": " << p.first << ", " << p.second << "\n"; 
	}
}

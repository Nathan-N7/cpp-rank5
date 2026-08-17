/* ************************************************************************** */
/*                                                                            */
/*   main.cpp                                                               */
/*                                                                            */
/*   Module 08 - ex00 : Easy find - tests                                   */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main()
{
	std::cout << "=== easyfind on std::vector<int> ===" << std::endl;
	std::vector<int> vec;
	for (int i = 0; i < 10; ++i)
		vec.push_back(i * 2); // 0 2 4 6 8 10 12 14 16 18

	try
	{
		std::vector<int>::iterator it = easyfind(vec, 8);
		std::cout << "Found 8 at index " << (it - vec.begin()) << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n=== easyfind: value not present (should throw) ===" << std::endl;
	try
	{
		std::vector<int>::iterator it = easyfind(vec, 99);
		std::cout << "Found 99: " << *it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught exception as expected: " << e.what() << std::endl;
	}

	std::cout << "\n=== easyfind on std::list<int> ===" << std::endl;
	std::list<int> lst;
	lst.push_back(42);
	lst.push_back(21);
	lst.push_back(1337);

	try
	{
		std::list<int>::iterator it = easyfind(lst, 21);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n=== easyfind on std::deque<int> ===" << std::endl;
	std::deque<int> deq;
	deq.push_back(5);
	deq.push_back(15);
	deq.push_back(25);

	try
	{
		std::deque<int>::iterator it = easyfind(deq, 15);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n=== easyfind on a const container ===" << std::endl;
	const std::vector<int> cvec(vec);
	try
	{
		std::vector<int>::const_iterator it = easyfind(cvec, 12);
		std::cout << "Found (const): " << *it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	return 0;
}

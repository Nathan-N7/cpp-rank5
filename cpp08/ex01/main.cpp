/* ************************************************************************** */
/*                                                                            */
/*   main.cpp                                                               */
/*                                                                            */
/*   Module 08 - ex01 : Span - tests                                        */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main()
{
	std::cout << "=== Example straight from the subject ===" << std::endl;
	Span sp(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl; // expected 2
	std::cout << sp.longestSpan() << std::endl;  // expected 14

	std::cout << "\n=== Exception: adding past capacity ===" << std::endl;
	try
	{
		sp.addNumber(42);
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Exception: span on empty / one-element Span ===" << std::endl;
	Span tiny(3);
	try
	{
		tiny.shortestSpan();
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	tiny.addNumber(1);
	try
	{
		tiny.longestSpan();
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Copy constructor / assignment operator ===" << std::endl;
	Span copySp(sp);
	Span assignSp(1);
	assignSp = sp;
	std::cout << "copySp shortest/longest: " << copySp.shortestSpan()
			   << " / " << copySp.longestSpan() << std::endl;
	std::cout << "assignSp shortest/longest: " << assignSp.shortestSpan()
			   << " / " << assignSp.longestSpan() << std::endl;

	std::cout << "\n=== Filling a Span using a range of iterators ===" << std::endl;
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(100);
	vec.push_back(53);
	vec.push_back(-10);
	vec.push_back(24);

	Span rangeSpan(vec.size());
	rangeSpan.addNumber(vec.begin(), vec.end());
	std::cout << "Shortest span: " << rangeSpan.shortestSpan() << std::endl;
	std::cout << "Longest span:  " << rangeSpan.longestSpan() << std::endl;

	std::cout << "\n=== Stress test with 10 000 numbers ===" << std::endl;
	std::srand(static_cast<unsigned int>(std::time(0)));

	std::vector<int> big;
	for (int i = 0; i < 10000; ++i)
		big.push_back(std::rand());

	Span bigSpan(10000);
	bigSpan.addNumber(big.begin(), big.end());

	std::cout << "Numbers stored: 10000" << std::endl;
	std::cout << "Shortest span: " << bigSpan.shortestSpan() << std::endl;
	std::cout << "Longest span:  " << bigSpan.longestSpan() << std::endl;

	return 0;
}

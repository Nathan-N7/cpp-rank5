/* ************************************************************************** */
/*                                                                            */
/*   main.cpp                                                               */
/*                                                                            */
/*   Module 08 - ex02 : Mutated abomination - tests                         */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <stack>

int main()
{
	std::cout << "=== MutantStack (test straight from the subject) ===" << std::endl;
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	// [...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	// MutantStack still behaves like a normal std::stack
	std::stack<int> s(mstack);
	std::cout << "std::stack built from MutantStack, size: " << s.size() << std::endl;

	std::cout << "\n=== Same sequence of operations on a std::list, for comparison ===" << std::endl;
	std::list<int> lstack;

	lstack.push_back(5);
	lstack.push_back(17);

	std::cout << lstack.back() << std::endl;

	lstack.pop_back();

	std::cout << lstack.size() << std::endl;

	lstack.push_back(3);
	lstack.push_back(5);
	lstack.push_back(737);
	lstack.push_back(0);

	std::list<int>::iterator lit = lstack.begin();
	std::list<int>::iterator lite = lstack.end();

	++lit;
	--lit;
	while (lit != lite)
	{
		std::cout << *lit << std::endl;
		++lit;
	}

	std::cout << "\n=== Extra: const iterators + reverse iterators ===" << std::endl;
	const MutantStack<int> constStack(mstack);
	for (MutantStack<int>::const_iterator cit = constStack.begin(); cit != constStack.end(); ++cit)
		std::cout << *cit << " ";
	std::cout << std::endl;

	for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit)
		std::cout << *rit << " ";
	std::cout << std::endl;

	return 0;
}

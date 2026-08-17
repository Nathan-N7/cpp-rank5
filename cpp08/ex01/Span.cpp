/* ************************************************************************** */
/*                                                                            */
/*   Span.cpp                                                               */
/*                                                                            */
/*   Module 08 - ex01 : Span                                                */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <stdexcept>
#include <climits>

Span::Span(unsigned int n) : _maxSize(n)
{
	_numbers.reserve(n);
}

Span::Span(const Span &other) : _maxSize(other._maxSize), _numbers(other._numbers)
{
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_maxSize = other._maxSize;
		_numbers = other._numbers;
	}
	return *this;
}

Span::~Span()
{
}

void Span::addNumber(int number)
{
	if (_numbers.size() >= _maxSize)
		throw std::length_error("Span::addNumber: Span is already full");
	_numbers.push_back(number);
}

int Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw std::logic_error("Span::shortestSpan: not enough numbers stored");

	std::vector<int> sorted(_numbers);
	std::sort(sorted.begin(), sorted.end());

	int minDiff = INT_MAX;
	for (std::vector<int>::size_type i = 1; i < sorted.size(); ++i)
	{
		int diff = sorted[i] - sorted[i - 1];
		if (diff < minDiff)
			minDiff = diff;
	}
	return minDiff;
}

int Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw std::logic_error("Span::longestSpan: not enough numbers stored");

	int minVal = *std::min_element(_numbers.begin(), _numbers.end());
	int maxVal = *std::max_element(_numbers.begin(), _numbers.end());

	return maxVal - minVal;
}

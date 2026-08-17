/* ************************************************************************** */
/*                                                                            */
/*   Span.hpp                                                               */
/*                                                                            */
/*   Module 08 - ex01 : Span                                                */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span
{
	public:
		Span(unsigned int n);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();

		void	addNumber(int number);
		int		shortestSpan() const;
		int		longestSpan() const;

		/*
		** Fills the Span with a range of iterators in a single call,
		** instead of looping over addNumber(). Works with the iterator
		** type of any container (vector, list, array, ...).
		*/
		template <typename InputIterator>
		void addNumber(InputIterator begin, InputIterator end)
		{
			for (InputIterator it = begin; it != end; ++it)
				addNumber(*it);
		}

	private:
		Span(); // default constructor disabled: N is mandatory

		unsigned int		_maxSize;
		std::vector<int>	_numbers;
};

#endif

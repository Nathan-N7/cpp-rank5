/* ************************************************************************** */
/*                                                                            */
/*   easyfind.hpp                                                           */
/*                                                                            */
/*   Module 08 - ex00 : Easy find                                           */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>

/*
** easyfind
** ----------------------------------------------------------------------
** Finds the first occurrence of `value` inside `container`.
**
** T is assumed to be a container of integers (vector, list, deque, ...).
** We only need `begin()`, `end()` and `T::iterator` to exist, so any
** sequence container works out of the box.
**
** Returns an iterator to the first element equal to `value`.
** Throws std::runtime_error if the value is not found, mimicking the
** behaviour of std::map::at() / std::vector::at() when something is
** missing/out of range instead of returning end() (which is easy to
** dereference by mistake).
*/
template <typename T>
typename T::iterator easyfind(T &container, int value)
{
	typename T::iterator it = std::find(container.begin(), container.end(), value);

	if (it == container.end())
		throw std::runtime_error("easyfind: value not found in container");
	return it;
}

/* const overload, so the function can also be used on a const container */
template <typename T>
typename T::const_iterator easyfind(const T &container, int value)
{
	typename T::const_iterator it = std::find(container.begin(), container.end(), value);

	if (it == container.end())
		throw std::runtime_error("easyfind: value not found in container");
	return it;
}

#endif

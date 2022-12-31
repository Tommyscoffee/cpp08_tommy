#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <algorithm>
# include <exception>

template < class T >class T::iterator easyfind( T &container, int i)//Tをintのコンテナだとして、第二引数が一番最初に現れるのを探す。もし見つからなかったら、
{
	class T::iterator	result = find(container.begin(), container.end(), goal);

	if (result == container.end())
		throw std::runtime_error("not found");
	return result;
}

#endif
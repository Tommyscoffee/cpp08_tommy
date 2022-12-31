#ifndef SPAN_HPP
# define SPAN_HPP
# include <iostream>
# include <vector>
class Span
{

public:

	Span( void );
	Span( unsigned int strageSize );
	Span( const Span &src );
	~Span( void );

	Span	&operator=( const Span &rhs );

	void			addNumber( unsigned int n );
	void			fillStrage( void );
	void			addByIteratorRange( std::vector<int>::iterator begin,
			std::vector<int>::iterator end);
	unsigned int	shortestSpan( void ) const;
	unsigned int	longestSpan( void ) const;
	unsigned int	size( void ) const;
	unsigned int	maxSize( void ) const;
	unsigned int	spaceLeft( void ) const;

private:

	unsigned int		_storageSize;
	std::vector<int>	_storage;

};

std::ostream	&operator<<( std::ostream &ostr, const Span &instance );

#endif
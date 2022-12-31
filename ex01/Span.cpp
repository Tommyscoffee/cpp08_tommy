#include "Span.hpp"

Span::Span( void ) : _storageSize( 0 )
{
	std::cout << "Span( void ) called "<< std::endl;
}

Span::Span( unsigned int storageSize) : _storageSize( storageSize )
{
	std::cout << "Span( unsigned int _storageSize ) called  "<< std::endl;
}

Span::Span( Span const &src )
{
	std::cout << "Span( Span const &src ) called "<< std::endl;
	*this = src;
	return ;
}

Span::~Span( void )
{
	std::cout << "Destructor called" << std::endl;
	return;
}

Span &	Span::operator=( Span const & obj )
{
	if (this != &obj)
	{
		this->_storageSize = obj._storageSize;
		this->_storage = obj._storage;
	}
	return *this;
}

std::ostream &	operator<<( std::ostream & ostr, Span const & instance)
{
	int	shortest = instance.shortestSpan();
	int	longest = instance.longestSpan();

	ostr << "Span of max size " << instance.maxSize() << " contains "
		<< instance.size() << " numbers, shortest span is "
		<< shortest << " and longest is " << longest;
	return ostr;
}


// member functions

void	Span::addNumber( unsigned int n)
{
	if (this->_storage.size() == this->_storageSize)
		throw std::out_of_range("*Error* cannot add cause strage is full.");
	std::cout << "addNumber called " << n << std::endl;
	_storage.push_back( n );
}

unsigned int		Span::shortestSpan( void ) const
{
	std::vector< int >				tmp = this->_storage;
	int								res_span = -1;
	std::vector< int >::iterator	it;

	if ( this->_storage.size() <= 1)
		throw std::runtime_error("*Error* there is no span");
	sort(tmp.begin(), tmp.end());
	res_span = *(tmp.begin() + 1) - *tmp.begin();
	if (this->size() == 2)
		return res_span;
	for (it = tmp.begin() + 1; it != tmp.end() -1 && res_span != 0; it++)
	{
		if (*(it + 1) - *it < res_span)
			res_span = *(it + 1) - *it;
	}
	return res_span;
}

void	Span::fillStrage( void )
{
	unsigned int leftStorage = this->spaceLeft();
	for ( unsigned int i = 0; i < leftStorage; i++)
		this->addNumber( rand() % (this->maxSize() * 10));
}

unsigned int		Span::longestSpan( void ) const
{
	std::vector< int >	tmp = this->_storage;

	if (this->_storage.size() <= 1)
		throw std::runtime_error("*Error* thire is no span");
	sort(tmp.begin(), tmp.end());
	return *(tmp.end() - 1) - *tmp.begin();
}


unsigned int	Span::size( void ) const
{
	return _storage.size();
}

unsigned int	Span::maxSize( void ) const
{
	return _storageSize;
}

unsigned int	Span::spaceLeft( void ) const
{
	return maxSize() - size();
}

// void Span::randomFill( void )
// {

// }
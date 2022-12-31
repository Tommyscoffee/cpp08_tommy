#include "Span.hpp"

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	
	//エラー処理
	{
		Span err = Span();
		try
		{
			std::cout << err.shortestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	
	// エラー処理　同じ値
	{
		Span err = Span(2);
		err.addNumber(1);
		err.addNumber(1);
		try
		{
			std::cout << err.shortestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	//ランダムなテスト
	{
		Span random(50);
		random.fillStrage();
		std::cout << random << std::endl;

		std::cout << random.shortestSpan() << std::endl;
		std::cout << random.longestSpan() << std::endl;

	}
	return 0;
}
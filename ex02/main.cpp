#include <stack>
#include <iostream>
#include "MutantStack.hpp"
#include <list>
int main()
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
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
	std::stack<int> s(mstack);
	{
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;

		std::cout << "mstack content (bottom to top): " << std::endl;
		while(it != ite)
		{
			std::cout << *it;
			if (++it == ite)
				std::cout << std::endl;
			else
				std::cout << ", ";
		}
	}

	std::cout << "---" << std::endl;
	{
		std::list<int> test_list;
		test_list.push_back(5);
		test_list.push_back(17);
		std::list<int>::reverse_iterator reiter = test_list.rbegin();
		std::cout << "    " << *reiter << std::endl;
	}

	return 0;
}

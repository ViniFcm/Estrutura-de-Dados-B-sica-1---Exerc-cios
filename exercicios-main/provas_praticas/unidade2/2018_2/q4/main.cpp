#include "LinkedList.h"
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

void test(vector<string> inputs)
{
	LinkedList l;

	for(string s : inputs)
	{
		l.insertBegin(s);	
	}

	int i = inputs.size()-1;
	for(auto node = l.getFirst(); node != nullptr; node = node->getNext() )
	{
		assert( node->getValue() == inputs[i] );
		--i;
	}	

	cout << "Antes de inverter: \n";
	l.print();

	l.invert();

	i = 0;
	for(auto node = l.getFirst(); node != nullptr; node = node->getNext() )
	{
		assert( node->getValue() == inputs[i] );
		++i;
	}

	cout << "Após inverter: \n";
	l.print();
}

int main(void)
{
	vector<vector<string>> inputs = {
		{"X"},
		{"XX", "YY"},
		{"A", "B", "C", "D", "E", "F", "G"},
		{"AA", "BB", "CC", "DD", "EE", "FF", "GG"}
	};

	for(auto input : inputs)
	{
		test(input);	
	}

	cout << "\nAll tests passed \n";

	return 0;
}

#include <cassert>
#include <iostream>
#include <string>

using namespace std;

bool isAnagram(string s1, string s2)
{
	return false;
}

int main(void)
{
	// São anagramas entre si
	assert( isAnagram("", "") == true );
	assert( isAnagram("A", "A") == true );
	assert( isAnagram("AB", "BA") == true );
	assert( isAnagram("AVAL", "VALA") == true );
	assert( isAnagram("LAVA", "VALA") == true );
	assert( isAnagram("FENO", "FONE") == true );
	assert( isAnagram("AMERIC", "MERICA") == true );
	assert( isAnagram("IRACEMA", "AMERICA") == true );
	assert( isAnagram("IRACEMA", "IRACEMA") == true );
	assert( isAnagram("AMERICA", "AMERICA") == true );
	
	// Não são anagramas entre si
	assert( isAnagram("AMERICA", "MER") == false );
	assert( isAnagram("RICA", "AMARACA") == false );
	assert( isAnagram("", "AMARACA") == false );
	assert( isAnagram("RICA", "") == false );
	assert( isAnagram("BOLA", "BALA") == false );

	std::cout << "Q3_Anagram - Passou em todos os testes!" << std::endl;

	return 0;
}

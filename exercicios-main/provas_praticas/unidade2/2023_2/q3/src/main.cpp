#include <iostream>
#include <stack>
#include <string>

int main() 
{
  std::stack<std::string> pilha;

  std::string v[] = {"alpha", "bravo", "charlie", "delta", "eagle"};

  for(auto s : v)
  {
    std::cout << "Empilhando: " << s << std::endl;
    pilha.push(s);
    std::cout << " - Tamanho da pilha: " << pilha.size() << std::endl;
  }
  
  while( !pilha.empty() )
  {
    std::cout << "Desempilhando: " << pilha.top() << std::endl;
    pilha.pop();
    std::cout << " - Tamanho da pilha: " << pilha.size() << std::endl;
  }

  return 0;
}

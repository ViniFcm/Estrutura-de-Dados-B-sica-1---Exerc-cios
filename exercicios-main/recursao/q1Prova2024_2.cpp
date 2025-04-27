#include <iostream>
int contarDigitos(int n, int d){
  if(n >= 0 && n<=9){
    if(n == d){
      return 1;
    }
    return 0;
  }
  else if(n%10 == d){
    return 1 + contarDigitos(n/10, d);
  }
  else{
    return 0 + contarDigitos(n/10, d);
  }
  return -1;
}
int main(){
  int check = 0;
  if(contarDigitos(1231231, 1) == 3)
    check++;
  if(contarDigitos(3423423, 1) == 0)
    check++;
  if(contarDigitos(24532341, 2) == 2)
    check++;

  if(check == 3){
    std::cout<<"Passou! Ganhou 1.5 pontos na média!";
  }
  else{
    std::cout<<"Não Passou!";
  }
}
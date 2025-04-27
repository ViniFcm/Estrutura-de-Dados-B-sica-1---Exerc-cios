#include <iostream>
int maiorDigito(int n){
  if(n >= 0 && n <= 9){
    return n;
  }
  
    int maior = n%10;
    int segundoDigito = ((n%100) - (n%10))/10;
    if(maior > segundoDigito){
      int novo = (n/10) - segundoDigito + n%10;
      return maiorDigito(novo);
    }
    return maiorDigito(n/10);
  }
  


int main(){
  int check = 0;
  if(maiorDigito(122311) == 3)
    check++;
  if(maiorDigito(3423423) == 4)
    check++;
  if(maiorDigito(245541) == 5)
    check++;

  if(check == 3){
    std::cout<<"Passou! Ganhou 1.5 pontos na média!";
  }
  else{
    std::cout<<"Não Passou!";
  }
}
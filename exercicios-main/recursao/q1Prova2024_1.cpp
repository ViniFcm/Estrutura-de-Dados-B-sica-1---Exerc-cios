#include <iostream>
bool consecutivos(int n){
  if(n < 10){
    return false;
  }
  int segundoDigito = ((n%100) - (n%10))/10; // 12 = 20
  if(n%10 == segundoDigito)
  {
    return true;
  }
  return consecutivos(n/10);
}

int main(){
  int check = 0;
  if(consecutivos(1223141) == true)
    check++;
  if(consecutivos(3423423) == false)
    check++;
  if(consecutivos(245541) == true)
    check++;

  if(check == 3){
    std::cout<<"Passou! Ganhou 1.5 pontos na média!";
  }
  else{
    std::cout<<"Não Passou!";
  }
}
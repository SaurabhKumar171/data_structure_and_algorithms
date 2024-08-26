#include <algorithm>
#include <iostream>
using namespace std;


bool checkNum(int i , int num){
  if( i == 1){
    return true;
  }
  else if(num % i == 0){
    return false;
  }

  return checkNum(i - 1, num);
}

bool checkPrime(int num){
  //your code goes here

  return checkNum(num - 1, num);

}

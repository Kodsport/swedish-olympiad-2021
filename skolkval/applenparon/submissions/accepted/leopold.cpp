#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, P;
  cin>>A>>P;
  
  int price_A = A*7;
  int price_P = P*13;
  
  if(price_A > price_P){
    cout<<"Axel"<<endl;
  }else if(price_A < price_P){
    cout<<"Petra"<<endl;
  }else if (price_A == price_P){
    cout<<"lika"<<endl;
  }
  return 0;
}

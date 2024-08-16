#include <iostream>
#include<stack>
using namespace std;

void explainStack(){
  stack<int> st;

  st.push(117);
  st.push(27);
  st.push(74);
  st.push(72);
  st.push(77);

  while(st.empty() == false){
      cout << st.top() << " ";
      st.pop();
  }
}
#include <iostream>
using namespace std;

bool even(char c){
  return c=='0' || c=='2' || c=='4' || c=='6' || c=='8';
}

int main(){
  string s;
  cin>>s;

  char end = s[s.length()-1];

  for (int i=0; i<=s.length()-2; i++) {
    if (even(s[i]) && s[i]<end) {
      s[s.length()-1] = s[i];
      s[i] = end;
      cout<<s<<endl;
      return 0;
    }
  }

  for (int i=s.length()-2; i>=0; i--) {
    if (even(s[i])) {
      s[s.length()-1] = s[i];
      s[i] = end;
      cout<<s<<endl;
      return 0;
    }
  }

  cout<<"-1"<<endl;
}

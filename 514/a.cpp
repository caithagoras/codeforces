#include <iostream>
using namespace std;

int main(){
  string s;
  string str = "";
  bool first = true;
  cin>>s;
  for (int i=0; i<s.length(); i++){
    int c = (int)(s[i]-'0');
    if (c<=4) {
      str += (char)(c+'0');
      first = false;
    }
    else if (c<=8) {
      str += (char)(9-c+'0');
      first = false;
    }
    else if (first) {
      str += '9';
      first = false;
    }
    else {
      str += '0';
    }
  }
  cout<<str<<endl;
}

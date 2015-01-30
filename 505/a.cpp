#include <iostream>
using namespace std;

bool p(string s){
  int i = 0;
  int j = s.length()-1;
  while (i<j) {
    if (s[i] != s[j]) return false;
    i++;
    j--;
  }
  return true;
}

int main() {
  string s;
  cin>>s;

  for (int i=0;i<=s.length();i++) {
    char c;
    if (s.length() % 2 == 1) {
      if (i <= s.length()/2) c = s[s.length()-i-1];
      else c=s[s.length()-i];
    }
    else {
      if (i < s.length()/2) c = s[s.length()-i-1];
      else if (i == s.length()/2) c = 'a';
      else c = s[s.length()-i];
    }
    string str = s.substr(0,i) + c + s.substr(i);
    if (p(str)) {
      cout<<str<<endl;
      return  0;
    }
  }
  cout<<"NA"<<endl;
}

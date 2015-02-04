#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int n;
string s[100];
bool graph[26][26];

int ord(char c) {
  return (int)(c-'a');
}

void reject() {
  printf("Impossible\n");
  exit(0);
}

int main() {
  cin>>n;
 
  for (int i=0; i<n; i++)
    cin>>s[i];

  for (int i=0; i<n-1; i++)
    for (int j=i+1; j<n; j++) {
      int k=0;
      while (k<s[i].length() && k<s[j].length() && s[i][k]==s[j][k]) k++;
      if (k==s[i].length() || k==s[j].length()) {
        if (s[i].length()>s[j].length()) reject();
      }
      graph[ord(s[i][j])][ord(s[j][k])] = true;
    }

  
}

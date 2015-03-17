#include <iostream>
#include <cstring>
using namespace std;

int ord(char c){
  return (int)(c-'a');
}

int main() {
  int n;
  cin>>n;
  string s,t;
  cin>>s>>t;

  int m[26][26];
  memset(m, 0, sizeof(m));
    
  int d=0;
  for (int i=0; i<n; i++)
    if (s[i] != t[i]) {
      d++;
      int x = ord(s[i]);
      int y = ord(t[i]);
      if (m[x][y] == 0) {
        m[x][y] = i+1;
      }
    }

  bool found = false;
  int ii,jj;
  for (int i=0; i<26; i++) {
    for (int j=0; j<26; j++)
      if (i!=j && m[i][j] != 0 && m[j][i] != 0) {
        found = true;
        ii = m[i][j];
        jj = m[j][i];
        break;
      }
    if (found) break;
  }

  if (found) {
    cout<<d-2<<endl;
    cout<<ii<<" "<<jj<<endl;
    return 0;
  }

  found = false;
  for (int i=0; i<26; i++) {
    for (int j=0; j<26; j++)
      if (i!=j && m[i][j]!=0) {
        bool canswap = false;
        int kk;
        for (int k=0; k<26; k++)
          if (m[j][k]!=0) {
            canswap = true;
            kk = k;
            break;
          }
        if (canswap) {
          found = true;
          ii = m[i][j];
          jj = m[j][kk];
          break;
        }
      }
    if (found)
      break;
  }

  if (found) {
    cout<<d-1<<endl;
    cout<<ii<<" "<<jj<<endl;
  }
  else {
    cout<<d<<endl;
    cout<<"-1 -1"<<endl;
  }
}

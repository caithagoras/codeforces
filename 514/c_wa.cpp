#include <iostream>
#include <cstdio>
#include <unordered_set>
using namespace std;

unordered_set<string> pre;
unordered_set<string> post;
unordered_set<string> mp;

int n,m;

int main(){
  cin>>n>>m;

  string s;
  for (int i=0; i<n; i++) {
    cin>>s;
    for (int j=0; j<=s.length(); j++){
      pre.insert(s.substr(0,j));
      post.insert(s.substr(j));
      mp.insert(s);
    }
  }

  for (int i=0; i<m; i++) {
    cin>>s;
    if (mp.count(s)) {
      printf("YES\n");
      continue;
    }

    int l=0;
    while (l<=s.length() && pre.count(s.substr(0,l))==1) l++;
    int r=s.length();
    while (r>=0 && post.count(s.substr(r))==1) r--;

    int flag = false;
    for (int j=r; j<=l-1; j++){
      if (j==-1 || j==s.length()) {
        if (mp.count(s)) {
          flag = true;
          break;
        }
        continue;
      }
      string copy = s;

      copy[j] = 'a';
      if (mp.count(copy)) {
        flag = true;
        break;
      }        

      copy[j] = 'b';
      if (mp.count(copy)) {
        flag = true;
        break;
      }

      copy[j] = 'c';
      if (mp.count(copy)) {
        flag = true;
        break;
      }
    }
    if (flag)
      printf("YES\n");
    else
      printf("NO\n");
  }

  
  
}

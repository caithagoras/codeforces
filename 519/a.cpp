#include <iostream>
#include <cstdio>
using namespace std;

int white[5];
int black[5];

int main() {
  for (int i=0; i<8; i++) {
    string s;
    cin>>s;
    for (int j=0; j<8; j++) {
      int k;
      switch (tolower(s[j])) {
      case 'q': k=0; break;
      case 'r': k=1; break;
      case 'b': k=2; break;
      case 'n': k=3; break;
      case 'p': k=4; break;
      default: continue;
      }
      
      if (s[j]>='A' && s[j]<='Z') white[k]++;
      else black[k]++;
    }
  }

  int w = white[0]*9 + white[1]*5 + white[2]*3 + white[3]*3 + white[4]*1;
  int b = black[0]*9 + black[1]*5 + black[2]*3 + black[3]*3 + black[4]*1;

  if (w>b) printf("White\n");
  else if (w<b) printf("Black\n");
  else printf("Draw\n");
}

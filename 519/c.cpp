#include <iostream>
#include <cstdio>
using namespace std;

int main() {
  int x,y;
  cin>>x>>y;

  int n=0;
  while (x>0 && y>0 && x+y>=3) {
    if (x>y) {
      x-=2;
      y--;
      n++;
    }
    else {
      x--;
      y-=2;
      n++;
    }
  }
  printf("%d\n",n);
}

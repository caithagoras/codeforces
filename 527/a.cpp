#include <iostream>
using namespace std;

void swap(long long &x, long long &y) {
  long long t=x;
  x=y;
  y=t;
}

int main() {
  long long x,y;
  cin>>x>>y;

  if (x<y) swap(x,y);
  long long tot = 0LL;
  
  while (x!=0 && y!=0) {
    tot += (x/y);
    x%=y;
    if (x<y) swap(x,y);
  }

  cout<<tot<<endl;
}

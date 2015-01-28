#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(){
  double r,x,y,xx,yy;
  cin>>r>>x>>y>>xx>>yy;
  
  double dist = sqrt((xx-x)*(xx-x)+(yy-y)*(yy-y));

  double n = dist / (2*r);
  if (abs(n - round(n)) < 1e-12)
    printf("%d\n",(int)round(n));
  else {
    printf("%d\n",(int)round(ceil(n)));
  }
}

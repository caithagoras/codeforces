#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int xx, yy;
int n;

double angle(int x, int y){
  x = x - xx;
  y = y - yy;
  if (y < 0) {
    x = -x;
    y = -y;
  }

  if (y == 0) {
    x = abs(x);
  }

  return (double)x/sqrt(x*x+y*y);
}

int main(){
  cin>>n>>xx>>yy;
  int x,y;
  vector<double> f(n, 0);
  for (int i=0; i<n; i++) {
    cin>>x>>y;
    f[i] = angle(x,y);
  }

  sort(f.begin(),f.end());

  int c=1;
  for (int i=1; i<f.size(); i++)
    if (!(fabs(f[i]-f[i-1]) < 1e-10))
      c++;
  cout<<c<<endl;
}

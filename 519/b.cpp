#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int n;

int compare(const vector<int> &x, const vector<int> &y) {
  for (int i=0; i<y.size(); i++)
    if (x[i] != y[i]) return x[i];
  return x[y.size()];
}

int main() {
  cin>>n;
  vector<int> a(n,0);
  vector<int> b(n-1,0);
  vector<int> c(n-2,0);

  for (int i=0;i<n;i++)
    cin>>a[i];
  for (int i=0;i<n-1;i++)
    cin>>b[i];
  for (int i=0;i<n-2;i++)
    cin>>c[i];

  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  sort(c.begin(),c.end());

  printf("%d\n", compare(a,b));
  printf("%d\n", compare(b,c));
}

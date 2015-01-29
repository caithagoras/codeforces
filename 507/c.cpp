#include <iostream>
#include <cstdio>
using namespace std;

long long f(int h, long long n) {
  if (h == 1) return n;
  long long k = 1LL << (h-1);
  if (n <= k) 
    return f(h-1LL, k-n+1LL) + 1LL;
  else
    return f(h-1LL, n-k) + (k<<1);
}

int main(){
  int h;
  long long n;
  cin>>h>>n;
  cout<<f(h, n)<<endl;
}

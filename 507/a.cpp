#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int f[101][10001];
int p[101][10001];

int main() {
  int n,k;
  cin>>n>>k;

  for (int i=1; i<=n; i++) {
    int w;
    cin>>w;
    for (int j=0; j<w; j++) {
      f[i][j] = f[i-1][j];
      p[i][j] = j;
    }

    for (int j=w; j<=k; j++) {
      if (f[i-1][j] > f[i-1][j-w]+1) {
        f[i][j] = f[i-1][j];
        p[i][j] = j;
      }
      else {
        f[i][j] = f[i-1][j-w]+1;
        p[i][j] = j-w;
      }
    }
  }

  int m = f[n][0];
  int u = 3;
  for (int i=1; i<=k ;i++)
    if (f[n][i] > m) {
      m = f[n][i];
      u = i;
    }

  cout<<m<<endl;
  if (m==0) return 0;
  vector<int> ans;
  for (int i=n; i>=1 ;i--)
    if (u != p[i][u]) {
      ans.push_back(i);
      u = p[i][u];
    }
  
  for (int s : ans)
    cout<<s<<" ";
  cout<<endl;
}

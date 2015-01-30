#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int v[30001];
int f[30001][491];

int main() {
  memset(f, -1, sizeof(f));
  
  int n,d;
  cin>>n>>d;
  
  for (int i=0; i<n-1; i++) {
    int x;
    cin>>x;
    v[x]++;
  }

  int pmax;
  cin>>pmax;
  v[pmax]++;
  
  f[d][245] = v[d];
  
  int max_gem = 0;

  for (int i=d; i<pmax; i++)
    for (int j=0; j<=490; j++) {
      if (f[i][j] == -1) continue;
      max_gem = max(max_gem, f[i][j]);
      int l = j+d-245;
      for (int k=-1; k<=1; k++) {
        int next_l = l+k;
        int next_pos = i+next_l;
        if (next_l <=0 || next_pos>pmax) continue;
        f[next_pos][next_l+245-d] = max(f[next_pos][next_l+245-d], f[i][j] + v[next_pos]);
      }
    }

  for (int j=0; j<=490; j++)
    max_gem = max(max_gem, f[pmax][j]);

  cout<<max_gem<<endl;
}

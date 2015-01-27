#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

bool f[1002][1002];

void lose(int k){
  printf("%d\n", k);
  exit(0);
}

int main(){
  int n,m,k;
  int x,y;
  
  cin>>n>>m>>k;
  for (int i=0; i<k; i++){
    cin>>x>>y;
    f[x][y]=true;

    if (f[x][y] && f[x+1][y] && f[x][y+1] && f[x+1][y+1]) lose(i+1);
    if (f[x][y] && f[x+1][y] && f[x][y-1] && f[x+1][y-1]) lose(i+1);
    if (f[x][y] && f[x-1][y] && f[x][y+1] && f[x-1][y+1]) lose(i+1);
    if (f[x][y] && f[x-1][y] && f[x][y-1] && f[x-1][y-1]) lose(i+1);
  }
  cout<<"0"<<endl;
}

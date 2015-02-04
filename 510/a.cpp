#include <iostream>
#include <cstdio>
using namespace std;

int main() {
  int n,m;
  cin>>n>>m;
  for (int i=0; i<m; i++) {
    if (i%2 == 0)
      for (int j=0; j<m; j++) printf("#");
    else if (i%4 == 1) {
      for (int j=0; j<m-1; j++) printf(".");
      printf("#");
    }
    else if (i%4 == 3) {
      printf("#");
      for (int j=0; j<m-1; j++) printf(".");
    }
    cout<<endl;
  }
}

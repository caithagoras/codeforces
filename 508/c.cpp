#include <iostream>
#include <set>
using namespace std;

int main(){
  int m,t,r;
  cin>>m>>t>>r;

  if (r>t) {
    cout<<"-1"<<endl;
    return 0;
  }

  set<int> mp;
  int x;

  for (int i=0; i<m; i++){
    cin>>x;
    int light = 0;
    for (int j=x-1; j>=x-t; j--)
      if (mp.count(j)) light++;

    if (light>=r) continue;

    int j=x-1;
    while (light<r) {
      if (!mp.count(j)) {
        mp.insert(j);
        light++;
      }
      j--;
    }
  }

  cout<<mp.size()<<endl;
}

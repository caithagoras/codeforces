#include <iostream>
using namespace std;

int l[600];
int r[600];
int f[600][600];

bool sub(int start, int end){
  if (start > end)
    return true;

  if (f[start][end] != 0)
    return f[start][end] > 0;

  for (int i=l[start]; i<=r[start]; i++)
    if (i%2 == 1 && end-start>=i/2) {
      int mid = start + i/2;
      if (sub(start+1, mid) && sub(mid+1, end)) {
        f[start][end] = mid;
        return true;
      }
    }

  f[start][end] = -1;
  return false;
}

string construct(int start, int end) {
  if (start > end)
    return "";
  
  int mid = f[start][end];
  return "(" + construct(start+1, mid) + ")" + construct(mid+1, end);
}

int main() {
  int n;
  cin>>n;

  for (int i=0; i<n; i++)
    cin>>l[i]>>r[i];

  if (sub(0,n-1))
    cout<<construct(0, n-1)<<endl;
  else
    cout<<"IMPOSSIBLE"<<endl;

}

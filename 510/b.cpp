#include <iostream>
#include <cstdio>
using namespace std;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

int n,m;
bool visited[51][51];
char v[51][51];

bool sub(int x, int y, int px, int py) {
  visited[x][y] = true;
  for (int k=0; k<4; k++) {
    int xx = x + dx[k];
    int yy = y + dy[k];
    if (xx>=0 && xx<n && yy>=0 && yy<m && v[xx][yy]==v[x][y] && !(xx==px && yy==py)) {
      if (visited[xx][yy]) return true;
      if (sub(xx, yy, x, y)) return true;
    }
  }
  return false;
}

int main(){
  cin>>n>>m;

  string s;
  getline(cin,s);

  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++)
      cin>>v[i][j];
    getline(cin,s);
  }

  for (int i=0; i<n; i++)
    for (int j=0; j<m; j++)
      if (!visited[i][j])
        if (sub(i, j, -1, -1)) {
          printf("Yes\n");
          return 0;
        };

  printf("No\n");
}

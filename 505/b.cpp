#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int v[101][101];
vector<pair<int,int> > graph[101];

int n,m,q;

void sub(int s, int f[], int color, int order) {
  f[s] = order;
  for (int i=0; i<graph[s].size(); i++) {
    if (graph[s][i].second == color && !f[graph[s][i].first])
      sub(graph[s][i].first, f, color, order);
  }
}

void dfs(int color) {
  int order = 0;

  for (int i=1; i<=n ;i++) {
    if (!v[color][i]) {
      order++;
      sub(i, v[color], color, order);
    }
  }
}

int main() {
  cin>>n>>m;

  int x,y,c;
  for (int i=0; i<m; i++) {
    cin>>x>>y>>c;
    graph[x].push_back(pair<int,int>(y,c));
    graph[y].push_back(pair<int,int>(x,c));
  }

  for (int i=1; i<=m; i++)
    dfs(i);

  cin>>q;
  for (int i=0; i<q; i++) {
    cin>>x>>y;
    
    int num = 0;
    for (int j=1; j<=m; j++)
      if (v[j][x] == v[j][y])
        num++;
      
    cout<<num<<endl;
  }
}

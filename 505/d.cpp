#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int n,m;

vector<int> graph[100001];
vector<int> graph_t[100001];
bool visited_dfs0[100001];
bool visited_dfs1[100001];

void check(int s, vector<bool> &visited, vector<int> &nodes) {
  queue<int> q;
  q.push(s);
  visited[s] = true;

  while (!q.empty()) {
    s = q.front();
    q.pop();
    nodes.push_back(s);

    for (int i=0; i<graph[s].size(); i++)
      if (!visited[graph[s][i]]) {
        q.push(graph[s][i]);
        visited[graph[s][i]] = true;
      }
    
    for (int i=0; i<graph_t[s].size(); i++)
      if (!visited[graph_t[s][i]]) {
        q.push(graph_t[s][i]);
        visited[graph_t[s][i]] = true;
      }
  }
}

void dfs(int s, bool visited[], stack<int> &order) {
  visited[s] = true;
  
  for (int i=0; i<graph[s].size(); i++)
    if (!visited[graph[s][i]])
      dfs(graph[s][i], visited, order);

  order.push(s);
}

bool is_single_node(int s, bool visited[]) {
  visited[s] = true;
  for (int i=0; i<graph_t[s].size(); i++)
    if (!visited[graph_t[s][i]]) return false;
  return true;
}

bool contains_cycle(vector<int> &nodes) {
  stack<int> order;
  
  for (auto it = nodes.begin(); it!=nodes.end(); it++)
    if (!visited_dfs0[*it]) dfs(*it, visited_dfs0, order);

  while (!order.empty()) {
    int t = order.top();
    order.pop();
    if (!is_single_node(t, visited_dfs1)) return true;
  }

  return false;
}

int main() {
  cin>>n>>m;
  for (int i=0; i<m; i++) {
    int x,y;
    cin>>x>>y;
    graph[x].push_back(y);
    graph_t[y].push_back(x);
  }

  int ans = 0;
  vector<bool> visited(n+1, false);

  for (int i=1; i<=n; i++)
    if (!visited[i]) {
      vector<int> nodes;
      check(i, visited, nodes);
      if (contains_cycle(nodes)) ans += nodes.size();
      else ans += nodes.size()-1;
    }

  cout<<ans<<endl;
}

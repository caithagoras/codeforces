#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <stack>
#include <vector>
using namespace std;

void reject(){
  printf("NO\n");
  exit(0);
}

int main() {
  map<string, stack<string> > graph;
  map<string, int> indeg;
  map<string, int> outdeg;
  
  int n;
  cin>>n;

  string s;
  for (int i=0; i<n; i++){
    cin>>s;
    string s1 = s.substr(0,2);
    string s2 = s.substr(1,2);
    graph[s1].push(s2);
    graph[s2];
    outdeg[s1]++;
    outdeg[s2];
    indeg[s2]++;
    indeg[s1];
  }

  // Find Start
  bool has_start = false;
  bool has_end = false;
  string start;
  for (auto it=indeg.begin(); it!=indeg.end(); it++){
    int id = it->second;
    int od = outdeg[it->first];
    if (od - id == 1) {
      if (!has_start) { has_start = true; start = it->first; }
      else reject();
    }
    else if (id - od == 1) {
      if (!has_end) { has_end = true; }
      else reject();
    }
    else if (id != od) reject();
  }

  if (!has_start && !has_end) start = indeg.begin()->first;
  else if (!has_start || !has_end) reject();

  // Find Eulerian Path
  vector<string> path;
  stack<string> v;
  string current = start;
  while (!(graph[current].empty() && v.empty())) {
    if (graph[current].empty()) {
      path.push_back(current);
      current = v.top();
      v.pop();
    }
    else {
      v.push(current);
      string next = graph[current].top();
      graph[current].pop();
      current = next;
    }
  }

  for (auto it=graph.begin(); it!=graph.end(); it++)
    if (!it->second.empty()) reject();

  path.push_back(current);
  cout<<"YES"<<endl;
  
  char ans[n+3];
  for (int i=0; i<n+1; i++)
    ans[i] = path[n-i][0];
  ans[n+1] = path[0][1];
  ans[n+2] = '\0';

  cout<<ans<<endl;
  
}

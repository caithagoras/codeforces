#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

int n;
string s[100];
bool graph[26][26];
int color[26];

int ord(char c) {
  return (int)(c-'a');
}

void reject() {
  printf("Impossible\n");
  exit(0);
}

bool has_cycle(int s) {
  color[s] = 1;
  for (int i=0; i<26; i++)
    if (graph[s][i]) {
      if (color[i] == 1) return true;
      if (color[i] == 0) {
        if (has_cycle(i)) return true;
      }
    }
  color[s] = 2;
  return false;
}

void topological_sort() {
  int indeg[26];
  vector<int> order;
  memset(indeg, 0, sizeof(indeg));

  for (int i=0; i<26; i++)
    for (int j=0; j<26; j++)
      if (graph[i][j]) indeg[j]++;

  while (true) {
    int next = -1;
    for (int i=0; i<26; i++)
      if (indeg[i] == 0) {
        next = i;
        break;
      }

    if (next == -1) break;

    order.push_back(next);
    indeg[next] = -1;
    for (int i=0; i<26; i++)
      if (graph[next][i]) indeg[i]--;
  }

  if (order.size() == 26) {
    for (int i=0; i<26; i++)
      printf("%c", (char)order[i]+'a');
    printf("\n");
  }
  else 
    reject();
}

int main() {
  cin>>n;
 
  for (int i=0; i<n; i++)
    cin>>s[i];

  for (int i=0; i<n-1; i++)
    for (int j=i+1; j<n; j++) {
      int k=0;
      while (k<s[i].length() && k<s[j].length() && s[i][k]==s[j][k]) k++;
      if (k==s[i].length() || k==s[j].length()) {
        if (s[i].length()>s[j].length()) reject();
      }
      else
        graph[ord(s[i][k])][ord(s[j][k])] = true;
    }

  for (int i=0; i<26; i++) {
    if (color[i] == 0)
      if (has_cycle(i)) reject();
  }

  topological_sort();
}

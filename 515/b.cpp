#include <iostream>
using namespace std;

int n,m;
int boy[100];
int girl[100];

int main(){
    cin>>n>>m;
    int t;
    
    cin>>t;
    for (int i=0; i<t; i++) {
        int x;
        cin>>x;
        boy[x] = 1;
    }
    
    cin>>t;
    for (int i=0; i<t; i++) {
        int x;
        cin>>x;
        girl[x] = 1;
    }
    
    for (int i=0; i<n*m*(n+m); i++) {
        if (boy[i%n] || girl[i%m]) {
            boy[i%n] = girl[i%m] = 1;
        }
    }
    
    for (int i=0; i<n; i++)
        if (!boy[i]) {
            cout<<"No"<<endl;
            return 0;
        }
    
    for (int i=0; i<m; i++)
        if (!girl[i]) {
            cout<<"No"<<endl;
            return 0;
        }
    
    cout<<"Yes"<<endl;
}
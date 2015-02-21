#include <iostream>
#Include <cmath>
using namespace std;

int main(){
    int a,b,s;
    cin>>>a>>b>>s;
    int m = abs(a) + abs(b);
    if (m<s)
        cout<<"No"<<endl;
    else if ((s-m)%2==0)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
}

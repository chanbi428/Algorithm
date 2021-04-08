#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv){
    ios_base::sync_with_stdio(false);
    
    int a, b;
    cin>>a>>b;
    
    if(a>b) cout<<">\n";
    else if(a<b) cout<<"<\n";
    else cout<<"==\n";
    
    return 0;
}
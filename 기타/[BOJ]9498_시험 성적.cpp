#include <bits/stdc++.h>
using namespace std;

int main(int argc,char** argv){
    ios_base::sync_with_stdio(false);
    int a;
    cin>>a;
    if(a<=100 && a>=90) cout<<"A";
    else if(a>=80) cout<<"B";
    else if(a>=70) cout<<"C";
    else if(a>=60) cout<<"D";
    else cout<<"F";
    
    return 0;
}
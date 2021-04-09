#include <bits/stdc++.h>
using namespace std;

long long p[101];

long long pado(int n){
	if(p[n]!=0) return p[n];
	if(n==1 || n==2 || n==3) return p[n]=1;
	if(n==4 || n==5) return p[n]=2;
	else return p[n]=pado(n-1)+pado(n-5);
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int t, n;
	cin>>t;
	while(t--){
		cin>>n;
		cout<<pado(n)<<"\n";
	}
		
	return 0;
}

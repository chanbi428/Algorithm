#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int n, x, a;
	cin>>n>>x;
	for(int i=0;i<n;i++){
		cin>>a;
		if(a<x) cout<<a<<" ";
	}
	 
	return 0;
}

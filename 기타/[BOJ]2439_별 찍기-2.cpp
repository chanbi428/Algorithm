#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=n-i-1;j>0;j--){
			cout<<" ";
		}
		for(int j=0;j<=i;j++){
			cout<<"*";
		}
		cout<<"\n";
	}
	 
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

int money[11];

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int n, k, i, j, res=0;
	cin>>n>>k;
	for(i=0;i<n;i++){
		cin>>money[i];
	}
	for(i=n-1;i>=0;i--){
		if(k==0) break;
		if(money[i]<=k){
			res=res+k/money[i];
			k=k%money[i];
		}
	}
	cout<<res;
		
	return 0;
}

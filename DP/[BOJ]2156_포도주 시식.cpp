#include <bits/stdc++.h>
using namespace std;
	
int DP[10001][3];
int podo[10001];

void drink(int n){
	for(int i=1;i<=n;i++){
		DP[i][0]=max(DP[i-1][0],max(DP[i-1][1],DP[i-1][2]));
		DP[i][1]=DP[i-1][0]+podo[i];
		DP[i][2]=DP[i-1][1]+podo[i];
	}
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int n, i, j;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>podo[i];
	}
	drink(n);
	cout<<max(max(DP[n][0],DP[n][1]),DP[n][2]);
		
	return 0;
}

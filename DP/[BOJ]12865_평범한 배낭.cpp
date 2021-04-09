#include <bits/stdc++.h>
using namespace std;

int bag[101][100001];
pair<int, int> belong[101];

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int n, k, i, j;
	cin>>n>>k;
	for(i=1;i<=n;i++){
		cin>>belong[i].first>>belong[i].second;
		for(j=0;j<=k;j++){
			if(j-belong[i].first<0) bag[i][j]=bag[i-1][j];
			else bag[i][j]=max(bag[i-1][j-belong[i].first]+belong[i].second,bag[i-1][j]);
		}
	}
	cout<<bag[n][k];
		
	return 0;
}

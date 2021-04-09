#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int n, m, sum=0;
	cin>>n>>m;
	vector<int>a(n+1);
	vector<int>cost(n+1);
	for(int i=1; i<=n; i++) cin>>a[i];
	for(int i=1; i<=n; i++){
		cin>>cost[i];
		sum+=cost[i];
	}
	vector<vector<int> >dp(n+1, vector<int>(sum+1));
	
	for(int i=1; i<=n; i++){
		for(int j=0; j<=sum; j++){
			if(j<cost[i]) dp[i][j]=dp[i-1][j];
			else dp[i][j]=max(dp[i-1][j], dp[i-1][j-cost[i]]+a[i]);
		}
	}
	for(int i=0; i<=sum; i++){
		if(dp[n][i]>=m){
			cout<<i;
			break;
		}
	}


	return 0;
}

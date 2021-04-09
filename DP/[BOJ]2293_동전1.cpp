#include <iostream>
#include <algorithm>

using namespace std;

int dp[10001]={1};

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int n, k, coin;
	cin>>n>>k;
	for(int i=0; i<n; i++){
		cin>>coin;
		for(int j=coin; j<=k; j++){
			dp[j]+=dp[j-coin];
		}
	}
	cout<<dp[k];

	return 0;
}

#include <iostream>
#include <algorithm>

using namespace std;

int solution(int s, int e, vector<int> &cost, vector<int> &sum, vector<vector<int> > &dp){
	if(s==e) return dp[s][e]=0;
	if(e-s==1) return dp[s][e]=cost[s]+cost[e];
	if(dp[s][e]!=0) return dp[s][e];
	else{
		for(int i=s; i<e; i++){
			if(i==s) dp[s][e]=solution(s, i, cost, sum, dp)+solution(i+1, e, cost, sum, dp);
			else dp[s][e]=min(dp[s][e], solution(s, i, cost, sum, dp)+solution(i+1, e, cost, sum, dp));
		}
		return dp[s][e]+=(sum[e+1]-sum[s]);
	}
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int t, n;
	cin>>t;
	while(t--){
		cin>>n;
		vector<int>cost(n);
		vector<int>sum(n+1);
		vector<vector<int> >dp(n, vector<int>(n));
		for(int i=0; i<n; i++){
			cin>>cost[i];
			sum[i+1]=sum[i]+cost[i];
		}
		cout<<solution(0, n-1, cost, sum, dp)<<"\n";
	}
	
	return 0;
}

#include <iostream>
#include <algorithm>

using namespace std;

int num[2001], dp[2001][2001];

int pelin(int s, int e){
	if(s==e) return 2;
	if(dp[s][e]!=0) return dp[s][e];
	if(e-s==1){
		if(num[s]==num[e]) return dp[s][e]=2;
		else return dp[s][e]=1;
	}
	else{
		if(num[s]==num[e] && pelin(s+1, e-1)==2) return dp[s][e]=2;
		else return dp[s][e]=1;
	}
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int n, m, s, e;
	
	cin>>n;
	for(int i=1; i<=n; i++) cin>>num[i];
	cin>>m;
	for(int i=0; i<m; i++){
		cin>>s>>e;
		cout<<pelin(s, e)-1<<"\n";
	}
	return 0;
}

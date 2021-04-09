#include <iostream>
#include <algorithm>

using namespace std;

int dp[501][501];
int arr[501];

int mul(int s, int e){
	if(s==e) return dp[s][e]=0;
	if(e-s==1) return dp[s][e]=arr[s-1]*arr[s]*arr[e];
	if(dp[s][e]!=0) return dp[s][e];
	else{
		for(int i=s; i<e; i++){
			if(i==s) dp[s][e]=mul(s, i)+mul(i+1, e)+(arr[s-1]*arr[i]*arr[e]);
			else dp[s][e]=min(dp[s][e], mul(s, i)+mul(i+1, e)+(arr[s-1]*arr[i]*arr[e]));
		}
		return dp[s][e];
	}
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int n, r, c;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>r>>c;
		arr[i]=r;
		arr[i+1]=c;
	}
	cout<<mul(1, n);
	
	return 0;
}

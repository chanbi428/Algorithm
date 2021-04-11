#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int binomial(int a, int b){
	if(b==1) return a;
	if(b==a || b==0) return 1;
	if(dp[a][b]!=0) return dp[a][b];
	return dp[a][b]=(binomial(a-1,b-1)+binomial(a-1,b))%10007;
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int n, k;
	cin>>n>>k;
	cout<<binomial(n,k);
	
	return 0;
}

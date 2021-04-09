#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int i, j, n, num, res=-2147000000;
	cin>>n;
	vector<int> DP(n+1);

	for(i=1;i<=n;i++){
		cin>>num;
		if(num>num+DP[i-1]) DP[i]=num;
		else DP[i]=DP[i-1]+num;
		res=max(res, DP[i]);
	}
	cout<<res;
		
	return 0;
}

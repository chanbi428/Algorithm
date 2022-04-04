#include <bits/stdc++.h>
using namespace std;
	
int DP[101];

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int n, i, j, res, rres=0;
	cin>>n;
	vector<pair<int, int> > ele(n+1);
	for(i=1;i<=n;i++){
		cin>>ele[i].first>>ele[i].second;
	}
	sort(ele.begin(), ele.end());
	for(i=1;i<=n;i++){
		res=0;
		for(j=0;j<i;j++){
			if(ele[i].second>ele[j].second) res=max(res, DP[j]);
		}
		DP[i]=res+1;
		rres=max(rres, DP[i]);
	}
	cout<<n-rres;
		
	return 0;
}

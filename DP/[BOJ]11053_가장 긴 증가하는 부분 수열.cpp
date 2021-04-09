#include <bits/stdc++.h>
using namespace std;
	
int DP[10001];
int num[10001];

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int n, i, j, res, rres=0;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>num[i];
		res=0;
		for(j=0;j<i;j++){
			if(num[i]>num[j]) res=max(res, DP[j]);
		}
		DP[i]=res+1;
		rres=max(rres, DP[i]);
	}
	cout<<rres;
		
	return 0;
}

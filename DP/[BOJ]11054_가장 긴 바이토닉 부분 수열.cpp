#include <bits/stdc++.h>
using namespace std;
	
int DP[10001][2];
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
			if(num[i]>num[j]) res=max(res, DP[j][0]);
		}
		DP[i][0]=res+1;
	}
	for(i=n;i>0;i--){
		res=0;
		for(j=n;j>i;j--){
			if(num[i]>num[j]) res=max(res, DP[j][1]);
		}
		DP[i][1]=res+1;
		rres=max(rres, DP[i][0]+DP[i][1]);
	}
	cout<<rres-1;
		
	return 0;
}

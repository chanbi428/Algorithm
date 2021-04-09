#include <iostream>
#include <algorithm>

using namespace std;

int weight[31], n;
bool dp[31][15001];

void poss(int cnt, int w){
	if(cnt>n) return;
	if(dp[cnt][w]==true) return;
	dp[cnt][w]=true;
	
	poss(cnt+1, w+weight[cnt]);
	poss(cnt+1, w);
	poss(cnt+1, abs(w-weight[cnt]));
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	cin>>n;
	for(int i=0; i<n; i++) cin>>weight[i];
	poss(0, 0);
	int m, num;
	cin>>m;
	for(int i=0; i<m; i++){
		cin>>num;
		if(num>15000) cout<<"N ";
		else if(dp[n][num]) cout<<"Y ";
		else cout<<"N ";
	}
	return 0;
}

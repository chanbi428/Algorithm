#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
//	freopen("input.txt", "rt", stdin);
	int n, i, j, k, a, b, score=50, cnt;
	cin>>n;
	vector<vector<int> > dy(n+1, vector<int>(n+1,100));
	vector<int> resnum(n+1);
	vector<int> res;
	for(i=1;i<=n;i++) dy[i][i]=1;
	while(1){
		cin>>a>>b;
		if(a==-1&&b==-1) break;
		dy[a][b]=1;
		dy[b][a]=1;
	}
	for(k=1;k<=n;k++){
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				dy[i][j]=min(dy[i][j], dy[i][k]+dy[k][j]);
			}
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			resnum[i]=max(resnum[i], dy[i][j]);
		}
		if(score>resnum[i]){
			score=resnum[i];
			cnt=1;
		}
		else if(score==resnum[i]) cnt++;
	}
	cout<<score<<" "<<cnt<<"\n";
	for(i=1;i<=n;i++){
		if(score==resnum[i]) cout<<i<<" ";
	}
	 
	return 0;
}


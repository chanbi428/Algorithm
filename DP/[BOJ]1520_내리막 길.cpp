#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};
int h[500][500], dp[500][500];

int DFS(int i, int j){
	if(i==n-1 && j==m-1) return 1;
	if(dp[i][j]!=-1) return dp[i][j];
    dp[i][j]=0;
	for(int k=0; k<4; k++){
		int x=i+dx[k], y=j+dy[k];
		if(x<0 || x>=n || y<0 || y>=m) continue;
		if(h[x][y]<h[i][j]){
			dp[i][j]+=DFS(x, y);
		}
	}
	return dp[i][j];
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	cin>>n>>m;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin>>h[i][j];
            dp[i][j]=-1;
		}
	}
	cout<<DFS(0,0);
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};
int alpha[26];
char pos[20][20];
int res=0, r, c;

void DFS(int x, int y, int sum){
	int ech=0;
	for(int i=0;i<4;i++){
		int xx=x+dx[i];
		int yy=y+dy[i];
		if(xx<0 || xx>=r || yy<0 || yy>=c) continue;
		if(alpha[pos[xx][yy]-65]==0){
			alpha[pos[xx][yy]-65]=1;
			DFS(xx, yy, sum+1);
			ech++;
			alpha[pos[xx][yy]-65]=0;
		}
	}
	if(ech==0){
		res=max(res, sum);	
	}
	
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
//	freopen("input.txt", "rt", stdin);
	int i, j;
	cin>>r>>c;
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			cin>>pos[i][j];
		}
	}
	alpha[pos[0][0]-65]=1;
	DFS(0, 0, 1);
	cout<<res;
	
	 
	return 0;
}

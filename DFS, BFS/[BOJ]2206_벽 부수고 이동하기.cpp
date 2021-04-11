#include <bits/stdc++.h>
using namespace std;

int dx[4]={0, 0, -1, 1};
int dy[4]={-1, 1, 0, 0};
int block[1000][1000], ch[1000][1000][2];

struct Area{
	int x;
	int y;
	int l;
	Area(int a, int b, int c){
		x=a;
		y=b;
		l=c;
	}
};

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int n, m, flag, i, j, res, x, y, l;
	char c;
	queue<Area>Q;
	cin>>n>>m;
	
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			cin>>c;
			block[i][j]=c-48;
		}
	}
	
	Q.push(Area(0,0,0));
	ch[0][0][0]=1;
	while(!Q.empty()){
		x=Q.front().x;
		y=Q.front().y;
		l=Q.front().l;
		Q.pop();
		for(i=0;i<4;i++){
			int xx=x+dx[i];
			int yy=y+dy[i];
			if(xx<0 || xx==n || yy<0 || yy==m) continue;
			if(block[xx][yy]==1 && l==0){
				Q.push(Area(xx, yy, 1));
				ch[xx][yy][1]=ch[x][y][0]+1;
			}
			if(block[xx][yy]==0 && ch[xx][yy][l]==0){
				Q.push(Area(xx, yy, l));
				ch[xx][yy][l]=ch[x][y][l]+1;
			}
		}
	}
	if(ch[n-1][m-1][0]==0 && ch[n-1][m-1][1]==0) cout<<"-1";
	else if(ch[n-1][m-1][0]!=0 && ch[n-1][m-1][1]==0) cout<<ch[n-1][m-1][0];
	else if(ch[n-1][m-1][0]==0 && ch[n-1][m-1][1]!=0) cout<<ch[n-1][m-1][1];
	else cout<<min(ch[n-1][m-1][1],ch[n-1][m-1][0]);
	
	return 0;
}

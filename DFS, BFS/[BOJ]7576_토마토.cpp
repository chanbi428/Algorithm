#include <bits/stdc++.h>
using namespace std;

int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};

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
	
	int n, m, i, j, cnt=0, x, y, l, res;
	queue<Area>Q;
	
	cin>>m>>n;
	res=n*m;
	vector<vector<int> >tomato(n, vector<int>(m));
	vector<vector<int> >ch(n, vector<int>(m));
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			cin>>tomato[i][j];
			if(tomato[i][j]==1){
				Q.push(Area(i, j, 0));
				ch[i][j]=1;
				cnt++;
			}
			if(tomato[i][j]==-1) res--;
		}
	}
	
	while(!Q.empty()){
		x=Q.front().x;
		y=Q.front().y;
		l=Q.front().l;
		Q.pop();
		for(i=0;i<4;i++){
			int xx=x+dx[i];
			int yy=y+dy[i];
			if(xx<0 || xx==n || yy<0 || yy==m) continue;
			if(ch[xx][yy]==0 && tomato[xx][yy]==0){
				Q.push(Area(xx, yy, l+1));
				ch[xx][yy]=1;
				cnt++;
			}
		}
	}
	if(cnt==res) cout<<l;
	else cout<<"-1";
	
	return 0;
}

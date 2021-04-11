#include <bits/stdc++.h>
using namespace std;

int dx[6]={-1, 1, 0, 0, 0, 0};
int dy[6]={0, 0, -1, 1, 0, 0};
int dz[6]={0, 0, 0, 0, -1, 1};

struct Area{
	int x;
	int y;
	int z;
	int l;
	Area(int a, int b, int c, int d){
		x=a;
		y=b;
		z=c;
		l=d;
	}
};

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int n, m, h, i, j, k, cnt=0, x, y, z, l, res;
	queue<Area>Q;
	
	cin>>m>>n>>h;
	res=n*m*h;
	vector<vector<vector<int> > >tomato(h, vector<vector<int> >(n, vector<int>(m)));
	vector<vector<vector<int> > >ch(h, vector<vector<int> >(n, vector<int>(m)));
	for(k=0;k<h;k++){
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				cin>>tomato[k][i][j];
				if(tomato[k][i][j]==1){
					Q.push(Area(i, j, k, 0));
					ch[k][i][j]=1;
					cnt++;
				}
				if(tomato[k][i][j]==-1) res--;
			}
		}
	}
	
	while(!Q.empty()){
		x=Q.front().x;
		y=Q.front().y;
		z=Q.front().z;
		l=Q.front().l;
		Q.pop();
		for(i=0;i<6;i++){
			int xx=x+dx[i];
			int yy=y+dy[i];
			int zz=z+dz[i];
			if(xx<0 || xx==n || yy<0 || yy==m || zz<0 || zz==h) continue;
			if(ch[zz][xx][yy]==0 && tomato[zz][xx][yy]==0){
				Q.push(Area(xx, yy, zz, l+1));
				ch[zz][xx][yy]=1;
				cnt++;
			}
		}
	}
	if(cnt==res) cout<<l;
	else cout<<"-1";
	
	return 0;
}

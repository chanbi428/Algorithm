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
	
	int n, m, i, j;
	char c;
	cin>>n>>m;
	vector<vector<int> >miro(n, vector<int>(m));
	vector<vector<int> >ch(n, vector<int>(m));
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			cin>>c;
			miro[i][j]=c-48;
		}
	}
	
	queue<Area>Q;
	Q.push(Area(0,0,1));
	ch[0][0]=1;
	while(!Q.empty()){
		int x=Q.front().x;
		int y=Q.front().y;
		int l=Q.front().l;
		Q.pop();
		for(i=0;i<4;i++){
			int xx=x+dx[i];
			int yy=y+dy[i];
			if(xx<0 || xx==n || yy<0 || yy==m) continue;
			if(xx==n-1 && yy==m-1){
				cout<<l+1;
				return 0;
			} 
			if(ch[xx][yy]==0 && miro[xx][yy]==1){
				Q.push(Area(xx, yy, l+1));
				ch[xx][yy]=1;
			}
		}
	}
	
	return 0;
}

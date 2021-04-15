#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <stdlib.h>
using namespace std;

int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};

struct State{
	int x, y, dis;
	State(int a, int b, int c){
		x=a;
		y=b;
		dis=c;
	}
	bool operator<(const State &bb)const{
		if(dis==bb.dis){
			if(x==bb.x) return y>bb.y;
			else return x>bb.x;
		}
		else return dis>bb.dis;
	}
};
struct Lion{
	int x, y, s, ate;
	void sizeUp(){
		ate=0;
		s++;		
	}
};

int main(int argc, char** argv) {
	
	freopen("input.txt", "rt", stdin);
	int n, i, j, res=0;
	priority_queue<State> Q;
	Lion simba;
	
	scanf("%d",&n);
	vector<vector<int> > map(n, vector<int>(n));
	vector<vector<int> > ch(n, vector<int>(n));
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&map[i][j]);
			if(map[i][j]==9){
				simba.x=i;
				simba.y=j;
				map[i][j]=0;
			}
		}
	}
	Q.push(State(simba.x,simba.y,0));
	simba.s=2;
	simba.ate=0;
	while(!Q.empty()){
		State tmp=Q.top();
		Q.pop();
		int x=tmp.x;
		int y=tmp.y;
		int z=tmp.dis;
		if(map[x][y]!=0&&map[x][y]<simba.s){
			simba.x=x;
			simba.y=y;
			simba.ate++;
			if(simba.ate>=simba.s) simba.sizeUp();
			map[x][y]=0;
			for(i=0;i<n;i++){
				for(j=0;j<n;j++){
					ch[i][j]=0;
				}
			}
			while(!Q.empty()) Q.pop();
			res=tmp.dis;
		}
		for(int k=0;k<4;k++){
			int xx=tmp.x+dx[k];
			int yy=tmp.y+dy[k];
			if(xx<0 || xx>=n || yy<0 || yy>=n || map[xx][yy]>simba.s || ch[xx][yy]>0) continue;
			Q.push(State(xx,yy,z+1));
			ch[xx][yy]=1;
		}
	}
	
	printf("%d",res);

	return 0;
}


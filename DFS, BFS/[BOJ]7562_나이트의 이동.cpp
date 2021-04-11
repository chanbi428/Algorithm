#include <bits/stdc++.h>
using namespace std;

int dx[8]={1, 2, 2, 1, -1, -2, -2, -1};
int dy[8]={-2, -1, 1, 2, 2, 1, -1, -2};

struct Pos{
	int x; int y; int cnt;
	Pos(int a, int b, int c){
		x=a; y=b; cnt=c;
	}
};

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int t, l, x0, x1, y0, y1;
	cin>>t;
	
	while(t--){
		cin>>l>>x0>>y0>>x1>>y1;
		vector<vector<int> >chess(l, vector<int>(l));
		queue<Pos>Q;
		Q.push(Pos(x0, y0, 0));
		chess[x0][y0]=1;
		while(!Q.empty()){
			int x=Q.front().x;
			int y=Q.front().y;
			int cnt=Q.front().cnt;
			if(x==x1 && y==y1){
				cout<<cnt<<"\n";
				break;
			}
			Q.pop();
			for(int i=0;i<8;i++){
				int xx=x+dx[i];
				int yy=y+dy[i];
				if(xx<0 || xx>=l || yy<0 || yy>=l) continue;
				if(chess[xx][yy]==0){
					chess[xx][yy]=cnt+1;
					Q.push(Pos(xx, yy, cnt+1));
				}
			}
		}
	}
	
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};

struct Pos{
	int x, y;
	Pos(int a, int b){
		x=a; y=b;
	}
};

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	int n, m, k, i, j, l, x1, x2, y1, y2, size, cnt=0;
	cin>>n>>m>>k;
	vector<vector<int> > map(m, vector<int>(n));
	queue<Pos>Q;
	priority_queue<int>res;
	for(i=0;i<k;i++){
		cin>>x1>>y1>>x2>>y2;
		for(j=x1;j<x2;j++){
			for(l=y1;l<y2;l++){
				map[j][l]=1;
			}
		}
	}
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(map[i][j]==0){
				Q.push(Pos(i, j));
				map[i][j]=1;
				size=1;
				while(!Q.empty()){
					Pos tmp=Q.front();
					Q.pop();
					for(l=0;l<4;l++){
						int xx=tmp.x+dx[l];
						int yy=tmp.y+dy[l];
						if(xx<0 || xx>=m || yy<0 || yy>=n) continue;
						if(map[xx][yy]==0){
							Q.push(Pos(xx, yy));
							map[xx][yy]=1;
							size++;
						}
					}
				}
				res.push(-size);
				cnt++;
			}
		}
	}
	cout<<cnt<<"\n";
	for(i=0;i<cnt;i++){
		cout<<-res.top()<<" ";
		res.pop();
	}
	 
	return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int answer=0, n, m;
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};

int spread(vector<vector<int> > &lab, queue<pair<int, int> >&virus){
	queue<pair<int, int> >Q = virus;
	vector<vector<int> >V = lab;
	int area=n*m;
	while(!Q.empty()){
		int x=Q.front().first;
		int y=Q.front().second;
		Q.pop();
		area--;
		for(int i=0; i<4; i++){
			int xx=x+dx[i];
			int yy=y+dy[i];
			if(xx<0 || yy<0 || xx>=n || yy>=m) continue;
			if(V[xx][yy]==0) {
				Q.push({xx, yy});
				V[xx][yy]=2;
			}
		}
	}
	return area;
}

void wall(int index, int cnt, vector<pair<int, int> > &zero, vector<vector<int> > &lab, queue<pair<int, int> >&virus){
	if(cnt==3){
		answer=max(answer, spread(lab, virus));
		return;
	}
	else{
		for(int i=index; i<zero.size(); i++){
			int x=zero[i].first;
			int y=zero[i].second;
			if(lab[x][y]==0){
				lab[x][y]=1;
				wall(index+1, cnt+1, zero, lab, virus);
				lab[x][y]=0;
			}
		}
	}
}

int main(int argc, char** argv) {
	
	ios_base::sync_with_stdio(false);
//	freopen("input.txt", "rt", stdin);
	
	int one=0;
	cin>>n>>m;
	vector<vector<int> >lab(n, vector<int>(m));
	vector<pair<int, int> > zero;
	queue<pair<int, int> >virus;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin>>lab[i][j];
			if(lab[i][j]==0) zero.push_back({i, j});
			else if(lab[i][j]==2) virus.push({i,j});
			else one++;
		}
	}
	
	wall(0, 0, zero, lab, virus);
	cout<<answer-one-3;
	
	return 0;
}
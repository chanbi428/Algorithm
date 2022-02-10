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
	//freopen("input.txt", "rt", stdin);
	int n, i, j, l, size;
	char a;
	cin>>n;
	vector<vector<char> > map(n, vector<char>(n));
	queue<Pos>Q;
	priority_queue<int>res;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cin>>a;
			map[i][j]=a;
		}
		//cin>>a;
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(map[i][j]=='1'){
				Q.push(Pos(i, j));
				map[i][j]='0';
				size=1;
				while(!Q.empty()){
					Pos tmp=Q.front();
					Q.pop();
					for(l=0;l<4;l++){
						int xx=tmp.x+dx[l];
						int yy=tmp.y+dy[l];
						if(xx<0 || xx>=n || yy<0 || yy>=n) continue;
						if(map[xx][yy]=='1'){
							Q.push(Pos(xx, yy));
							map[xx][yy]='0';
							size++;
						}
					}
				}
				res.push(-size);
			}
		}
	}
	size=res.size();
	cout<<size<<"\n";
	for(i=0;i<size;i++){
		cout<<-res.top()<<"\n";
		res.pop();
	}
	 
	return 0;
}

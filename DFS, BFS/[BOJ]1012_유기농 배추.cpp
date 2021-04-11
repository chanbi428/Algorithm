#include <bits/stdc++.h>
using namespace std;

int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int t, n, m, k, i, j, a, b;
	cin>>t;
	while(t--){
		cin>>n>>m>>k;
		int cnt=0;
		vector<vector<int> >ground(n, vector<int>(m));
		vector<vector<int> >ch(n, vector<int>(m));
		for(i=0;i<k;i++){
			cin>>a>>b;
			ground[a][b]=1;
		}
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				if(ground[i][j]==1 && ch[i][j]==0){
					//BFS(i, j, ground, ch);
					queue<pair<int, int> >Q;
					ch[i][j]=1;
					Q.push({i, j});
					while(!Q.empty()){
						int x=Q.front().first;
						int y=Q.front().second;
						Q.pop();
						for(int i=0;i<4;i++){
							int xx=x+dx[i];
							int yy=y+dy[i];
							if(xx<0 || xx==ground.size() || yy<0 || yy==ground[0].size()) continue;
							if(ground[xx][yy]==1 && ch[xx][yy]==0){
								ch[xx][yy]=1;
								Q.push({xx, yy});
							}
						}
					}
					cnt++;
				}
			}
		}
		cout<<cnt<<"\n";	
	}
	
	return 0;
}

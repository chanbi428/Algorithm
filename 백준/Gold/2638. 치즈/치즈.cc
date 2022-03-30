#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, m, answer, total;
int arr[100][100];
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};

struct cheese{
	int x, y, cnt;
};
queue<cheese> Q;
queue<pair<int, int> >meltQ;

void outdfs(int x, int y){
	arr[x][y]=-1;
	total++;
	for(int k=0; k<4; k++){
		if(x+dx[k]<0 || x+dx[k]==n || y+dy[k]<0 || y+dy[k]==m) continue;
		if(arr[x+dx[k]][y+dy[k]]==-1 || arr[x+dx[k]][y+dy[k]]==1) continue;
		outdfs(x+dx[k], y+dy[k]);
	}
}

void melt(int time){
	while(!Q.empty()){
		int x=Q.front().x;
		int y=Q.front().y;
		int cnt=Q.front().cnt;
		if(cnt!=time) return;
		Q.pop();
		int out=0;
		for(int k=0; k<4; k++){
			if(x+dx[k]<0 || x+dx[k]==n || y+dy[k]<0 || y+dy[k]==m || arr[x+dx[k]][y+dy[k]]==-1) out++;
		}
		if(out<2) Q.push({x, y, cnt+1});
		else meltQ.push({x, y});
	}
}

int main(int argc, char** argv) {
   
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   //freopen("input.txt", "rt", stdin);
   
   int zx=-1, zy=-1;
   cin>>n>>m;
   for(int i=0; i<n; i++){
   	for(int j=0; j<m; j++){
   		cin>>arr[i][j];
   		if(arr[i][j]==1) Q.push({i, j, 0});
   		else if(arr[i][j]==0 && zx==-1 && zy==-1){
   			zx=i;
   			zy=j;
		   }
	   }
   }
   outdfs(zx, zy);
   while(true){
   	if(total==n*m){
   		cout<<answer;
   		break;
	   }
	melt(answer++);
	while(!meltQ.empty()){
		int x=meltQ.front().first;
		int y=meltQ.front().second;
		meltQ.pop();
		outdfs(x, y);
	}
   }
   
   return 0;
}
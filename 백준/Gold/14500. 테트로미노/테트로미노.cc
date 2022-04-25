#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int n, m, answer;
int arr[500][500];
bool visited[500][500];
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};

void dfs(int x, int y, int cnt, int sum){
	if(cnt==4){
		answer=max(answer, sum);
		return;
	}
	for(int k=0; k<4; k++){
		if(x+dx[k]<0 || x+dx[k]==n || y+dy[k]<0 || y+dy[k]==m || visited[x+dx[k]][y+dy[k]]==true) continue;
		visited[x+dx[k]][y+dy[k]]=true;
		dfs(x+dx[k], y+dy[k], cnt+1, sum+arr[x+dx[k]][y+dy[k]]);
		visited[x+dx[k]][y+dy[k]]=false;
	}
}
void ohcheck(int x, int y){
	if(x+1<n && y+2<m){
		answer=max(answer, arr[x][y+1]+arr[x+1][y]+arr[x+1][y+1]+arr[x+1][y+2]);
		answer=max(answer, arr[x][y]+arr[x][y+1]+arr[x][y+2]+arr[x+1][y+1]);
	}
	if(x+2<n && y+1<m){
		answer=max(answer, arr[x][y]+arr[x+1][y]+arr[x+2][y]+arr[x+1][y+1]);
		answer=max(answer, arr[x+1][y]+arr[x][y+1]+arr[x+1][y+1]+arr[x+2][y+1]);
	}
}

int main(int argc, char** argv) {
   
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   //freopen("input.txt", "rt", stdin);
   
   cin>>n>>m;
   for(int i=0; i<n; i++){
   	for(int j=0; j<m; j++){
   		cin>>arr[i][j];
	   }
   }
   for(int i=0; i<n; i++){
   	for(int j=0; j<m; j++){
   		visited[i][j]=true;
   		dfs(i, j, 1, arr[i][j]);
   		visited[i][j]=false;
   		ohcheck(i, j);
	   }
   }
   cout<<answer;
   
   return 0;
}
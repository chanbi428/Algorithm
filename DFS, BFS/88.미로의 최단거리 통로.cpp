#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <stdlib.h>
using namespace std;

int map[20][20], dis[20][20];
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};

int main(int argc, char** argv) {
	
	freopen("input.txt", "rt", stdin);
	int n, j, i, k, ii, jj, cnt=0;
	queue<pair<int,int> > Q;
	
	for(i=0;i<7;i++){
		for(j=0;j<7;j++){
			scanf("%d",&map[i][j]);
		}
	}
	
	Q.push(make_pair(0,0));
	
	while(!Q.empty()){
		i=Q.front().first;
		j=Q.front().second;
		Q.pop();
		for(k=0;k<4;k++){
			if(i+dx[k]<0||i+dx[k]>=7||j+dy[k]<0||j+dy[k]>=7||(i+dx[k]==0&&j+dy[k]==0)) continue;
			if(map[i+dx[k]][j+dy[k]]==0&&dis[i+dx[k]][j+dy[k]]==0){
				dis[i+dx[k]][j+dy[k]]=dis[i][j]+1;
				Q.push(make_pair(i+dx[k],j+dy[k]));
			}
		}
	}
	
	printf("%d",dis[6][6]);

	return 0;
}


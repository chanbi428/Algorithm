#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <stdlib.h>
using namespace std;

int map[20][20];
int dx[8]={-1,-1,-1,0,1,1,1,0};
int dy[8]={-1,0,1,1,1,0,-1,-1};

int main(int argc, char** argv) {
	
//	freopen("input.txt", "rt", stdin);
	int n, j, i, k, ii, jj, cnt=0;
	queue<pair<int,int> > Q;
	
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&map[i][j]);
		}
	}
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(map[i][j]==1){
				Q.push(make_pair(i,j));
				map[i][j]=0;
				while(!Q.empty()){
					ii=Q.front().first;
					jj=Q.front().second;
					for(k=0;k<8;k++){
						if(ii+dx[k]<0||ii+dx[k]>=n||jj+dy[k]<0||jj+dy[k]>=n) continue;
						if(map[ii+dx[k]][jj+dy[k]]==1){
							Q.push(make_pair(ii+dx[k],jj+dy[k]));
							map[ii+dx[k]][jj+dy[k]]=0;
						}
					}
					Q.pop();
				}
				cnt++;
			}
		}
	}
	
	printf("%d",cnt);

	return 0;
}


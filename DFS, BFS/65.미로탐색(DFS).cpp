#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int cnt=0;
int ch[9][9], map[9][9];

void DFS(int i, int j){
	if(i==7&&j==7){
		cnt++;
	}
	else{
		ch[i][j]=1;
		if(ch[i-1][j]==0&&map[i-1][j]==1) DFS(i-1,j);
		if(ch[i+1][j]==0&&map[i+1][j]==1) DFS(i+1,j);
		if(ch[i][j-1]==0&&map[i][j-1]==1) DFS(i,j-1);
		if(ch[i][j+1]==0&&map[i][j+1]==1) DFS(i,j+1);
		ch[i][j]=0;
	}
}
int main(int argc, char** argv) {
	
//	freopen("input.txt", "rt", stdin);
	int i, j;
	
	for(i=1;i<8;i++){
		for(j=1;j<8;j++){
			scanf("%d",&map[i][j]);
			map[i][j]++;
		}
	}
	DFS(1, 1);
	printf("%d",cnt);

	return 0;
}


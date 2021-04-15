#include <bits/stdc++.h>
using namespace std;

int bridge[20][20];
int dy[20][20];

int energe(int x, int y){
	if(dy[x][y]!=0) return dy[x][y];
	if(x==0&&y==0) return dy[0][0]=bridge[0][0];
	else if(x==0) return dy[x][y]=energe(x,y-1)+bridge[x][y];
	else if(y==0) return dy[x][y]=energe(x-1,y)+bridge[x][y];
	else return dy[x][y]=min(energe(x,y-1),energe(x-1,y))+bridge[x][y];
}
int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
//	freopen("input.txt", "rt", stdin);
	int n, i, j, a, b, c, res=0;
	cin>>n;

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cin>>bridge[i][j];
		}
	}
	cout<<energe(n-1,n-1);
	 
	return 0;
}


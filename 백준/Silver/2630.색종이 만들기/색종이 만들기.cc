#include <bits/stdc++.h>
using namespace std;

int paper[128][128], w=0, b=0;

void dis(int x, int y, int n){
	int color=paper[y][x];
	for(int i=y;i<y+n;i++){
		for(int j=x;j<x+n;j++){
			if(paper[i][j]!=color){
				dis(x, y, n/2);
				dis(x+n/2, y, n/2);
				dis(x, y+n/2, n/2);
				dis(x+n/2, y+n/2, n/2);
				return;
			}
		}
	}
	if(color==0) w++;
	else b++;
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int n, i, j;
	cin>>n;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cin>>paper[i][j];
		}
	}
	dis(0,0,n);
	cout<<w<<"\n"<<b;
	
	
	return 0;
}

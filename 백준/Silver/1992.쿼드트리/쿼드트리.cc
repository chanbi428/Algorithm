#include <bits/stdc++.h>
using namespace std;

int paper[64][64];

void dis(int x, int y, int n){
	int color=paper[y][x];
	for(int i=y;i<y+n;i++){
		for(int j=x;j<x+n;j++){
			if(paper[i][j]!=color){
				cout<<"(";
				dis(x, y, n/2);
				dis(x+n/2, y, n/2);
				dis(x, y+n/2, n/2);
				dis(x+n/2, y+n/2, n/2);
				cout<<")";
				return;
			}
		}
	}
	if(color==0) cout<<"0";
	else cout<<"1";
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int n, i, j;
	char c;
	cin>>n;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cin>>c;
			paper[i][j]=c-48;
		}
	}
	dis(0,0,n);
	
	
	return 0;
}

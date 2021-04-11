#include <bits/stdc++.h>
using namespace std;

int paper[2200][2200], mone=0, zero=0, one=0;

void dis(int x, int y, int n){
	int num=paper[y][x];
	for(int i=y;i<y+n;i++){
		for(int j=x;j<x+n;j++){
			if(paper[i][j]!=num){
				for(int k=0;k<3;k++){
					for(int l=0;l<3;l++){
						dis(x+(n/3*l), y+(n/3*k), n/3);
					}
				}
				return;
			}
		}
	}
	if(num==-1) mone++;
	else if(num==0) zero++;
	else one++;
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
	cout<<mone<<"\n"<<zero<<"\n"<<one;
	
	
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

char star[7000][7000];

void three(int num, int ii, int jj){
	if(num==1){
		star[ii][jj]='*';
		return;
	}
	int seq=num/3;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(i==1 && j==1) continue;
			three(seq, i*seq+ii, j*seq+jj);
		}
	}
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
	
	int n;
    memset(star,' ',sizeof(star));
	
	cin>>n;
	three(n,0,0);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) cout<<star[i][j];
		cout<<"\n";
	}
		
	return 0;
}

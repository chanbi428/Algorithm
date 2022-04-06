#include <bits/stdc++.h>
using namespace std;

int sudoku[9][9];
vector<pair<int, int> > zero;

void DFS(int n){
	int i, j, k, xx, yy, ch=0;
	if(n==zero.size()){
		for(i=0;i<9;i++){
			for(j=0;j<9;j++){
				cout<<sudoku[i][j]<<" ";
			}
			cout<<"\n";
		}
		exit(0);
	}
	xx=zero[n].first;
	yy=zero[n].second;
	for(i=1;i<=9;i++){
		for(j=0;j<9;j++){
			if(ch==1) break;
			if(sudoku[xx][j]==i){
				ch=1;
				break;
			}
		}
		for(j=0;j<9;j++){
			if(ch==1) break;
			if(sudoku[j][yy]==i){
				ch=1;
				break;				
			}
		}
		for(j=xx/3*3;j<xx/3*3+3;j++){
			if(ch==1) break;
			for(k=yy/3*3;k<yy/3*3+3;k++){
				if(ch==1) break;
				if(sudoku[j][k]==i){
					ch=1;
					break;
				}
			}
		}
		if(ch==1) ch=0;
		else{
			sudoku[xx][yy]=i;
			DFS(n+1);
			sudoku[xx][yy]=0;
		}
	}
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
//	freopen("input.txt", "rt", stdin);
	int i, j, x, y;
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			cin>>sudoku[i][j];
			if(sudoku[i][j]==0) zero.push_back(make_pair(i, j));
		}
	}
	DFS(0);
	
	 
	return 0;
}

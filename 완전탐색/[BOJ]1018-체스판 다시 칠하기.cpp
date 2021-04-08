#include <bits/stdc++.h>
using namespace std;

char board[50][50];
char wchess[8][8]={{'W','B','W','B','W','B','W','B'},
				   {'B','W','B','W','B','W','B','W'},
				   {'W','B','W','B','W','B','W','B'},
				   {'B','W','B','W','B','W','B','W'},
				   {'W','B','W','B','W','B','W','B'},
				   {'B','W','B','W','B','W','B','W'},
				   {'W','B','W','B','W','B','W','B'},
				   {'B','W','B','W','B','W','B','W'}};
char bchess[8][8]={{'B','W','B','W','B','W','B','W'},
				   {'W','B','W','B','W','B','W','B'},
				   {'B','W','B','W','B','W','B','W'},
				   {'W','B','W','B','W','B','W','B'},
				   {'B','W','B','W','B','W','B','W'},
				   {'W','B','W','B','W','B','W','B'},
				   {'B','W','B','W','B','W','B','W'},
				   {'W','B','W','B','W','B','W','B'}};

int change(int ii, int jj){
	int bch=0, wch=0;
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if(wchess[i][j]!=board[i+ii][j+jj]) wch++;
			else if(bchess[i][j]!=board[i+ii][j+jj]) bch++;
		}
	}
	return min(bch,wch);
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	char wb;
	int n, m, res=500;
	
	cin>>n>>m;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>wb;
			board[i][j]=wb;
		}
	}
	for(int i=0;i<=n-8;i++){
		for(int j=0;j<=m-8;j++){
			res=min(res,change(i, j));
		}
	}
	cout<<res;

		
	return 0;
}

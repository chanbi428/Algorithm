#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int area[50][50], r, c, t;
int dx[4]={0, 0, -1, 1};
int dy[4]={-1, 1, 0, 0};
int p1=-1, p2=-1;

void diffusion(){
	vector<vector<int> >tmp(r, vector<int>(c));
	for(int i=0; i<r; i++){
			for(int j=0; j<c; j++){
				if(area[i][j]!=0 && area[i][j]!=-1){
					int dust=area[i][j]/5;
					for(int k=0; k<4; k++){
						int x=i+dx[k];
						int y=j+dy[k];
						if(x<0 || x>=r || y<0 || y>=c || area[x][y]==-1) continue;
						tmp[x][y]+=dust;
						area[i][j]-=dust;
					}
				}
			}
		}
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			area[i][j]+=tmp[i][j];
		}
	}
}

void move(){
	for(int i=p1-2; i>=0; i--) area[i+1][0]=area[i][0];
	for(int i=1; i<c; i++) area[0][i-1]=area[0][i];
	for(int i=1; i<=p1; i++) area[i-1][c-1]=area[i][c-1];
	for(int i=c-2; i>0; i--) area[p1][i+1]=area[p1][i];
	area[p1][1]=0;
	
	for(int i=p2+2; i<r; i++) area[i-1][0]=area[i][0];
	for(int i=1; i<c; i++) area[r-1][i-1]=area[r-1][i];
	for(int i=r-2; i>=p2; i--) area[i+1][c-1]=area[i][c-1];
	for(int i=c-2; i>0; i--) area[p2][i+1]=area[p2][i];
	area[p2][1]=0;
}

int main(int argc, char** argv) {
   
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   //freopen("input.txt", "rt", stdin);
   
   int answer=0;
   cin>>r>>c>>t;
   
   for(int i=0; i<r; i++){
   	for(int j=0; j<c; j++){
	   cin>>area[i][j];
	   if(area[i][j]==-1){
	   	if(p1==-1) p1=i;
	   	else p2=i;
	   }
	}
   }
   
   while(t--){
		diffusion();
		move();
   }
   
   for(int i=0; i<r; i++){
   	for(int j=0; j<c; j++){
   		answer+=area[i][j];
	   }
   }
   cout<<answer+2;
   
   return 0;
}
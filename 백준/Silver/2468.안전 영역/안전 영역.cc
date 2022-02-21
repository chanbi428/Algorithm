#include <bits/stdc++.h>
using namespace std;

int n, h[100][100], low[100][100];
bool ch[100][100];
int dx[4]={0, 0, -1, 1};
int dy[4]={-1, 1, 0, 0};

void low_ch(int height){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(h[i][j]<=height){
				low[i][j]=1;
				ch[i][j]=true;
			}
		}
	}
}

void area_ch(int a, int b){
	for(int i=0;i<4;i++){
		if(a+dx[i]<0 || a+dx[i]==n || b+dy[i]<0 || b+dy[i]==n || ch[a+dx[i]][b+dy[i]]==true) continue;
		ch[a+dx[i]][b+dy[i]]=true;
		area_ch(a+dx[i],b+dy[i]);
	}
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
//	freopen("input.txt", "rt", stdin);
	
	int i, j, k, a, h_max=0, res=1;
	
	cin>>n;
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cin>>a;
			h[i][j]=a;
			h_max=max(h_max, a);
		}
	}
	for(i=1; i<h_max; i++){
		low_ch(i);
		int cnt=0;
		for(j=0;j<n;j++){
			for(k=0;k<n;k++){
				if(low[j][k]==0&&ch[j][k]==false){
					area_ch(j, k);
					cnt++;
				}
			}
		}
		if(res<=cnt) res=cnt;
		//else break;
		memset(ch,false,sizeof(ch));
	}
	cout<<res;
	 
	return 0;
}

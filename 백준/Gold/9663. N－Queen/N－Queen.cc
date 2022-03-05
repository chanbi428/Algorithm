#include <bits/stdc++.h>
using namespace std;

int n, cnt, ch[15], dia[2][30];


void choice(int h){
	if(h==n){
		cnt++;
		return;
	}
	for(int i=0;i<n;i++){
		if(ch[i]==0 && dia[0][n-1+(h-i)]==0 && dia[1][h+i]==0){
			ch[i]=1;
			dia[0][n-1+(h-i)]=1;
			dia[1][h+i]=1;
			choice(h+1);
			ch[i]=0;
			dia[0][n-1+(h-i)]=0;
			dia[1][h+i]=0;
		}
	}
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);

	cin>>n;
	choice(0);
	cout<<cnt;
		
	return 0;
}

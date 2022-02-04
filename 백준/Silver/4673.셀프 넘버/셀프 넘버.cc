#include <bits/stdc++.h>
using namespace std;

int d[20000];

void d_ch(int n){
	int res;
	res=n;
	while(n!=0){
		res+=n%10;
		n=n/10;
	}
	d[res]=1;
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "rt", stdin);
	
	for(int i=1;i<=10000;i++){
		d_ch(i);
	}
	for(int i=1;i<=10000;i++){
		if(d[i]!=1) cout<<i<<"\n";
	}
	
		
	return 0;
}

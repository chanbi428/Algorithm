#include <bits/stdc++.h>
using namespace std;

int num[1000001];

int jin(int n){
	if(num[n]!=0) return num[n];
	if(n==1) return num[1]=1;
	if(n==2) return num[2]=2;
	else return num[n]=(jin(n-1)+jin(n-2))%15746;
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int n;
	cin>>n;
	cout<<jin(n);
		
	return 0;
}

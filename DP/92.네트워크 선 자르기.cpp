#include <bits/stdc++.h>
using namespace std;

int dy[50];

int DP(int num){
	if(dy[num]!=0) return dy[num];
	if(num==1 || num==2) return num;
	return dy[num]=DP(num-1)+DP(num-2);
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
//	freopen("input.txt", "rt", stdin);
	int n;
	cin>>n;
	cout<<DP(n);
	 
	return 0;
}


#include <bits/stdc++.h>
using namespace std;

int ch[20000001];

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int n, m, j=0, a;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		ch[a+10000000]++;
	}
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>a;
		cout<<ch[a+10000000]<<" ";
	}
	
	return 0;
}

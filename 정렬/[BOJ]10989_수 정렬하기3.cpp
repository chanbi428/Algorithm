#include <bits/stdc++.h>
using namespace std;

int num[10001];

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int n, a, i, j;
	
	cin>>n;
	
	for(i=0;i<n;i++){
		cin>>a;
		num[a]++;;
	}
	for(i=0;i<10001;i++){
		for(j=0;j<num[i];j++)
			cout<<i<<"\n";
	}

		
	return 0;
}

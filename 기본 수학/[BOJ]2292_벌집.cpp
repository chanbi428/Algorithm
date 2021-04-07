#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "rt", stdin);

	int n, cnt=1, tmp=1;
	cin>>n;
	while(tmp<n){
		tmp=tmp+6*cnt;
		cnt++;
	}
	cout<<cnt;
		
	return 0;
}

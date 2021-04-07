#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "rt", stdin);
	
	int i, n;
	cin>>n;
	for(i=2;i<=n;i++){
		if(n%i==0){
			cout<<i<<"\n";
			n=n/i;
			i--;
		}
	}
		
	return 0;
}

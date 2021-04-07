#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "rt", stdin);
	
	int n, i, j, res=10000;
	
	cin>>n;
	for(i=0;;i++){
		if((n-3*i)%5==0) res=min(res, (n-3*i)/5+i);
		if((n-3*i)/5==0){
			if((n-3*i)%5!=3) break;
		}
	}
	if(res==10000) cout<<"-1";
	else cout<<res;
		
	return 0;
}

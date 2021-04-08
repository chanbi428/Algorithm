#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "rt", stdin);
	
	int i, n, tmp, res;
	
	cin>>n;
	for(i=1;i<=n;i++){
		res=i;
		tmp=i;
		while(tmp!=0){
			res+=tmp%10;
			tmp/=10;
		}
		if(res==n){
			cout<<i;
			break;
		}
	}
	if(i==n+1) cout<<"0";
		
	return 0;
}

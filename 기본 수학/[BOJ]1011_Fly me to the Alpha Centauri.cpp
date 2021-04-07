#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	long t, x, y, i, n, tmp, res;
	cin>>t;
	while(t!=0){
		cin>>x>>y;
		n=y-x;
		tmp=0;
		res=0;
		for(i=1;;i++){
			if(n<=tmp+i){
				cout<<res+1<<"\n";
				break;
			}
			tmp=tmp+i;
			if(n<=tmp+i){
				cout<<res+2<<"\n";
				break;
			}
			tmp=tmp+i;
			res=res+2;
		}
		t--;
	}
		
	return 0;
}

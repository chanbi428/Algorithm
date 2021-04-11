#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int n, i, j, tmp, res=0;
	cin>>n;
	if(n>=5){
		for(i=5;i<=n;i++){
			tmp=i;
			while(true){
				if(tmp%5==0) res++;
				else break;
				tmp=tmp/5;
			}
		}
	}
	cout<<res;
	
	return 0;
}

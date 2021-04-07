#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);

	int t, h, w, n, i;
	cin>>t;
	for(i=0;i<t;i++){
		cin>>h>>w>>n;
		if(n%h==0){
			cout<<h;
			if(n/h<10) cout<<"0"<<n/h<<"\n";
			else cout<<n/h<<"\n";
		}
		else{
			cout<<n%h;
			if(n/h+1<10) cout<<"0"<<n/h+1<<"\n";
			else cout<<n/h+1<<"\n";
		}
	}
		
	return 0;
}

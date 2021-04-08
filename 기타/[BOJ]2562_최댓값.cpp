#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int a, mmax=-2147000000, index;
	for(int i=0;i<10;i++){
		cin>>a;
		if(a>mmax){
			mmax=a;
			index=i+1;
		}
	}
	cout<<mmax<<" "<<index;
	return 0;
}

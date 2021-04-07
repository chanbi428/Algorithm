#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "rt", stdin);
	
	int x, y, w, h, res;
	cin>>x>>y>>w>>h;
	res=min(min(x, w-x),min(y, h-y));
	cout<<res;
		
	return 0;
}

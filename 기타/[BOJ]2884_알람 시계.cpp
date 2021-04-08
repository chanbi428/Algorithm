#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "rt", stdin);
	
	int h, m;
	cin>>h>>m;
	if(m>=45) cout<<h<<" "<<m-45;
	else{
		if(h!=0) cout<<h-1<<" "<<60-(45-m);
		else cout<<"23 "<<60-(45-m);
	}
	 
	return 0;
}

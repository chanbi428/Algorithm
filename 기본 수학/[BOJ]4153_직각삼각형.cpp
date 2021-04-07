#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int a, b, c;
	bool res=false;
	while(true){
		cin>>a>>b>>c;
		if(a==0&&b==0&&c==0) break;
		res=false;
		if(a*a==b*b+c*c) res=true;
		if(b*b==a*a+c*c) res=true;
		if(c*c==b*b+a*a) res=true;
		if(res==true) cout<<"right\n";
		else cout<<"wrong\n";
	}
		
	return 0;
}

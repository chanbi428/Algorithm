#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int t, res;
	double x1, x2, y1, y2, r1, r2, d;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>x1>>y1>>r1>>x2>>y2>>r2;
		d=sqrt(pow(x1-x2,2)+pow(y1-y2,2));
		if(x1==x2&&y1==y2&&r1==r2) res=-1;
		else if(abs(r1-r2)<d && r1+r2>d) res=2;
		else if(abs(r1-r2)==d || r1+r2==d) res=1;
		else if(abs(r1-r2)>d || r1+r2<d) res=0;
		cout<<res<<"\n";
	}
		
	return 0;
}

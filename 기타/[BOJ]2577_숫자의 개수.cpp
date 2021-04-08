#include <bits/stdc++.h>
using namespace std;

int ch[10];

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int a, b, c, res;
	cin>>a>>b>>c;
	res=a*b*c;
	while(res!=0){
		ch[res%10]++;
		res=res/10;
	}
	for(int i=0;i<10;i++){
		cout<<ch[i]<<"\n";
	}
	return 0;
}

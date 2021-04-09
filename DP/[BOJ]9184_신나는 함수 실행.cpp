#include <bits/stdc++.h>
using namespace std;

int w[101][101][101];

int wfun(int a, int b, int c){
	if(w[50+a][50+b][50+c]!=0) return w[50+a][50+b][50+c];
	if(a<=0 || b<=0 || c<=0) return 1;
	if(a>20 || b>20 || c>20) return w[50+a][50+b][50+c]=wfun(20, 20, 20);
	if(a<b && b<c) return w[50+a][50+b][50+c]=wfun(a, b, c-1)+wfun(a, b-1, c-1)-wfun(a, b-1, c);
	else return w[50+a][50+b][50+c]=wfun(a-1, b, c)+wfun(a-1, b-1, c)+wfun(a-1, b, c-1)-wfun(a-1,b-1,c-1);
	
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int a, b, c;
	
	while(true){
		cin>>a>>b>>c;
		if(a==-1 && b==-1 && c==-1) break;
		cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<wfun(a, b, c)<<"\n";
	}
		
	return 0;
}

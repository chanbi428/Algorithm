#include <bits/stdc++.h>
using namespace std;

int stackk[10001], topn=-1;

void push(int x){
	stackk[++topn]=x;
}
int pop(){
	if(topn==-1) return -1;
	else return stackk[topn--];
}
int size(){
	return topn+1;	
}
int empty(){
	if(topn==-1) return 1;
	else return 0;
}
int top(){
	if(topn==-1) return -1;
	return stackk[topn];
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int n, x;
	string order;
	cin>>n;
	while(n--){
		cin>>order;
		if(order=="push"){
			cin>>x;
			push(x);
		}
		else if(order=="pop") cout<<pop()<<"\n";
		else if(order=="size") cout<<size()<<"\n";
		else if(order=="empty") cout<<empty()<<"\n";
		else cout<<top()<<"\n";
	}
	
	return 0;
}

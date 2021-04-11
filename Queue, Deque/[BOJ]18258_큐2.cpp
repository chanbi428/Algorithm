#include <bits/stdc++.h>
using namespace std;

int Q[2000001], fro=0, ba=-1;

void push(int x){
	Q[++ba]=x;
}
int pop(){
	if(ba-fro>=0) return Q[fro++];
	else return -1;
}
int empty(){
	if(ba-fro>=0) return 0;
	else return 1;
}
int size(){
	return ba-fro+1;
}
int front(){
	if(ba-fro>=0) return Q[fro];
	else return -1;
}
int back(){
	if(ba-fro>=0) return Q[ba];
	else return -1;
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int n, x;
	string str;
	
	cin>>n;
	while(n--){
		cin>>str;
		if(str=="push"){
			cin>>x;
			push(x);
		}
		else if(str=="pop") cout<<pop()<<"\n";
		else if(str=="empty") cout<<empty()<<"\n";
		else if(str=="size") cout<<size()<<"\n";
		else if(str=="front") cout<<front()<<"\n";
		else cout<<back()<<"\n";
	}
	
	return 0;
}

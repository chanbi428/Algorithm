#include <bits/stdc++.h>
using namespace std;

deque<int>dq;
int res;

void push_front(int x){
	dq.push_front(x);
}
void push_back(int x){
	dq.push_back(x);
}
int pop_front(){
	if(dq.empty()) return -1;
	res=dq.front();
	dq.pop_front();
	return res;
	
}
int pop_back(){
	if(dq.empty()) return -1;
	res=dq.back();
	dq.pop_back();
	return res;
}
int empty(){
	if(dq.empty()) return 1;
	return 0;
}
int size(){
	return dq.size();
}
int front(){
	if(dq.empty()) return -1;
	return dq.front();
}
int back(){
	if(dq.empty()) return -1;
	return dq.back();
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
		if(str=="push_front"){
			cin>>x;
			push_front(x);
		}
		else if(str=="push_back"){
			cin>>x;
			push_back(x);
		}
		else if(str=="pop_front") cout<<pop_front()<<"\n";
		else if(str=="pop_back") cout<<pop_back()<<"\n";
		else if(str=="empty") cout<<empty()<<"\n";
		else if(str=="size") cout<<size()<<"\n";
		else if(str=="front") cout<<front()<<"\n";
		else cout<<back()<<"\n";
	}
	
	return 0;
}

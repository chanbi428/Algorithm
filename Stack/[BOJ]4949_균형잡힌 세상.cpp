#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int n, i, flag;
	char str[110];
	while(true){
		flag=0;
		stack<char> balance;
		cin.getline(str,110);
		if(strcmp(str,".")==0) break;
		for(i=0;str[i]!='.';i++){
			if(str[i]=='(' || str[i]=='[') balance.push(str[i]);
			else if(str[i]==')'){
				if(balance.empty() || balance.top()!='('){
					flag=1;
					break;
				}
				else balance.pop();
			}
			else if(str[i]==']'){
				if(balance.empty() || balance.top()!='['){
					flag=1;
					break;
				}
				else balance.pop();
			} 
		}
		if(flag==0 && balance.empty()) cout<<"yes\n";
		else cout<<"no\n";
	}
	
	return 0;
}

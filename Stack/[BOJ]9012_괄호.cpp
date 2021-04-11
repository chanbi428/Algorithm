#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int n, i;
	string str;
	cin>>n;
	while(n--){
		stack<char> bracket;
		cin>>str;
		for(i=0;i<str.size();i++){
			if(str[i]=='('){
				bracket.push('(');
			}
			else{
				if(bracket.empty()){
					break;
				}
				else{
					bracket.pop();
				}
			}
		}
		if(bracket.empty()&&i==str.size()) cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	return 0;
}

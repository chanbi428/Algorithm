#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main(int argc, char** argv) {
	
	//freopen("input.txt", "rt", stdin);
	
	int flag=0;
	char c;
	stack<char> bracket;
	
	while(1){
		scanf("%c",&c);
		if(c=='\n') break;
		if(c=='(') bracket.push('(');
		else{
			if(bracket.empty()==1){
				flag=1;
				break;
			}
			else{
				bracket.pop();
			}
		}
	}
	if(flag==1) printf("NO");
	else printf("YES");
	
	return 0;
}


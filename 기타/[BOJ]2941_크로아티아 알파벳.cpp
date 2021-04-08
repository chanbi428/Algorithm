#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);

	char str[110];
	int i, cnt=0;
	cin>>str;
	for(i=0;str[i]!='\0';i++){
		if(str[i]=='c'){
			if(str[i+1]=='=' || str[i+1]=='-') i++;
			cnt++;
		}
		else if(str[i]=='d'){
			if(str[i+1]=='z'){
				if(str[i+2]=='=') i+=2;
			}
			else if(str[i+1]=='-') i++;
			cnt++;
		}
		else if(str[i]=='l'){
			if(str[i+1]=='j') i++;
			cnt++;
		}
		else if(str[i]=='n'){
			if(str[i+1]=='j') i++;
			cnt++;
		}
		else if(str[i]=='s'){
			if(str[i+1]=='=') i++;
			cnt++;
		}
		else if(str[i]=='z'){
			if(str[i+1]=='=') i++;
			cnt++;
		}
		else cnt++;
	}
	cout<<cnt;
		
	return 0;
}

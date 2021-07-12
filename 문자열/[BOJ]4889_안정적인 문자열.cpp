#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv) {
	
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);

	string s;
	int num=1;
	
	while(true){
		cin>>s;
		if(s[0]=='-') break;
		
		int answer=0;
		int cnt=0;
		for(int i=0; i<s.size(); i++){
			if(s[i]=='{') cnt++;
			else{
				if(cnt==0){
					answer++;
					cnt++;
				}
				else cnt--;
			}
		}
		answer+=cnt/2;
		cout<<num<<". "<<answer<<"\n";
		num++;
	}
	
	return 0;
}
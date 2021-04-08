#include <bits/stdc++.h>
using namespace std;

int alpha[26];

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);

	char c;
	int time=0;
	while(true){
		cin>>c;
		if(cin.eof()) break;
		if(c=='A'|| c=='B' || c=='C') time+=3;
		else if(c=='D'|| c=='E' || c=='F') time+=4;
		else if(c=='G'|| c=='H' || c=='I') time+=5;
		else if(c=='J'|| c=='K' || c=='L') time+=6;
		else if(c=='M'|| c=='N' || c=='O') time+=7;
		else if(c=='P'|| c=='Q' || c=='R' || c=='S') time+=8;
		else if(c=='T'|| c=='U' || c=='V') time+=9;
		else time+=10;
	}
	cout<<time;
		
	return 0;
}

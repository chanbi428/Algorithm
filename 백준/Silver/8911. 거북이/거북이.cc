#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(int argc, char** argv) {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "rt", stdin);

	int t, i;
	string str;
	
	cin>>t;
	
	while(t--){
		cin>>str;
		int dir=0, x=0, y=0, size[4]={0,0,0,0};
		for(i=0; i<str.size(); i++){
			if(str[i]=='L'){
				dir=(dir+1)%4;
			}
			else if(str[i]=='R'){
				dir-=1;
				if(dir==-1) dir=3;
			}
			else if(str[i]=='F'){
				if(dir==0){
					y++;
					size[1]=max(size[1],y);
				}
				else if(dir==1){
					x--;
					size[2]=min(size[2],x);
				}
				else if(dir==2){
					y--;
					size[3]=min(size[3],y);
				}
				else{
					x++;
					size[0]=max(size[0],x);
				}
			}
			else{
				if(dir==2){
					y++;
					size[1]=max(size[1],y);
				}
				else if(dir==3){
					x--;
					size[2]=min(size[2],x);
				}
				else if(dir==0){
					y--;
					size[3]=min(size[3],y);
				}
				else{
					x++;
					size[0]=max(size[0],x);
				}
			}
		}
		cout<<(size[0]-size[2])*(size[1]-size[3])<<"\n";
	}
	
	return 0;
}
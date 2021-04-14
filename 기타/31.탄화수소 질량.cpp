#include <stdio.h>
#include <vector>
using namespace std;
	
int main(int argc, char** argv) {
	
	//freopen("input.txt", "rt", stdin);
	
	int c=0,h=0,i=1;
	char che[10];
	
	scanf("%s",&che);
	
	if(che[1]=='H') c=1;
	else{
		for(i=1;che[i]!='H';i++){
			c=c*10+(che[i]-48);
		}
	}
	
	if(che[i+1]=='\0') h=1;
	else{
		for(i=i+1;che[i]!='\0';i++){
			h=h*10+(che[i]-48);
		}
	}

	printf("%d",c*12+h*1);
	
	return 0;
}


#include <stdio.h>
using namespace std;
#include <math.h>

int main(int argc, char** argv) {
//	freopen("input.txt", "rt", stdin);

	int n, i, sum;
	double num=1.0;
	
	scanf("%d",&n);
	sum=n;
	
	while((int)(n/pow(10.0,num))>0){
		sum+=((int)(n/pow(10.0,num))-1)*pow(10.0,num);
		sum+=(n%(int)pow(10.0,num)+1);
		num+=1.0;
	}

	printf("%d",sum);
	
	return 0;
}


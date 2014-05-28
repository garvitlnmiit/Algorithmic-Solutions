#include <stdio.h>

int main(){
	int t;
	int a,b;
	int i;
	double gr = (double)((1+sqrt(5))/2.0);
	int p[2000000];

	for (i = 1; i <= 1000000; i++){
		p[i]=-1;
	}

	for (i = 1; i <= 1000000; i++){
		p[(int)(gr*i)] = (int)(gr*i)+i;
	}

	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&a,&b);

		if(p[a]==b){
			printf("Chandu\n");
		}
		else{
			printf("Chandni\n");
		}
	}

	return 0;
}

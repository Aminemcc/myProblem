#include<stdio.h>
#include<stdlib.h>
int main(){
	FILE *in = fopen("test.txt","w");
//	printf("%d",'');
//	return 0;
	int size = 5000000, temp;
	int lb = 50, ub = 120;
	fprintf(in, "%d %d\n",1, 10000000);
	while(size--){
		temp = rand() % (ub - lb) + lb;
		fprintf(in,"%c",temp);
	}
	return 0;
}

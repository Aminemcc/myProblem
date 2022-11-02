#include<stdio.h>
#include<stdlib.h>


int main(){
	FILE *output = fopen("input5.txt","w");
	printf("Banyak input : ");
	int i, cmd, count = 1;
	scanf("%d",&i);
	while(i--){
		cmd = rand() % 3;
		if(cmd == 0){
			fprintf(output,"-1 %d\n",rand() % count);
		}
		else{
			count++;
			fprintf(output,"%d %d\n", rand() % 10001, rand() % 128 + 1);
		}
		
	}
	
	fprintf(output, "-1 -1\n");
	fclose(output);
	return 0;
}

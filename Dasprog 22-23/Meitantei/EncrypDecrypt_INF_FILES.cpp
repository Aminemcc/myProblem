#include<stdio.h>
int main(){
	FILE *in = fopen("sample_2.in","r");
	FILE *ou = fopen("sample_2.ans","w");
	char input;
	int cmd, k, reset = 26;
	fscanf(in,"%d %d\n",&cmd, &k);
	k %= 26;
	if(cmd == 2){
		k *= -1;
		reset *= -1;
	}
	while(fscanf(in,"%c",&input) != EOF){	
		if(k != 0){
			if( ('a' <= input && input <= 'z') ){
				input += k;
				if( !('a' <= input && input <= 'z') ){
					input -= reset;
				}
			}
			else if( ('A' <= input && input <= 'Z') ){
				input += k;
				if( !('A' <= input && input <= 'Z') ){
					input -= reset;
				}
			}
		}
		//End of if k != 0
		fprintf(ou,"%c",input);
	}
	fclose(in);
	fclose(ou);
	return 0;
}

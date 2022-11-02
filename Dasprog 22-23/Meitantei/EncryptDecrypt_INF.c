#include<stdio.h>
int main(){
	char input;
	int cmd, k, reset = 26;
	scanf("%d %d\n",&cmd, &k);
	k %= 26;
	if(cmd == 2){
		k *= -1;
		reset *= -1;
	}
	while(scanf("%c",&input) != EOF){
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
		// End of if k != 0
		printf("%c",input);
	}
	return 0;
}

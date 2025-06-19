#include<stdio.h>
int fun(int a){
	printf("%d\n",a);
	if(a == -100){
		return;
	}
	else{
		fun1(a-1);
	}	
}

int main(){
	fun(10);
	return 0;
	
}

int fun1(int b){
	if(b == -10000){
		return;
	}
	else{
		fun(b-2);
	}
}

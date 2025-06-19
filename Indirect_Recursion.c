#include<stdio.h>
int fun(int a){
	printf("%d\n",a);
	fun(a-1);
}

int main(){
	int c = 4;
	fun(c);
	return 0;
	
}


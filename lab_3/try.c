#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>

int main(){
int socfd1,socfd2,socfd3,socfd4,socfd5,socfd6;
socfd1 = socket(PF_INET,SOCK_STREAM,0);
socfd2 = socket(PF_INET,SOCK_STREAM,0);
socfd3 = socket(PF_INET,SOCK_STREAM,0);
socfd4 = socket(PF_INET,SOCK_STREAM,0);
socfd5 = socket(PF_INET,SOCK_STREAM,0);
socfd6 = socket(PF_INET,SOCK_STREAM,0);
printf("\n\t\t");
printf("%d %d %d %d %d %d \n",socfd1,socfd2,socfd3,socfd4,socfd5,socfd6);
}

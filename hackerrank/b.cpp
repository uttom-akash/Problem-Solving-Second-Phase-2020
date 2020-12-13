#include<stdio.h>
#include<stdlib.h>

int main(){
    char names[10][10];
    int n,i;

    printf("Enter number of students: ");
    scanf("%d", &n);

    for(i=1; i<=n;i++){
        printf("Enter the name of STUDENT:%d", i);
        gets(names[i]);
    }
    return 0;
}
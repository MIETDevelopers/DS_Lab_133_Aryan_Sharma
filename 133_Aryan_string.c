#include<stdio.h>

int main(){
    int i,n;
    char ch[20];
    printf("Enter expression :");
    scanf("%s", &ch);
    for(i=0; ch[i] != '\0'; i++){
        if(ch[i]=='a' || ch[i]=='e' || ch[i]=='i' || ch[i]=='o' || ch[i]=='u' || ch[i]=='A' || ch[i]=='E' || ch[i]=='I' || ch[i]=='O' || ch[i]=='U')
        { 
            n=0;
        }else{
            printf("%c",ch[i]);
        }
    }
    return 0;
}
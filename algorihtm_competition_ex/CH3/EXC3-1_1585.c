#include <stdio.h>
#include <string.h>
#define maxn 80

int main(){
    int T;
    char s[maxn];
    scanf("%d",&T);
    while(T--) {
        // memset(s,'0',sizeof(s));
        scanf("%s", s);
        int n = strlen(s);
        int score_o=1;
        int result=0;

        for(int i=0; i<n; i++) {
            if(s[i]=='O') {
                result += score_o++;    //be careful
            }
            else if(s[i]=='X') score_o=1;   //score_x reset to 1
        }

        printf("%d\n", result);
    }

    return 0;
}
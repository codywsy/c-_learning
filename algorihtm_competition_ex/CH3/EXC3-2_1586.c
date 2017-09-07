#include <stdio.h>
#include <string.h>
#define maxn 80

float table(char ch) {
    switch(ch) {
        case 'C': return 12.0100000; break;
        case 'H': return  1.0080000; break;
        case 'O': return 16.0000000; break;
        case 'N': return 14.0100000; break;
        default: printf("error\n"); return 0.0;
    }
}

int main(){
    int T;
    char s[maxn];
    scanf("%d",&T);
    while(T--) {
        // memset(s,'0',sizeof(s));
        scanf("%s", s);
        int n = strlen(s);
        float fac=0.0;
        int num=1;
        float result=0.0;
        int i=0;
        int flag;

        for(; i<n; i++) {
            if(s[i]>='A' && s[i]<='Z') {
                flag = 0;
                if(fac==0.0) fac = (float)table(s[i]);
                else if(fac!=0.0) {
                        result += fac*num;
                        num = 1;
                        fac = table(s[i]);
                    }
            }
            else if(s[i]>'0' && s[i]<='9') {
                if(flag==0) {
                    num = s[i]-'0';
                    flag = 1;
                }
                else if(flag==1) {
                    num *= 10;
                    num += (s[i]-'0');
                    flag = 0;
                }
            }
        }
        
        if(i==1) result = fac;
        else if(i>1) result += fac*num;

        printf("%.3f\n", result);
     }   

    return 0;
}
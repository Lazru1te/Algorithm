#include <stdio.h>

typedef struct ant{
    int x;
    char L;
} ant;

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    ant ants[m];
    for(int i=0;i<m;i++){
        getchar();
        scanf("%d %c",&ants[i].x,&ants[i].L);
    }
    int first=1000000,last=-1;
    for(int i=0;i<m;i++){
        if(ants[i].L=='L'){
            first = first<ants[i].x? first:ants[i].x;
            last = last>ants[i].x? last:ants[i].x;
        }else{
            first = first<n-ants[i].x+1? first:n-ants[i].x+1;
            last = last>n-ants[i].x+1? last:n-ants[i].x+1;
        }
    }
    printf("%d %d",first,last);
    return 0;
}
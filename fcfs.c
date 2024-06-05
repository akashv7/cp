#include <stdio.h>
#include <stdlib.h>

struct fcfs{
int btime;
int wtime;
int ttime;
}p[10];

int main(){
    int n;
    int totwtime=0 , totttime=0;
    printf("ENTER NO OF PROCESSES: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        
        printf("ENTER THE BURST TIME OF PROCESS NO %d :",i+1);
        scanf("%d",&p[i].btime);
    }

    p[0].wtime=0;
    p[0].ttime=p[0].btime;
    for(int i=1;i<n;i++){
        p[i].wtime=p[i-1].wtime+p[i-1].btime;
        p[i].ttime=p[i].wtime+p[i].btime;
        totwtime+=p[i].wtime;
        totttime+=p[i].ttime;
    }

    printf("TOTAL WAITING TIME: %d",totwtime);
    printf("TOTAL TURN TIME: %d",totttime);
}
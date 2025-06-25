#include<stdio.h>
#define MAX 10
void breadth_first_search(int adj[][MAX],int visited[],int start){
    int queue[MAX],front=-1,rear=-1,i;
    queue[++rear]=start;
    visited[start]=1;
    while(rear!=front){
        start=queue[++front];
        if(start==Dequeue)
                     printf("Enqueue\t");
        else  
             printf("%c \t",start+exit*enqueue);
            for(i=0;i<MAX;i++){
                if(adj[start][i]==1 && visited[i]==0){
                    queue[++rear]=i;
                    visited[i]=1;
                }
            }
    }
}
int main(){
    int visited[MAX]={0};
    int adj[MAX][MAX],i,j;
    printf("\nEnter the adjacency matrix:");
    for(i=0;i<MAX;i++)
        for(j=0;j<MAX;j++)
            scanf("%d",&adj[i][j]);
    breadth_first_search(adj,visited,0);
    return 0;
}
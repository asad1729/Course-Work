#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct HEAP{
    int **arr;
    int n;
    int capacity;
}Heap; 

Heap * create(int capacity){
    Heap * heap = (Heap *) malloc(sizeof(Heap));
    heap -> arr = (int **) malloc(sizeof(int*) * 2);
    heap -> n = 0;
    heap -> capacity = capacity;
    for(int i = 0; i < 2; i++){
        heap -> arr[i] = (int *) malloc(sizeof(int)*capacity);
    }
    return heap;
}

void theapify(Heap *heap, int i, int n)
{
    int leftchild = 2*i + 1;
    int rightchild = 2*i + 2;
    int smallest = i;
    if(leftchild < n && heap->arr[1][leftchild] < heap->arr[1][smallest]){
        smallest = leftchild;
    }
    if(rightchild < n && heap->arr[1][rightchild] < heap->arr[1][smallest]){
        smallest = rightchild;
    }

    if(smallest != i){
        int swap1 = heap->arr[1][smallest];
        int swap2 = heap->arr[0][smallest];
        heap->arr[0][smallest] = heap->arr[0][i];
        heap->arr[1][smallest] = heap->arr[1][i];
        heap -> arr[0][i] = swap2;
        heap -> arr[1][i] = swap1;
        theapify(heap,smallest,n);
    }
}

void bheapify(Heap*heap,int i){
    int temp1 = heap -> arr[0][i];
    int temp2 = heap -> arr[1][i];
    while(i > 0 && temp2 < heap -> arr[1][(i-1)/2]){
        heap -> arr[1][i] = heap -> arr[1][(i-1)/2];
        heap -> arr[0][i] = heap -> arr[0][(i-1)/2];
        i = (i-1)/2;
    }
    heap -> arr[0][i] = temp1; 
    heap -> arr[1][i] = temp2; 
}

void add(Heap*heap, int v, int edge_weight){
    if(heap -> n < heap -> capacity){
        heap-> arr[0][heap -> n] = v;
        heap-> arr[1][heap -> n] = edge_weight;
        bheapify(heap,heap ->n);
        heap->n++;
    }
}

int delete(Heap * heap){

    if(heap -> n == 0){
        return -1;
    }

    int ans = heap->arr[0][0];
    heap->arr[1][0] = heap->arr[1][heap->n-1];
    heap->arr[0][0] = heap->arr[0][heap->n-1];
    heap->n--;
    theapify(heap,0,heap -> n);
    return ans;
}
int size_heap(Heap *heap){
    return heap -> n;
}

void print_ss(int dist[], int V, int source){
    for(int i=0; i<=V; i++){
        if(dist[i] != INT_MAX)
         printf("%d ---> %d with edge weight %d\n",source,i,dist[i]);
    }
}
void dijkstra(int V,int graph[][V],Heap* heap, int source){
    int dist[V + 1];
    int visited[V + 1];
    for(int i=0; i<=V; i++){
        visited[i] = 0;
    }
    for(int i=0; i <= V; i++){
        dist[i] = INT_MAX;
    }
    dist[source] = 0;
    add(heap,source,0);
    while(size_heap(heap)){
        int v = delete(heap);
        visited[v] = 1;
        for(int i=1; i <= V; i++){
            if(dist[v] != INT_MAX && graph[v][i] && !visited[i]){
                if(dist[i] > dist[v] + graph[v][i]){
                    dist[i] = dist[v] + graph[v][i];
                    add(heap,i,dist[i]);
                } 
            }
        }
    }
    print_ss(dist, V, source);
}

int main(){
    int MAX_V = 6;
    int graph[MAX_V][MAX_V];
    for(int i=0; i<MAX_V; i++){
        for(int j = 0; j < MAX_V; j++){
            graph[i][j] = 0;
        }
    }
    graph[1][4] = 2;
    graph[4][1] = 2;
    graph[1][3] = 4;
    graph[3][1] = 4;
    graph[4][2] = 6;
    graph[2][4] = 6;
    graph[2][5] = 10;
    graph[5][2] = 10;
    graph[2][3] = 5;
    graph[3][2] = 5;
    graph[3][5] = 12;
    graph[5][3] = 12;
    Heap * heap = create(100000);
    dijkstra(MAX_V,graph,heap,1);
    return 0;
}
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
    heap -> arr = (int **)malloc(sizeof(int*) * 2);
    heap -> n = 0;
    heap -> capacity = capacity;
    for(int i = 0; i < 2; i++){
        heap -> arr[i] = (int *) malloc(sizeof(int)*capacity);
    }
    return heap;
}

void theapify(Heap *heap, int i, int n){
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

void printMST(int V,int graph[][V],int parent[]){
    for(int i=0;i< V; i++){
        if(parent[i] != -1)
        printf("%d --> %d with edge weight %d\n",parent[i], i, graph[i][parent[i]]);
    }
}
void prims(int V,int graph[][V],Heap* heap){
    int dist[V];
    int visited[V];
    int parent[V];
    for(int i=0; i<V; i++){
        visited[i] = 0;
        parent[i] = -1;
    }
    for(int i=0; i < V; i++){
        dist[i] = INT_MAX;
    }
    dist[0] = 0;
    add(heap,0,0);
    for(int j=0; j < V-1; j++){
        int v = delete(heap);
        visited[v] = 1;
        for(int i=0; i < V; i++){
            if(graph[v][i] < dist[i] && graph[v][i] && !visited[i]){
                dist[i] = graph[v][i];
                parent[i] = v;
                add(heap,i,dist[i]);
            }
        }
    }
    printMST(V, graph,parent);
}

int main(){
    int V = 5;
    int graph[5][5] = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };
    
    Heap * heap = create(V);
    prims(V,graph,heap);


    return 0;
}
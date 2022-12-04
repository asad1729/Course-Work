#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


typedef struct edge {
    int source;
    int destination;
    int edge_weight;
}Edge;

typedef struct heap {
    int n;
    int capacity;
    Edge * edge;
}Heap;

int parent[100000];
int rank[100000];

int find_parent(int u) {
    if(u == parent[u]) return u;

    return parent[u] = find_parent(parent[u]);
}

void makeSet(int V){
    for(int i = 0; i <= V; i++){
        parent[i] = i;
        rank[i] = 0;
    }
}

Heap *create(int capacity){
    Heap * heap = (Heap*)malloc(sizeof(Heap));
    heap -> n = 0;
    heap -> capacity = capacity;
    heap -> edge = (Edge*)malloc(sizeof(Edge)*capacity);
}

void u(int u, int v) {
    int parent_v = find_parent(v);
    int parent_u = find_parent(u);
    if(rank[parent_u] > rank[parent_v]){
        parent[parent_v] = parent_u;
    }
    else if(rank[parent_u] < rank[parent_v]){
        parent[parent_u] = parent_v;
    }
    else{
        parent[parent_u] = parent_v;
        rank[parent_v]++;
    }
}

void theapify(Heap *heap, int i){

    int leftchild = 2*i + 1;
    int rightchild = 2*i + 2;
    int smallest = i;

    if(leftchild < heap -> n && heap -> edge[leftchild].edge_weight < heap -> edge[smallest].edge_weight){
        smallest = leftchild;
    }
    if(rightchild < heap -> n && heap -> edge[rightchild].edge_weight < heap -> edge[smallest].edge_weight){
        smallest = rightchild;
    }
    if(smallest != i){
        Edge swap = heap -> edge[i];
        heap ->edge[i] = heap -> edge[smallest];
        heap -> edge[smallest] = swap;
        theapify(heap,smallest);
    }
}
void bheapify(Heap* heap, int i){
    Edge temp = heap -> edge[i];
    while(i > 0 && heap -> edge[(i-1)/2].edge_weight > temp.edge_weight){
        heap ->edge[i] = heap -> edge[(i-1)/2];
        i = (i-1)/2;
    }
    heap -> edge[i] = temp;
}

void add(Heap* heap, int source, int destination, int edge_weight){
    heap -> edge[heap -> n].source = source;
    heap -> edge[heap -> n].destination = destination;
    heap->edge[heap -> n].edge_weight = edge_weight;
    bheapify(heap,heap->n);
    heap -> n++;
}

Edge delete(Heap * heap){
    Edge del = heap -> edge[0];
    heap-> edge[0] = heap -> edge[heap ->n-1];
    heap-> n--;
    theapify(heap,0);
    return del;
}
void krushkal(Heap* heap,int edges){
    makeSet(2*edges);
    int ans = 0;

    while(heap -> n != 0){
        Edge v = delete(heap);
        int src = v.source;
        int dest = v.destination;
        int ew = v.edge_weight;
        int parent_u = find_parent(src);
        int parent_v = find_parent(dest);
        if(parent_v != parent_u){
            u(src, dest);
            ans += ew;
            printf("%d --> %d with edge weight %d\n", src, dest,ew);
        }
    }

    printf("The cost of minimum spanning tree is %d\n",ans);

}

int main(){
    int n;
    printf("Enter number of edges\n");
    scanf("%d", &n);

    printf("Enter the source , edge and edge weight correspondingly\n");
    int u,v,e;

    Heap *heap = create(10000);

    for(int i=0; i<n; i++){
        scanf("%d %d %d",&u,&v,&e);
        add(heap,u,v,e);
    }

    krushkal(heap,n);

    return 0;
}
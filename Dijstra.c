#include <stdio.h>
#include <limits.h>

#define V 8

int minDistance(int dist[], bool sptSet[])
{

int min = INT_MAX, min_index;

for (int v = 0; v < V; v++)
if (sptSet[v] == false && dist[v] <= min)
min = dist[v], min_index = v;

return min_index;
}

int printSolution(int dist[], int n, char nodo[], int U[])
{
printf("\n\nVertex Distance from Sourcen\n");
for (int i = 0; i < V; i++)
printf("%c \t\t {%d,%c}\n", nodo[i], dist[i], nodo[U[i]]);
}

void dijkstra(int graph[V][V], int src)
{

int dist[V];
bool sptSet[V];
char nodo[V] = {'a','b','c','d','e','f','g','h'};
int U[V];
int iteracion=0, piv=0, cont1, cont2;

for (int i = 0; i < V; i++)
dist[i] = INT_MAX, sptSet[i] = false;

dist[src] = 0;

for (int count = 0; count < V-1; count++)
{

int u = minDistance(dist, sptSet);

sptSet[u] = true;
iteracion=count+1;
cont2=0;

for (int v = 0; v < V; v++){

if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
&& dist[u]+graph[u][v] < dist[v]){
dist[v] = dist[u] + graph[u][v];
U[v]= u;
if(iteracion != piv){
cont1=0;

printf("\n%d %c ", iteracion,nodo[u]);
for (int k = 0; k < V; k++){
if(sptSet[k]== false){
cont1=cont1 +1;
printf("%c",nodo[k]);
}
}
for (int j=0; j < V-cont1; j++ ){
printf(" ");
}
cont1=0;
printf(" ");
for (int k = 0; k < V; k++){
if(sptSet[k]== true){
cont1=cont1 +1;
printf("%c",nodo[k]);
}
}
for (int j=0; j < V-cont1; j++ ){
printf(" ");
}

}
while (cont2 != v){
printf(" ");

cont2=cont2+1;
}
cont2=cont2+1;
printf(" %c{%d, %c} ", nodo[v],dist[v],nodo[u]);
piv=iteracion;

}

}
}

printSolution(dist, V, nodo, U);
}

int main()
{

int graph[V][V] = {{0,2,0,3,0,0,0,0},
{4,0,4,0,6,0,0,0},
{0,6,0,0,0,7,0,0},
{0,0,0,0,5,0,4,0},
{0,0,0,6,0,4,0,3},
{0,0,0,0,0,0,0,0},
{0,0,0,2,0,0,0,5},
{0,0,0,0,0,01,0},
};
printf("I | C | Unvisited| Visited | a | b | c | d | e | f | g | h | \n");
dijkstra(graph, 0);

return 0;
}
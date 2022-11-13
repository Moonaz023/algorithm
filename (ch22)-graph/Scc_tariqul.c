#include <stdio.h>
#include <stdlib.h>

#define white 0
#define gray 1
#define black 2

int graph[101][101], color[101], s_time[101], e_time[101], predecessor[101];
int tgraph[101][101], tcolor[101];
int time = 0;
int vertex, edge;
int treeEdge[100], te=0;
int forEdge[100], fe=0;
int beckEdge[100], be=0;
int crossEdge[100], ce=0;
int topoSort[100], topo=0;

void dfsVisit(int u){
time = time+1;
s_time[u] = time;
color[u] = gray;
for(int v=1;v<=vertex;v++){
if(graph[u][v]==1){
if(color[v]==white){
treeEdge[++te] = u;
treeEdge[++te] = v;
predecessor[v] = u;
dfsVisit(v);
}
else if(color[v]==gray){
beckEdge[++be] = u;
beckEdge[++be] = v;
}
else if(color[v]==black){
if(s_time[v]>s_time[u]){
forEdge[++fe] = u;
forEdge[++fe] = v;
}
else if(s_time[v]<s_time[u]){
crossEdge[++ce] = u;
crossEdge[++ce] = v;
}
}
}
}
color[u] = black;
time = time+1;
e_time[u] = time;///-------------
topoSort[++topo] = u;
}
void dfsVisit2(int u){
tcolor[u] = gray;
printf("%d ",u);
for(int v=1;v<=vertex;v++){
if(tgraph[u][v]==1&&tcolor[v]==white){
tcolor[v] = gray;
dfsVisit2(v);
}
}
tcolor[u] = black;
}


int main(){
FILE * f = fopen("dfs2.txt","r");

fscanf(f,"%d%d",&vertex,&edge);

for(int i=1;i<=vertex;i++){
for(int j=1;j<=vertex;j++){
graph[i][j] = 0;
}
}
for(int i=0;i<edge;i++){
int a, b;
fscanf(f,"%d%d",&a,&b);
graph[a][b] = 1;
}
for(int u=1;u<=vertex;u++){
color[u] = white;
predecessor[u] = -1;
s_time[u] = 0;
e_time[u] = 0;
}
for(int u=1;u<=vertex;u++){
if(color[u]==white){
dfsVisit(u);
}
}

// Different Edges of graph
printf("Tree Edge\n");
for(int i=1;i<=te;i+=2){
printf("%d--to--%d\n",treeEdge[i],treeEdge[i+1]);
}
printf("\nBeck Edge\n");
for(int i=1;i<=be;i+=2){
printf("%d--to--%d\n",beckEdge[i],beckEdge[i+1]);
}
printf("\nForword Edge\n");
for(int i=1;i<=fe;i+=2){
printf("%d--to--%d\n",forEdge[i],forEdge[i+1]);
}
printf("\nCross Edge\n");
for(int i=1;i<=ce;i+=2){
printf("%d--to--%d\n",crossEdge[i],crossEdge[i+1]);
}
printf("\nTopological Sort\n");
for(int i=vertex;i>0;i--){
printf("%d ",topoSort[i]);
}
printf("\n\n");

// Traspose of Graph and
// Strongly connected components
for(int i=1;i<=vertex;i++){
for(int j=1;j<=vertex;j++){
tgraph[j][i] = graph[i][j];
}
}
for(int u=1;u<=vertex;u++){
tcolor[u] = white;
}
printf("Strongly Connected Components\n");
for(int u=vertex;u>0;u--){
if(tcolor[topoSort[u]]==white){
dfsVisit2(topoSort[u]);
printf("\n");
}
}
fclose(f);

return 0;
}

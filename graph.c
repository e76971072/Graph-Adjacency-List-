
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
#include "graph.h"


int main(int argc, char *argv[])
{
    int done = 0;
    char command[100];
    char command2 [100];
    graphT *myg1=NULL, *myg2=NULL;
    if(argc < 2){
        fprintf(stderr, "Usage: %s graph_filename", argv[0]);
        exit(-1);
    }
    myg1 = (graphT *) malloc(sizeof(graphT));
    if (myg1==NULL) {
        fprintf(stderr, "Cannot allocate memory for the graph");
        exit(-1);
    }
    initialize_graph(myg1, FALSE);
    read_graph(myg1,argv[1]);
    myg2 = copy_graph(myg1);
    /****************Main Menu ***********/
    
    listCommand();
    while (!done ){
        
        printf ("\nEnter your commands:  ");
        scanf ( "%s", command );
        printf ("\n" );
        if ( equal (command,"help")){
            listCommand();
        }
        else if (equal(command,"insert")){
            int x, y,w;
            printf (EXTRA3"Enter: (myg1 or myg2),[x],[y],[w]: "RESET);
            scanf ("%s %d %d %d", command2, &x,&y,&w);
            if(equal(command2,"myg1")){
                insert_edge(myg1,x,y,w);
                if(myg1->directed == FALSE){
                    insert_edge(myg1,y,x,w);
                }
                print_graph(myg1,"myg1");
            }
            else if (equal(command2,"myg2")){
                insert_edge(myg2,x,y,w);
                if(myg2->directed == FALSE){
                    insert_edge(myg2,y,x,w);
                }
                print_graph(myg2,"myg2");
            }
        }
        else if (equal(command,"copy")){
            print_graph(myg1, "myg1");
            // first implement copy_graph function and call it here
            myg2 = copy_graph(myg1);
            printf ("\n");
            print_graph(myg2, "myg2 (Copy Graph) ");
        }
        else if ( equal(command,"dfs")){
            printf ("myg1 or myg2??:" );
            scanf ("%s", command2 );
            printf ("\n");
            int v;
            int i;
            if(equal ( command2,"myg2")){
                printf ("\nEnter your starting edge: " );
                scanf ("%d",&v );
                printf( "\n" );
                setVisited_zero(myg2);
                dfs (myg2, v);
                
            }
            printf ("\nEnter your starting edge: " );
            scanf ("%d",&v );
            printf( "\n" );
            setVisited_zero(myg1);
            dfs (myg1, v);
        }
        else if ( equal (command,"print_complement")){
            printf(" Enter:[myg1 or myg2]: ");
            scanf("%s",command2); 
            if (equal(command2,"myg1")){
            print_complement (myg1);
            }
            else{
            print_complement (myg2);
            }
        }
        else if ( equal (command,"delete")){
            printf (GREEN"Enter: [myg1 or myg2], [x], [y]: "RESET);
            int node, value;
            scanf ("%s %d %d",command2,&node,&value );
            if ( equal( command2,"myg1")){
                delete_edge( myg1, node,value);
                if ( myg1->directed == FALSE){
                    delete_edge(myg1, value, node);
                }
                print_graph(myg1, "****myg1 after delete****");
            }
            else if (equal(command2,"myg2")){
                delete_edge( myg2, node,value);
                if ( myg2->directed == FALSE){
                    delete_edge(myg2, value, node);
                }
                print_graph(myg2, "***myg2 after delete****");
            }
        }
        else if ( equal (command, "number_component")){
            printf ("Enter:[myg1 or myg2] ");
            scanf ("%s",command2);
            if (equal(command2,"myg1")){
                numofCon(myg1);
            }
            else{
                numofCon (myg2);
            }
        }
        else if ( equal (command,"print_degree")){
            printf (" Enter: [myg1 or myg2]: ");
            scanf ("%s",command2);
            if ( equal(command2,"myg1")){
                print_degree(myg1);
            }
            else if (equal(command2,"myg2")){
                print_degree(myg2);
            }
        }
        else  if ( equal (command,"eleminate") ){
            int minW, maxW;
            printf ("Enter: [myg1 or myg1], [minw], [maxW]: " );
            scanf ("%s %d %d",command2, &minW, &maxW);
            if ( equal (command2,"myg1")){
                eleminate_links (myg1,minW, maxW);
                print_graph (myg1, "***Myg1 after elelinate link***" );}
            else if (equal(command2,"myg2")){
                eleminate_links (myg2,minW, maxW);
                print_graph (myg1, "***Myg2 after elelinate link***" );
            }
        }
        else if (equal(command,"quit")){
            free_graph(myg1);
            free_graph(myg2);
            exit(-1);
        }
        else if (equal(command,"bfs")){
            int start;
            printf(" Enter:[myg1 or myg2],[starting edge]:  " );
            scanf ("%s %d", command2,&start);
            if (equal(command2,"myg2")){
                bfs (myg2, start);
            }
            else if (equal(command2,"myg1")){
                bfs (myg1, start);
            }
        }
        else if (equal (command,"number_component" )){
            numofCon(myg1);
        }
        else if (equal(command,"common_links")){
            printf ("Enter:[myg1 or myg2]: ");
            scanf ("%s", command2);
            if (equal(command2,"myg1")){
                print_graph (myg1,"myg1");
                print_graph (myg2," myg2");
                printf ("\n**** Common Links (myg1 ∪ myg2) ****\n" );
                common_links ( myg1, myg2);
            }
            else if (equal(command2,"myg2")){
                print_graph (myg1,"myg1");
                print_graph (myg2,"myg2");
                printf ("\n**** Common Links(myg2 ∪ myg1)****\n" );
                common_links ( myg2, myg1);
            }
        }
        else if (equal (command,"different_links")){
            printf ("Enter:[myg1 or myg2] ");
            scanf ("%s",command2);
            if (equal(command2,"myg2")){
                print_graph(myg1,"Myg1\n" );
                printf ("\n");
                print_graph(myg2,"Myg2\n" );
                printf ("\n\n**** Myg2 - Myg1 ****\n\n" );
                different_links (myg2, myg1);
            }
            else if (equal(command2,"myg1")){
                print_graph(myg1,"Myg1\n" );
                printf ("\n");
                print_graph(myg2,"Myg2\n" );
                printf ("\n\n**** Myg1 - Myg2****\n\n" );
                different_links (myg1, myg2);
            }
        }
        else if (equal ( command,"connected")){
            printf ("Enter:[myg1 or myg2] ");
            scanf ("%s",command2);
            if (equal(command2,"myg1")){
                isConnected (myg1);
            }
            else if (equal(command2,"myg2")){
                isConnected (myg1);
            }
        }
        else if (equal(command,"print")){
            print_graph (myg1,"myg1" );
            printf ("\n");
            print_graph (myg2,"myg2" );
        }
        else{
            printf("Unrecognized command. ");
            printf("Type \"help\" for a list of commands.\n");
        }
    }
}
// NOW in a loop get commands and
// call related functions to perform them...
int equal ( char *a, char *b){
    if ( strcmp(a,b) ==0) {
        return 1;
        
    }
    return 0;
}
void initialize_graph(graphT *g, bool directed)
{
    int i;
    g->nvertices = 0;
    g->nedges = 0;
    g->directed = directed;
    for (i=1; i<=MAXV; i++)
        g->edges[i] = NULL;
    for (i=1; i<=MAXV; i++)
        g->degree[i] = 0;
}
void read_graph(graphT *g, char *filename)
{
    int i;
    int n, m, dir;
    int x, y, w;
    FILE *fp;
    if((fp=fopen(filename,"r"))==NULL){
        fprintf(stderr, "Cannot open the graph file");
        exit(-1);
    }
    fscanf(fp,"%d %d %d", &n, &m, &dir);
    g->nvertices = n;
    g->nedges = 0; // insert function will increase it;
    g->directed = dir;
    for (i=1; i<=m; i++) {
        fscanf(fp,"%d %d %d", &x, &y, &w);
        insert_edge(g, x, y, w);
        if(dir==FALSE)
            insert_edge(g, y, x, w);
    }
    fclose(fp);
}
void insert_edge(graphT *g, int x, int y, int w)
{
    edgenodeT *pe, *curr, * prev;
    pe = malloc(sizeof(edgenodeT)); // check if NULL
    int i ;
    if ( pe == NULL){
        exit(-1);
    }
    pe->weight = w;
    pe->y = y;
    curr = g->edges[x];
    prev = NULL;
    
    // case for middle or end
    while (curr != NULL){
        if (curr ->y > pe->y){
            break;
        }
        // case for insert at first
        else if (curr ->y ==  pe ->y){
            curr ->weight = pe ->weight;
            free(pe);
            return;
        }
        prev = curr;
        curr = curr ->next;
    }
    
    // SUCCESFUL INSERTION
    if ( prev == NULL ){
        g ->edges[x] = pe;
        pe ->next = curr;
    }
    else {
        prev->next = pe;
        pe ->next = curr;
    }
    
    g->degree[x]++;
    g->nedges++;
}
void print_graph(graphT *g, char *name)
{
    edgenodeT *pe;
    int i;
    if(!g) return;
    printf("Graph Name: %s\n", name);
    for(i=1; i<=g->nvertices; i++) {
        printf("Node %d: ", i);
        pe = g->edges[i];
        while(pe){
            // printf(" %d", pe->y);
            printf(" %d(w=%d),", pe->y, pe->weight);
            pe = pe->next;
        }
        printf("\n");
    }
}
void free_graph(graphT *g)
{
    edgenodeT *pe, *olde;
    int i;
    for(i=1; i<=g->nvertices; i++) {
        pe = g->edges[i];
        while(pe){
            olde = pe;
            pe = pe->next;
            free(olde);
        }
    }
    free(g);
}
graphT *copy_graph(graphT *g)
{
    graphT *newg;
    // I simply return the same graph as a copy
    // but you really need to dynamically create
    // another copy of the given graph
    newg = (graphT *) malloc (sizeof (graphT));
    if ( g == NULL) return NULL;
    int i;
    newg->nvertices = g ->nvertices;
    newg->nedges =  g->nedges;
    newg->directed = g ->directed;
    for ( i = 1;  i <= g ->nvertices; i ++ ){
        newg->degree[i] = g ->degree[i];
        newg->edges[i] = g ->edges[i];
        edgenodeT *curr = g ->edges[i];
        edgenodeT *newCurr, *prev;
        prev = NULL;
        while ( curr!= NULL ){
            
            newCurr = malloc ( sizeof ( edgenodeT));
            if ( newCurr == NULL){
                return NULL;}
            newCurr ->y = curr ->y;
            newCurr ->next = NULL;
            newCurr ->weight = curr ->weight;
            if ( prev == NULL){
                newg ->edges[i] = newCurr;
                prev = newCurr;
            }
            else {
                prev ->next = newCurr;
                prev = newCurr;
                
            }
            curr = curr ->next;
        }
    }
    return newg;
}
// your other functions

void delete_edge(graphT *g, int node, int edge) {
    
    edgenodeT *pe, *prev;
    pe = g ->edges[node];
    prev = NULL;
    while ( pe != NULL ){
        if (prev == NULL && pe->y == edge){
            g->edges[node] = pe ->next;
            free(pe);
        }
        else if (pe ->y == edge){
            prev->next = pe->next;
            free (pe);
        }
        else {
            prev = pe;
        }
        pe = pe->next;
    }
}
void print_parents ( graphT * g, int i ){
    if (g ->parents [i ] == -1){
        printf ("%d ", g ->degree[i] );
    }
    print_parents ( g, g ->parents[g ->degree[i]]);
    printf(" %d ", g ->degree[i]);
}

/* complement of graph is, on the
 undirected graph, it won't connect to itself */
// Delete the link 1 ->4 as for Example:

void eleminate_links (graphT *g, int minW, int maxW) {
    edgenodeT *pe, *temp, *prev;
    
    int i;
    for ( i = 1; i <= g ->nvertices; i ++ ){
        pe = g ->edges[i];
        prev=  NULL;
        temp = NULL;
        while ( pe != NULL) {
            // case at front:
            if (prev == NULL){
                if (pe->weight < minW || pe->weight > maxW ) {
                    g ->edges[i] = pe ->next;
                    free ( pe);
                }
            }
            else if (pe->weight< minW || pe->weight > maxW){
                prev ->next = pe ->next;
                free (pe);
            }
            else {
                prev = pe;
            }
            pe = pe ->next;
        }
    }
}
void  isConnected  (graphT *g){
    
    int i;
    edgenodeT *pe;
    if ( g ->directed){
        printf (" Purchase the next version of this program :)\n");
        return;
    }
    dfs(g,1);
    for (i = 1; i <= g ->nvertices; i ++ ){
        g ->visited[i] = 0;
    }
    for ( i = 1; i < g->nvertices; i ++  ){
        if ( g ->visited[i] == FALSE ){
            printf (" Not Connected\n ");
            return;
        }
        printf ("Connected\n ");
    }
}

void numofCon (graphT *g){
    int i, j;
    int count = 0;
    if ( g ->directed){
        printf (" Purchase the next version of this program :)\n");
        return;
    }
    setVisited_zero(g);
    for ( i = 1; i <=g->nvertices; i ++ ){
        if ( g->visited [i] == 0){
            bfs (g, i );
            count = count + 1;
        }
        
    }
    printf (" Count number of Component %d: \n", count);
}
void bfs (graphT *g,int start) {
    
    queueADT q;
    edgenodeT *pe;int v;
    if (g==NULL) return;
    q = NewQueue();
    Enqueue(q, start);
    g->visited[start] = TRUE;
    printf("Node [%d]: visited\n", start);
    while (!QueueIsEmpty(q)) {
        v = Dequeue(q);
        pe = g->edges[v];
        while (pe != NULL) {
            if (!(g->visited[pe->y] )) {
                Enqueue(q, pe->y);
                g->visited[pe->y] = TRUE;
                g ->parents[pe ->y] = v;
                printf("Node [%d]: visited\n", pe->y);
            }
            pe = pe->next;
        }
    }
}
void dfs(graphT *g, int v ) {
    edgenodeT * pe;
    if ( g == NULL ) return;
    g->visited[v] = 1;
    printf("Node [%d]:  is visited\n", v);
    pe = g->edges[v];
    while (pe != NULL) {
        if (g->visited[pe->y] == 0) {
            dfs(g, pe->y);
        }
        pe = pe->next;
    }
}
void print_complement ( graphT *g){
    int i, j;
    graphT *complement = ( graphT *) malloc ( sizeof (graphT));
    initialize_graph(complement, g ->directed );
    complement->nvertices = g->nvertices;
    edgenodeT *pe;
    for ( i = 1; i <= g->nvertices; i ++ ){
        pe = g ->edges[i];
        j = 1;
        while (j <= g ->nvertices){
            if ( pe && pe->y > j  ){
                insert_edge(complement, i, j ,0);
                //  printf("%d %d\n", i, complement->edges[i]->y);
                j ++;
            }
            else if (pe && j == pe ->y){
                pe = pe ->next;
                j++;
            }
            else {
                insert_edge(complement,i,j,0 );
                j++;
            }
            
        }
    }
    print_graph( complement, "Complement" );
    free_graph ( complement);
}

void print_degree (graphT *g) {
    int i;
    for ( i = 1; i <= g-> nvertices; i ++ ){
        edgenodeT *pe;
        int count = 0;
        pe = g ->edges[i];
        while ( pe != NULL){
            count++;
            pe = pe->next;
        }
        printf ("Node[%d] degree %d\n", i, count);
    }
}


/*********Same Node *************/
void common_links (graphT *g1, graphT *g2) {
    edgenodeT *pe1;
    edgenodeT *pe2;
    int i;
    for (i = 1; i <= g1->nvertices; i ++ ){
        pe1 = g1->edges[i];
        pe2 = g2->edges[i];
        while ( pe1!= NULL && pe2 != NULL) {
            if( pe1 ->y < pe2 ->y){
                pe1 = pe1 ->next;
            }
            else if( pe1 ->y > pe2 ->y){
                pe2 = pe2 ->next;
            }
            else{   // they both equal
                printf ("Node[%d] ---> %d(w=%d)\n", i , pe1 ->y,pe1->weight);
                pe1 = pe1 ->next;
                pe2 = pe2 ->next;
            }
        }
    }
}
void setVisited_zero (graphT * g){
    
    int i ;
    for ( i = 1; i <= g ->nvertices; i ++  ){
        g ->visited [i] = 0;
    }
}

/**************The set of difference ***************/
void different_links (graphT *g1, graphT *g2) {
    edgenodeT *pe1;
    edgenodeT *pe2;
    int i;
    for (i = 1; i <= g1->nvertices; i ++ ){
        pe1 = g1->edges[i];
        pe2 = g2->edges[i];
        while ( pe1!= NULL && pe2 != NULL) {
            if( pe1 ->y < pe2 ->y){
                printf ("Node[%d] ---> %d(w=%d)\n", i , pe1 ->y, pe1 ->weight);
                pe1 = pe1 ->next;
            }
            else if( pe1 ->y > pe2 ->y){
                // printf ("Node[%d] ---> %d(w=%d)\n", i , pe1 ->y, pe1->weight);
                pe2 = pe2 ->next;
            }
            else{
                pe1 = pe1 ->next;
                pe2 = pe2 ->next;
            }
        }
        while (pe1 != NULL){
            printf ("Node[%d] ---> %d(w=%d)\n", i , pe1 ->y, pe1 ->weight);
            pe1 = pe1 ->next;
        }
    }
}


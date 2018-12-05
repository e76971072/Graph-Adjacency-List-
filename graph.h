#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define EXTRA1  "\033[01;37m"
#define EXTRA2  "\033[01;31m"
#define EXTRA3  "\033[01;36m"
#define EXTRA4  "\033[22;33m"
#define RESET   "\x1b[0m"
// typedef enum {FALSE, TRUE} bool;
#define MAXV 100
#include <stdio.h>

typedef struct edgenode {
    int y;
    int weight;
    struct edgenode *next;
} edgenodeT;
typedef struct {
    edgenodeT *edges[MAXV+1];
    int degree[MAXV+1];
    int nvertices;
    int nedges; // number of directed edges....
    bool directed;
    int visited[MAXV + 1];
    int parents[MAXV + 1];
} graphT;
void initialize_graph(graphT *g, bool directed);
void read_graph(graphT *g, char *filename);
void insert_edge(graphT *g, int x, int y, int w);
void print_graph(graphT *g, char *name);
void free_graph(graphT *g);
graphT *copy_graph(graphT *g);
void dfs (graphT *g, int v );
void print_complement ( graphT *g);
void bfs (graphT *g,int x);
void delete_edge (graphT *g, int node, int value);
void  numofCon (graphT *g );
void eleminate_links (graphT *g, int minW, int maxW);
int equal ( char *a, char *b);
void print_degree (graphT *g);
void common_links (graphT *g1, graphT *g2);
void different_links (graphT *g1, graphT *g2);
void  isConnected  (graphT *g);
void setVisited_zero (graphT * g); 
void listCommand (){
    printf ("\n\n");
    printf ("********************************"EXTRA3"LIST OF COMMNANDS"RESET"*************************************\n");
    printf ("\n");
    printf("\t\t\t%c[4m[  copy  ]: Copy Graph\n%c[0m",27,27);
    printf("\t\t\t[insert]: Insert an edge\n" );
    printf(GREEN"\t\t\t[  delete  ]: Delete an edge" RESET"\n");
    printf (YELLOW"\t\t\t[eleminate]: Eleminate links" RESET"\n");
    printf ("\t\t\t[  print_degree  ]:print degree\n");
    printf (BLUE"\t\t\t[  dfs  ]: Depth first search"RESET"\n");
    printf (MAGENTA"\t\t\t[  bfs  ]: Breath first search"RESET"\n");
    printf (CYAN"\t\t\t[  print_complement  ]: Print complement"RESET"\n");
    printf ("\t\t\t[  print_degree  ]: print degree of graph\n" );
    printf (EXTRA1"\t\t\t[  number_component  ]: Number of complement"RESET"\n");
    printf (EXTRA2"\t\t\t[  different_links  ]: Different links"RESET"\n");
    printf (EXTRA3"\t\t\t[  common_links  ]: Common links"RESET"\n");
    printf ("\t\t\t[  print  ]: Print the graph\n");
    printf (CYAN"\t\t\t[  connected  ]:If the graph is Connected or not"RESET"\n");
    printf("\t\t\tEnter <help> for list of command\n");
    printf (RED"\t\t\t[  quit  ]: Quit program"RESET"\n");
    
}; 

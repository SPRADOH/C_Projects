// Project: Алгоритм Краскала Реализация
// Team: [Ойедиран Феликс Акинлойе, Чалве Франсис]
// Date: 20 Декабря 2025

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 1. DATA STRUCTURES AND UTILITY FUNCTIONS

// Structure for an edge
typedef struct {
    int src;
    int dest;
    int weight;
} Edge;

// Structure for a graph
typedef struct {
    int V;      // Number of vertices
    int E;      // Number of edges
    Edge* edges; // Array of edges
} Graph;

// Structure for Disjoint Set Union (Union-Find)
typedef struct {
    int* parent;
    int* rank;
    int n;
} DSU;

// 2. DISJOINT SET UNION (DSU) IMPLEMENTATION

// Create and initialize DSU
DSU* createDSU(int n) {
    DSU* dsu = (DSU*)malloc(sizeof(DSU));
    dsu->n = n;
    dsu->parent = (int*)malloc(n * sizeof(int));
    dsu->rank = (int*)malloc(n * sizeof(int));
    
    for (int i = 0; i < n; i++) {
        dsu->parent[i] = i;
        dsu->rank[i] = 0;
    }
    return dsu;
}


int find(DSU* dsu, int i) {
    if (dsu->parent[i] != i) {
        dsu->parent[i] = find(dsu, dsu->parent[i]); // Path compression
    }
    return dsu->parent[i];
}

// Union by rank
void unionSets(DSU* dsu, int x, int y) {
    int xroot = find(dsu, x);
    int yroot = find(dsu, y);
    
    if (xroot == yroot) return;
    
    // Union by rank
    if (dsu->rank[xroot] < dsu->rank[yroot]) {
        dsu->parent[xroot] = yroot;
    } else if (dsu->rank[xroot] > dsu->rank[yroot]) {
        dsu->parent[yroot] = xroot;
    } else {
        dsu->parent[yroot] = xroot;
        dsu->rank[xroot]++;
    }
}

int isConnected(DSU* dsu, int x, int y) {
    return find(dsu, x) == find(dsu, y);
}

// Free DSU memory
void freeDSU(DSU* dsu) {
    free(dsu->parent);
    free(dsu->rank);
    free(dsu);
}

// 3. COMPARATOR FUNCTION FOR SORTING EDGES

int compareEdges(const void* a, const void* b) {
    Edge* edge1 = (Edge*)a;
    Edge* edge2 = (Edge*)b;
    return edge1->weight - edge2->weight;
}

// 4. GRAPH FUNCTIONS

// Create a graph with V vertices and E edges
Graph* createGraph(int V, int E) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->E = E;
    graph->edges = (Edge*)malloc(E * sizeof(Edge));
    return graph;
}

// Free graph memory
void freeGraph(Graph* graph) {
    free(graph->edges);
    free(graph);
}

// 5. FILE I/O FUNCTIONS (REQUIREMENT 1: Reading from file)

// Read graph from file (format: first line: V E, then E lines: src dest weight)
Graph* readGraphFromFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Cannot open file %s\n", filename);
        return NULL;
    }
    
    int V, E;
    fscanf(file, "%d %d", &V, &E);
    
    Graph* graph = createGraph(V, E);
    
    for (int i = 0; i < E; i++) {
        fscanf(file, "%d %d %d", &graph->edges[i].src, 
               &graph->edges[i].dest, &graph->edges[i].weight);
    }
    
    fclose(file);
    printf("✓ Graph loaded from %s: %d vertices, %d edges\n", filename, V, E);
    return graph;
}


// 6. RANDOM GRAPH GENERATION (REQUIREMENT 2: Generate random graph)

Graph* generateRandomGraph(int V, float density) {

    int maxEdges = V * (V - 1) / 2; // For undirected graph
    int E = (int)(maxEdges * density);
    if (E < V - 1) E = V - 1; // Ensure graph is connected
    
    Graph* graph = createGraph(V, E);
    
    srand(time(NULL));
    
    for (int i = 0; i < V - 1; i++) {
        graph->edges[i].src = i;
        graph->edges[i].dest = i + 1;
        graph->edges[i].weight = rand() % 100 + 1; 
    }
    
    for (int i = V - 1; i < E; i++) {
        graph->edges[i].src = rand() % V;
        graph->edges[i].dest = rand() % V;
        
        while (graph->edges[i].src == graph->edges[i].dest) {
            graph->edges[i].dest = rand() % V;
        }
        
        graph->edges[i].weight = rand() % 100 + 1;
    }
    
    printf("✓ Random graph generated: %d vertices, %d edges (density: %.2f)\n", 
           V, E, density);
    return graph;
}


// 7. KRUSKAL'S ALGORITHM IMPLEMENTATION 

void kruskalMST(Graph* graph, int verbose) {
    int V = graph->V;
    int E = graph->E;
    
    // Step 1: Sort edges by weight
    qsort(graph->edges, E, sizeof(Edge), compareEdges);
    
    if (verbose) {
        printf("\n=== Step 1: Sorted edges ===\n");
        for (int i = 0; i < E; i++) {
            printf("Edge %d: (%d - %d) weight: %d\n", 
                   i, graph->edges[i].src, graph->edges[i].dest, 
                   graph->edges[i].weight);
        }
    }
    
    
    DSU* dsu = createDSU(V);
    
    // Array to store MST edges
    Edge* result = (Edge*)malloc((V - 1) * sizeof(Edge));
    int e = 0; 
    int i = 0; 
    int totalWeight = 0;
    
    if (verbose) {
        printf("\n=== Step 2: Building MST ===\n");
        printf("Initial DSU: ");
        for (int j = 0; j < V; j++) {
            printf("[%d:%d] ", j, dsu->parent[j]);
        }
        printf("\n");
    }
    
    // Step 2: Process edges in sorted order
    while (e < V - 1 && i < E) {
        Edge nextEdge = graph->edges[i++];
        
        if (verbose) {
            printf("\nProcessing edge %d-%d (weight: %d): ", 
                   nextEdge.src, nextEdge.dest, nextEdge.weight);
        }
        
        int x = find(dsu, nextEdge.src);
        int y = find(dsu, nextEdge.dest);
        
        if (x != y) {
            result[e++] = nextEdge;
            unionSets(dsu, x, y);
            totalWeight += nextEdge.weight;
            
            if (verbose) {
                printf("ADDED to MST (sets %d and %d were different)\n", x, y);
                printf("Current DSU: ");
                for (int j = 0; j < V; j++) {
                    printf("[%d:%d] ", j, dsu->parent[j]);
                }
                printf("\n");
            }
        } else {
            if (verbose) {
                printf("SKIPPED (would create cycle, both in set %d)\n", x);
            }
        }
    }
    
    // Step 3: Print results

    printf("MINIMUM SPANNING TREE (Kruskal's Algorithm)\n");
    printf("Total vertices: %d\n", V);
    printf("Total edges in original graph: %d\n", E);
    printf("Edges in MST: %d\n", e);
    printf("Total weight of MST: %d\n\n", totalWeight);
    
    printf("MST Edges:\n");
    printf("Src\tDest\tWeight\n");
    printf("---\t----\t------\n");
    for (int j = 0; j < e; j++) {
        printf("%d\t%d\t%d\n", 
               result[j].src, result[j].dest, result[j].weight);
    }
    
    
    free(result);
    freeDSU(dsu);
}


// 8. DEMONSTRATION WITH EXAMPLE GRAPHS (REQUIREMENT 4: Test cases)


void runExampleGraphs() {
    printf("\n=== Example 1: Small Graph (6 vertices) ===\n");
    
    // Create a sample graph
    Graph* graph1 = createGraph(6, 9);
    
    // Define edges
    Edge edges1[] = {
        {0, 1, 4}, {0, 2, 3}, {1, 2, 1},
        {1, 3, 2}, {2, 3, 4}, {2, 4, 5},
        {3, 4, 6}, {3, 5, 3}, {4, 5, 7}
    };
    
    for (int i = 0; i < 9; i++) {
        graph1->edges[i] = edges1[i];
    }
    
    kruskalMST(graph1, 1); // Verbose mode for step-by-step output
    freeGraph(graph1);
    
    printf("\n=== Example 2: Graph from file ===\n");
    Graph* graph2 = readGraphFromFile("kruskal_graph.txt");
    if (graph2 != NULL) {
        
        int step;
        printf("Select Mode:\n0.Just final result\n1.Step-by-step:\n");
        scanf(" %d",&step);
        
        if (step==1)
        {
            kruskalMST(graph2, 1); //verbose mode
            freeGraph(graph2);
        }
        
        else
        {
        kruskalMST(graph2, 0); // Non-verbose mode
        freeGraph(graph2);
        }
        
    }
}


// 9. PERFORMANCE TESTING 


void performanceTest() {
    printf("\n=== Performance Testing ===\n");
    printf("|V|\t|E|\tTime (ms)\n");
    printf("---\t---\t----------\n");
    
    int sizes[] = {100, 500, 1000, 2000, 5000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);
    
    for (int i = 0; i < num_sizes; i++) {
        int V = sizes[i];
        float density = 0.3; 
        
        // Generate graph
        Graph* graph = generateRandomGraph(V, density);
        
        // Measure time
        clock_t start = clock();
        kruskalMST(graph, 0);
        clock_t end = clock();
        
        double time_taken = ((double)(end - start)) * 1000 / CLOCKS_PER_SEC;
        
        printf("%d\t%d\t%.2f\n", V, graph->E, time_taken);
        
        freeGraph(graph);
    }
}

// ============================================================================
// 10. MAIN FUNCTION WITH MENU (REQUIREMENT: User interaction)
// ============================================================================

int main() {
    printf("========================================\n");
    printf("KRUSKAL'S ALGORITHM IMPLEMENTATION\n");
    printf("Team:\n1. Ойедиран Феликс\n2. Чалве Франсис\n");
    printf("========================================\n\n");
    
    int choice;
    
    do {
        printf("\n--- MENU ---\n");
        printf("1. Run example graph (step-by-step)\n");
        printf("2. Read graph from file\n");
        printf("3. Generate random graph\n");
        printf("4. Performance test (multiple sizes)\n");
        printf("5. Run kruskal_graph.txt (project file)\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                runExampleGraphs();
                break;
                
            case 2: {
                char filename[100];
                printf("Enter filename: ");
                scanf("%s", filename);
                Graph* graph = readGraphFromFile(filename);
                if (graph != NULL) {
                    printf("\nDisplay step-by-step? (1=Yes, 0=No): ");
                    int verbose;
                    scanf("%d", &verbose);
                    kruskalMST(graph, verbose);
                    freeGraph(graph);
                }
                break;
            }
                
            case 3: {
                int V;
                float density;
                printf("Enter number of vertices: ");
                scanf("%d", &V);
                printf("Enter density (0.1 to 0.9): ");
                scanf("%f", &density);
                
                if (density < 0.1) density = 0.1;
                if (density > 0.9) density = 0.9;
                
                Graph* graph = generateRandomGraph(V, density);
                
                printf("\nDisplay step-by-step? (1=Yes, 0=No): ");
                int verbose;
                scanf("%d", &verbose);
                kruskalMST(graph, verbose);
                freeGraph(graph);
                break;
            }
                
            case 4:
                performanceTest();
                break;
            
            case 5: {
                printf("\n=== Loading kruskal_graph.txt ===\n");
                Graph* graph = readGraphFromFile("kruskal_graph.txt");
                if (graph != NULL) {
                kruskalMST(graph, 1); // Always show step-by-step for project
                freeGraph(graph);
                } else {
                printf("Error: Could not load kruskal_graph.txt\n");
                printf("Make sure the file is in the same directory as the program.\n");
                }
                break;
            }    
            case 6:
                printf("Exiting program...\n");
                break;
                
            default:
                printf("Invalid choice! Try again.\n");
        }
        
    } while(choice != 5);
    
    return 0;
}
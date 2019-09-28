#include <iostream>
#include <string>
#include <queue>
using namespace std;

#define MAXV 200
#define MAXDEGREE 200

struct graph {
	int edges[MAXV + 1][MAXDEGREE];
	int degree[MAXV + 1];
	int n_vertices;
	int n_edges;
	int color[MAXV];
};

void insert_edge(graph* g, int x, int y, bool directed) {
	g->edges[x][g->degree[x]] = y;
	g->degree[x]++;

	if (!directed)
		insert_edge(g, y, x, true);
	else
		g->n_edges++;

}

void init_graph(graph* g) {
	g->n_edges = g->n_vertices = 0;
	for (int i = 0; i < MAXV; i++)g->degree[i] = 0;
}

void print_graph(graph* g) {
	for (int i = 0; i < g->n_vertices; i++) {
		printf("%d : ", i);
		for (int j = 0; j < g->degree[i]; j++)
			printf("%d, ", g->edges[i][j]);
		printf("\n");
	}
}

int main() {
	while (true) {
		graph g;
		cin >> g.n_vertices;
		if (g.n_vertices == 0)return 0;
		cin >> g.n_edges;
		// Setting 0's
		for (int i = 0; i < MAXV; i++) { 
			g.degree[i] = 0; 
			g.color[i] = -1; 
		}

		// Construction
		for (int i = 0; i < g.n_edges; i++) {
			int x, y;
			cin >> x >> y;
			g.edges[x][g.degree[x]] = y;
			g.edges[y][g.degree[y]] = x;
			g.degree[x]++;
			g.degree[y]++;
		}
		//Printing
		//print_graph(&g);
	
		//Bfs
		g.color[0] = 0;
		queue<int> q;
		bool discovered[MAXV];
		for (int i = 0; i < g.n_vertices; i++)
			discovered[i] = false;


		q.push(0);
		discovered[0] = true;
		while (!q.empty()) {
			int from = q.front();
			//printf("Visiting vertex %d\n", from);
			q.pop();
			for (int i = 0; i < g.degree[from]; i++) {
				int to = g.edges[from][i];
				if (!discovered[to]) {
					discovered[to] = true;
					//printf("Vertex %d is discovered\n", to);
					q.push(to);
					g.color[to] = 1 - g.color[from];
				}
			}
		}

		string can = "BICOLORABLE.";
		for (int i = 0; i < g.n_vertices; i++) {
			for (int j = 0; j < g.degree[i]; j++)
				if (g.color[i] == g.color[ g.edges[i][j]  ]) {
					can = "NOT BICOLORABLE.";
					//printf("%d and %d are the same color\n", i, j);
				}
		
		}
		/*for (int i = 0; i < g.n_vertices; i++) {
			cout << g.color[i] << ' ';
		}*/

		cout << can << endl;



	}

}

/*
3
2
0 1
1 2
*/
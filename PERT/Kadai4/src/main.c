#include <stdio.h>
#include <stdlib.h>
#include "../include/array_graph.h"
#include "../include/Kadai4.h"

void main(void)
{
	int *g[GRAPH_ITEM_NUM];
	int vs[VERTEX_NUM][VERTEX_PROPERTY];
	int es[EDGE_NUM][EDGE_PROPERTY];
	int cs[CELL_NUM][CELL_PROPERTY];
	char *fname = "graph-kadai.dat";
	int num_of_vertex = 8;
	int vid, v1, v2, eid;

	init_graph(g, vs, es, cs);
	read_data(g, fname);
	printf("Edge Data\n");
	pr_edge_all(g);
	printf("Vertex Data\n");
	pr_vertex_all(g);

	printf("最早結合点時刻\n");
	calc_earliest_node_times(g, es, vs, num_of_vertex);

	printf("最遅結合点時刻\n");
	calc_latest_node_times(g, es, vs, num_of_vertex);

	printf("クリティカルパス\n");
	trace_critical_path(g, es, vs, num_of_vertex);

}

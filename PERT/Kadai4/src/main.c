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

	printf("�ő������_����\n");
	calc_earliest_node_times(g, es, vs, num_of_vertex);

	printf("�Œx�����_����\n");
	calc_latest_node_times(g, es, vs, num_of_vertex);

	printf("�N���e�B�J���p�X\n");
	trace_critical_path(g, es, vs, num_of_vertex);
	/*vid = 3;
	printf("V%d�ڑ��ӂ̗񋓗�\n", vid);
	printf("> [v1�����_]\n");
	first_v1(g, vid, &v1, &eid);
	while (v1 != ARYGRAPH_NULL) {
		printf("> ���_�FV%d -> �ڑ��ӁFE%d -> v1�����_�ԍ��F%d\n", vid, eid, v1);
		next_v1(g, vid, &v1, &eid);
	}
	printf("> [v2�����_]\n");
	first_v2(g, vid, &v2, &eid);
	while (v2 != ARYGRAPH_NULL) {
		printf("> ���_�FV%d -> �ڑ��ӁFE%d -> v2�����_�ԍ��F%d\n", vid, eid, v2);
		next_v2(g, vid, &v2, &eid);
	}*/

}

#include "../include/Kadai4.h"

// vs[vid][4] : 最早結合点時刻用ラベル
// vs[vid][5] : 最遅結合点時刻用ラベル

int calc_local_earliest_times(int *g[GRAPH_ITEM_NUM], int es[][EDGE_PROPERTY], int vs[][VERTEX_PROPERTY], int vid);
int calc_local_latest_times(int *g[GRAPH_ITEM_NUM], int es[][EDGE_PROPERTY], int vs[][VERTEX_PROPERTY], int vid);

int calc_earliest_node_times(int *g[GRAPH_ITEM_NUM], int es[][EDGE_PROPERTY], int vs[][VERTEX_PROPERTY], int vmax)
{
	int eid = 0;
	int max = 0;
	int tmp = 0;
	int vid = 0;

	// 初期化
	vs[0][4] = 0;
	for (vid = 1; vid < vmax+1; vid++)
	{
		vs[vid][4] = calc_local_earliest_times(g, es, vs, vid);
		printf("vs[%d] : %d\n", vid, vs[vid][4]);
	}
	return 0;
}

int calc_local_earliest_times(int *g[GRAPH_ITEM_NUM], int es[][EDGE_PROPERTY], int vs[][VERTEX_PROPERTY], int vid)
{
	int v1 = 0;
	int eid = 0;
	int max = 0;
	int tmp = 0;

	first_v1(g, vid, &v1, &eid);
	while (v1 != ARYGRAPH_NULL) {
		if (v1 == vid)
		{
			next_v1(g, vid, &v1, &eid);
		}
		else
		{
			tmp = vs[v1][4] + get_label_edge(es[eid]);
			if (tmp > max)
			{
				max = tmp;
			}
			next_v1(g, vid, &v1, &eid);
		}
	}
	return max;
}

int calc_latest_node_times(int *g[GRAPH_ITEM_NUM], int es[][EDGE_PROPERTY], int vs[][VERTEX_PROPERTY], int vmax)
{
	int eid = 0;
	int max = 0;
	int tmp = 0;
	int vid = 0;

	// 初期化
	vs[0][5] = 0;
	for (vid = 1; vid < vmax + 1; vid++)
	{
		vs[vid][5] = calc_local_latest_times(g, es, vs, vid);
		printf("vs[%d] : %d\n", vid, vs[vid][5]);
	}
	return 0;
}

int calc_local_latest_times(int *g[GRAPH_ITEM_NUM], int es[][EDGE_PROPERTY], int vs[][VERTEX_PROPERTY], int vid)
{
	int v1 = 0;
	int eid = 0;
	int min = 0;
	int tmp = 0;

	first_v1(g, vid, &v1, &eid);
	while (v1 != ARYGRAPH_NULL) {
		if (v1 == vid)
		{
			next_v1(g, vid, &v1, &eid);
		}
		else
		{
			tmp = vs[v1][4] + get_label_edge(es[eid]);
			if (tmp < min)
			{
				min = tmp;
			}
			next_v1(g, vid, &v1, &eid);
		}
	}
	return min;
}

int trace_critical_path()
{
	return 0;
}
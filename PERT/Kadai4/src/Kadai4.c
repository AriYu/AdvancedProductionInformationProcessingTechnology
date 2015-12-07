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

int calc_latest_node_times(int *g[GRAPH_ITEM_NUM], int es[][EDGE_PROPERTY], int vs[][VERTEX_PROPERTY], int vmax)
{
	int eid = 0;
	int max = 0;
	int tmp = 0;
	int vid = 0;

	// 初期化
	vs[vmax][5] = vs[vmax][4];
	for (vid = vmax; vid > 0; vid--)
	{
		vs[vid][5] = calc_local_latest_times(g, es, vs, vid);
		printf("vs[%d] : %d\n", vid, vs[vid][5]);
	}
	return 0;
}

int trace_critical_path(int *g[GRAPH_ITEM_NUM], int es[][EDGE_PROPERTY], int vs[][VERTEX_PROPERTY], int vmax)
{
	int latest_time = 0;
	int earliest_time = 0;
	int v2 = 0;
	int eid = 0;
	int tij = 0;
	// 開始頂点番号 i <- 1 とする
	int start_vertex_num = 1;
	// 作業列を保存するリスト：P <- {}(空にする)とする
	int *p;
	p = (int *)malloc(sizeof(int) * vmax+1);
	for (int i = 0; i < vmax+1; i++)
	{
		p[i] = -1;
	}
	p[1] = start_vertex_num;
	int i = start_vertex_num;
	while (1)
	{
		earliest_time = vs[p[i]][4];
		first_v2(g, p[i], &v2, &eid);
		while (v2 != ARYGRAPH_NULL) {
			if (v2 == p[i])
			{
				next_v2(g, p[i], &v2, &eid);
			}
			else
			{
				latest_time = vs[v2][5];
				tij = get_label_edge(es[eid]);
				if (latest_time == (earliest_time + tij))
				{
					p[i + 1] = v2;
					break;
				}
				next_v2(g, p[i], &v2, &eid);
			}
		}
		if (p[i+1] == vmax)
		{
			break;
		}
		else
		{
			i = i + 1;
		}
	}
	
	printf("%d", p[1]);
	for (int j = 2; j <= i+1; j++)
	{
		printf(" -> ");
		printf("%d", p[j]);
	}
	printf("\n");

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

int calc_local_latest_times(int *g[GRAPH_ITEM_NUM], int es[][EDGE_PROPERTY], int vs[][VERTEX_PROPERTY], int vid)
{
	int v2 = 0;
	int eid = 0;
	int min = vs[vid][5];
	int tmp = 0;
	first_v2(g, vid, &v2, &eid);
	while (v2 != ARYGRAPH_NULL) {
		if (v2 == vid)
		{
			next_v2(g, vid, &v2, &eid);
		}
		else
		{
			if (min < 0)
			{
				min = vs[v2][5];
			}
			tmp = vs[v2][5] - get_label_edge(es[eid]);
			if (tmp < min)
			{
				min = tmp;
			}
			next_v2(g, vid, &v2, &eid);
		}
	}
	return min;
}


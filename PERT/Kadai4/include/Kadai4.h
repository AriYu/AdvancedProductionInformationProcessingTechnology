#ifndef KADAI4_H_
#define KADAI4_H_
#include "array_graph.h"

int calc_earliest_node_times(int *g[GRAPH_ITEM_NUM], int es[][EDGE_PROPERTY], int vs[][VERTEX_PROPERTY], int vmax);

int calc_latest_node_times(int *g[GRAPH_ITEM_NUM], int es[][EDGE_PROPERTY], int vs[][VERTEX_PROPERTY], int vmax);

int trace_critical_path();

#endif
#ifndef BEZIER_H_
#define BEZIER_H_

#define HDIM 4
#define BDIM 3

// パラメータベクトル(t0, t1, t2, t3)を返す
// pv : パラメータベクトルを格納する配列, t : パラメータ．0<= t <= 1の実数
void set_param_vector(double pv[BDIM + 1], double t);

// 行列とベクトルの積を求める．係数行列とパラメータベクトルの積に用いる
// u : 積演算の結果得られるベクトル．, mb : 3次のベジェ曲線用係数行列．, v : パラメータベクトル
void mulMVb(double u[BDIM + 1], double mb[BDIM + 1][BDIM + 1], double v[BDIM + 1]);

// 制御点リストとベクトルの積を求める．
// u : 積演算の結果得られるベクトル．, cps : 制御点リストを格納する2次元配列．, v : ベクトル．
void mulLCpVb(double u[HDIM], double cps[BDIM + 1][HDIM], double v[BDIM + 1]);

// パラメータ t に対応した3次のベジェ曲線上の点を求める．
// q : ベジェ曲線上の点, mb : 3次のベジェ曲線用係数行列, cps : 制御点リストを格納する2次元配列, t : パラメータ．0<= t <= 1の実数．
void on_bezier3_curve(double q[HDIM], double mb[BDIM + 1][BDIM + 1], double cps[BDIM + 1][HDIM], double t);

// 制御点行列とベクトルの積を求める
// lcp : ベクトル演算の結果得られるベクトルリスト, mcp : 制御点行列を格納する3次元配列, v : ベクトル
void mulMCpVb(double lcp[BDIM + 1][HDIM], double mcp[BDIM + 1][BDIM + 1][HDIM], double v[BDIM + 1]);

// パラメータ t に対応した3次のベジエ曲面上の点を求める
// q : ベジェ曲線上の点, mb : 3次のベジェ曲面用係数行列, cps : 制御点配列を格納する3次元配列, u and v : パラメータ. 0 <= t <= 1の実数.
void on_bezier3_surface(double q[HDIM], double mb[BDIM + 1][BDIM + 1], double cps[BDIM + 1][BDIM + 1][HDIM], double u, double v);

#endif
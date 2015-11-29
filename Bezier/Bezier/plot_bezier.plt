reset
set view equal xyz
set xlabel "X-Axis"
set ylabel "Y-Axis"
set zlabel "Z-Axis"
set ticslevel 0
set datafile separator "	"
splot for [IDX=0:1000] "../output/bezier_curve.csv" index IDX using 1:2:3 with linespoints lc rgb "blue" pt 7,for [IDX=0:1000] "../output/bezier_surface.csv" index IDX using 1:2:3 with linespoints lc rgb "red" pt 4

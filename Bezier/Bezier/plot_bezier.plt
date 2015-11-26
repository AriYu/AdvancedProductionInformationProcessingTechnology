reset
set view equal xyz
set xlabel "X-Axis"
set ylabel "Y-Axis"
set zlabel "Z-Axis"
set xrange [-1:10]
set yrange [-1:10]
set ticslevel 0
set datafile separator "	"
set cbrange[-1.5:1.5]
splot for [IDX=0:1000] "../output/bezier_curve.csv" index IDX using 1:2:3 with lines lc rgb "black" ,for [IDX=0:1000] "../output/bezier_surface.csv" index IDX using 1:2:3 with lines lc rgb "red"
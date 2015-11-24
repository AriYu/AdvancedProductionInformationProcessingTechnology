reset
set view equal xyz
set xlabel "X-Axis"
set ylabel "Y-Axis"
set zlabel "Z-Axis"
set xrange [-5:5]
set yrange [-5:5]
set ticslevel 0
set datafile separator "	"
set cbrange[-1.5:1.5]
splot for [IDX=0:1000] "../output/bezier_result.csv" index IDX using 1:2:3 with lines palette
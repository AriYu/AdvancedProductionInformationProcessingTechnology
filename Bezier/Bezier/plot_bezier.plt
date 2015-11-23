set view equal xyz
set xlabel "X-Axis"
set ylabel "Y-Axis"
set zlabel "Z-Axis"
set xrange [-5:5]
set yrange [-5:5]
set ticslevel 0
set datafile separator "	"
splot for [IDX=0:100] "../output/bezier_result.csv" index IDX using 1:2:3 pt 7 ps 2 lc rgb "black" , for [IDX=0:100] "../resource/bezier_curved_surface_control_points.csv" index IDX using 3:4:5 pt 7 ps 2 lc rgb "red" 

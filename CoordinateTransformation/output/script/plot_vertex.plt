set view equal xyz
set xlabel "X-Axis"
set ylabel "Y-Axis"
set zlabel "Z-Axis"
set xrange [-5:5]
set yrange [-5:5]
set ticslevel 0
splot for [IDX=0:100] "../txt/vertex.txt" index IDX using 1:2:3 with lines lw 2.0, for [IDX=0:100] "../txt/coordinate_x.txt" index IDX using 1:2:3 with lines lw 1.5 lc rgb "red", for [IDX=0:100] "../txt/coordinate_y.txt" index IDX using 1:2:3 with lines lw 1.5 lc rgb "green", for [IDX=0:100] "../txt/coordinate_z.txt" index IDX using 1:2:3 with lines lw 1.5 lc rgb "blue" 

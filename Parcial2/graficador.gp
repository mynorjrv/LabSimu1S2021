unset label
clear

set title "Proyeccion para 10 meses"
set grid

set key left top

set terminal pngcairo
set output 'proyeccion2.png'

set xlabel "Semanas transcurridas"
set ylabel "Peso levantado"

set xrange [0:45]
set yrange [15:280]

plot "datos", 5.785714*x + 14.428572

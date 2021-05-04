unset label
clear

set title "Gráfica de arcoseno"
set grid

set key left top

set terminal pngcairo
set output 'asin.png'

set xrange [-2:2]

plot asin(x)

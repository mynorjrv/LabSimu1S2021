unset label
clear

set title "Velocidad contra altura"
set grid

set key left top

set terminal jpeg
set output 'Velocidad contra altura AhMun.jpg'

set xlabel "h"
set ylabel "v"

plot "Info_Ah_Mun" using 1:2

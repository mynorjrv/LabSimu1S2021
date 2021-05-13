unset label
clear

set title "Velocidad contra tiempo"
set grid

set key left top

set terminal jpeg
set output 'Velocidad contra tiempo AhMun.jpg'

set xlabel "t"
set ylabel "v"

plot "Info_Ah_Mun" using 3:2

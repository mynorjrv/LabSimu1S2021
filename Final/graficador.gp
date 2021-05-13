unset label
clear

set title "Altura contra tiempo"
set grid

set key left top

set terminal jpeg
set output 'Altura contra tiempo AhMun.jpg'

set xlabel "t"
set ylabel "y"

plot "Info_Ah_Mun" using 3:1

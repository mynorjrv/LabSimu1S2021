unset label
clear

set title "Altura contra tiempo"
set grid

set key left top

set terminal jpeg
set output 'Altura contra tiempo Chac.jpg'

set xlabel "t"
set ylabel "y"

plot "Info_Chac" using 3:1

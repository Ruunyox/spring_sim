#! /bin/bash

gnuplot << EOF
set term postscript eps color enhanced
set output 'results.eps'
set title 'Spring System with Friction'
set xlabel 'Time (s)'
set ylabel 'Position (m)'
load 'dark2.pal'
plot 'output_x0_0.8.txt' with lines ls 1 lw 4 title 'X_0 = 0.8 m',\
'output_x0_1.3.txt' with lines ls 2 lw 4 title 'X_0 = 1.3 m'
EOF


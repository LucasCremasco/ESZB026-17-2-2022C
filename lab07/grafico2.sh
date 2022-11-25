#!/bin/sh
ARQUIVODADOS=/home/pi/sist_embarcados_git/lab07/gnuplot/dados3.txt
ARQUIVOSAIDA=/home/pi/sist_embarcados_git/lab07/gnuplot/dados3.png

gnuplot << EOF
set title "Título"
set ylabel "Eixo Y"
set xlabel "Eixo X"
set terminal png
set output "$ARQUIVOSAIDA"
plot "$ARQUIVODADOS" \
     linecolor rgb '#B072ad' \
     linetype 2 \
     linewidth 1 \
     pointtype 2 \
     pointsize 1.5 \
     title "meus dados" \
     with linespoints
EOF


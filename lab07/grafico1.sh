#!/bin/sh
ARQUIVODADOS=/home/pi/sist_embarcados_git/lab07/gnuplot/dados2.txt
ARQUIVOSAIDA=/home/pi/sist_embarcados_git/lab07/gnuplot/dados2.png

gnuplot << EOF
set title "Título"
set ylabel "Eixo Y"
set xlabel "Eixo X"
set terminal png
set output "$ARQUIVOSAIDA"
plot "$ARQUIVODADOS" \
     linecolor rgb '#a056c4' \
     linetype 1 \
     linewidth 4 \
     pointtype 1 \
     pointsize 1.8 \
     title "meus dados" \
     with linespoints
EOF


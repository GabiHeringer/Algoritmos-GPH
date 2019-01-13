#Instruções para plotar e fitar a curva para o algorítmo de busca ingênua.
reset

set terminal pdf
set output 'ingenua.pdf'

f(x) = a*x + b
fit f(x) 'buscas.txt' via a,b

set grid

set key righ bottom font 'arial, 10'
set key box
set xlabel "Tamanho do Vetor (n)" font 'arial,10'
set ylabel "Número de Comparações" font 'arial,10'
set title "Busca Ingênua"

plot f(x) lc 8, 'buscas.txt' lc 3 ps 0.5

set terminal pdf
set output 'binaria.pdf'

f(x) = a*log(x) + b
fit f(x) 'buscas.txt' using 1:3 via a,b

set grid
set key righ bottom font 'arial, 10'
set key box
set xlabel "Tamanho do Vetor (n)" font 'arial,10'
set ylabel "Número de Comparações" font 'arial,10'
set title "Busca Binária"

plot f(x) lc 12, 'buscas.txt' using 1:3 lc 6 ps 0.5

#fim

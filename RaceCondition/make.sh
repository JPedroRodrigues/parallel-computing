gcc base.c -o base.out
gcc fase1.c -o fase1.out
gcc fase2.c -o fase2.out

./base.out
./fase1.out
./fase2.out

rm -if *.out
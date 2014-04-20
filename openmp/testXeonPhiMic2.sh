# steps = 10k
# repeat = 10

# i7
# 128
# 256
# 512
# 1024

# ---
# Xeon / Xeon Phi
# 2048
# 4096

clear

test for 2048x2048

rm -f testBig2048.out testBig2048.out.times test2048.out

echo 'test 2048'

for i in $(seq 1 1 10)
 do
  ./a.out 2048 3 10000 ../matrix.in testBig2048.out 0 0 1
  done

echo 'test 2048 done. '
./testReduce.out testBig2048.out.times 10 > test2048.out

tail -n 4 test2048.out

echo ' '

test for 4096x4096

rm -f testBig4096.out testBig4096.out.times test4096.out

echo 'test 4096'

for i in $(seq 1 1 10)
  do
  ./a.out 4096 3 10000 ../matrix.in testBig4096.out 0 0 1
  done

echo 'test 4096 done'

./testReduce.out testBig4096.out.times 10 > test4096.out

tail -n 4 test4096.out

echo ' '

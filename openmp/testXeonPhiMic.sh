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

#test for 128x128

rm -f testBig128.out testBig128.out.times test128.out

echo 'test 128'

for i in $(seq 1 1 10)
  do
  ./a.out 128 3 10000 ../matrix.in testBig128.out 0 0 1
  done

echo 'test 128 done. '

./testReduce.out testBig128.out.times 10 > test128.out

tail -n 4 test128.out

echo ' '

#test for 256x256

rm -f testBig256.out testBig256.out.times test256.out

echo 'test 256'

for i in $(seq 1 1 10)
  do
  ./a.out 256 3 10000 ../matrix.in testBig256.out 0 0 1
  done

echo 'test 256 done'

./testReduce.out testBig256.out.times 10 > test256.out

tail -n 4 test256.out

echo ' '

#test for 512x512

rm -f testBig512.out testBig512.out.times test512.out

echo 'test 512'

for i in $(seq 1 1 10)
  do
  ./a.out 512 3 10000 ../matrix.in testBig512.out 0 0 1
  done

echo 'test 512 done'

./testReduce.out testBig512.out.times 10 > test512.out

tail -n 4 test512.out

echo ' '

#test for 1024x1024

rm -f testBig1024.out testBig1024.out.times test1024.out

echo 'test 1024'

for i in $(seq 1 1 10)
  do
  ./a.out 1024 3 10000 ../matrix.in testBig1024.out 0 0 1
  done

echo 'test 1024 done'

./testReduce.out testBig1024.out.times 10 > test1024.out

tail -n 4 test1024.out

echo ' '
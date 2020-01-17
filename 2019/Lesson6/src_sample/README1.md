## 課題１：比較してみよう

# 実行結果

$ gcc kadai1_fork.c -o fork
$ time ./fork 7
./fork 7  0.03s user 0.07s system 88% cpu 0.107 total


$ gcc kadai1_thread.c -o thread
$ time ./thread 127
./thread 127  0.00s user 0.01s system 49% cpu 0.019 total


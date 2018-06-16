## 課題２：スレッドで並列処理してみよう

## 考察

### 実行速度

~kadai2-1~

  計算結果:2000000
  ./kadai2-1  0.01s user 0.00s system 77% cpu 0.010 total


~kadai2-2~

  計算結果:2000000
  ./kadai2-2  0.01s user 0.00s system 76% cpu 0.009 total


(早すぎるのでもう少し多く！！)
※ 100倍にしてみました

↓↓↓

~kadai2-1~

  計算結果:200000000
  ./a.out  0.52s user 0.00s system 99% cpu 0.526 total


~kadai2-2~

  計算結果:200000000
  ./a.out  0.45s user 0.00s system 99% cpu 0.456 total



### 実行結果から得られたこと

計算結果にほとんど差はないが、2-2のように分けで処理した方が
早くなることが得られた。


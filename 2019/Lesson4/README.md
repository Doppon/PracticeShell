# 第四回提出課題

## 課題１
フォルダkadai1にはソースコードとテキストのサンプルのtext.txtを用意しておきました。

```
gcc kadai1.c
./a.out text.txt
```
とすることでファイル内の情報が出力されます。

## 課題２
ブラウザを開く問題でしたが、今回はRubyでの実装を行いました。
注意点としてlaunchyのgemを用いたのでインストールする必要があります。

```
gem i launchy
ruby open.rb
```
とすることで、プログラムが実行されるので任意のブラウザのURLを入力することで起動します。

## 課題３
ファイル間のコピーを行うプログラム。

```
gcc kadai3.c -o copy
./copy hoge.txt huga.txt
```
とすることでhoge.txtからhuga.txtに内容がコピーされます。

## 課題４


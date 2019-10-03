Student Number: AL16060
          Name: Sekino Doppo

# Exec01.sh


# Exec02.sh

- 課題1に対してロギングしていく機能を実装しました。

> ロギングしている実際の様子
=========================================================
$ chmod 744 Exec02.sh 
$ ./Exec02.sh 
2019-10-04T08:07:59 Create file name: Exec01_file_1.c
2019-10-04T08:07:59 Create file name: Exec01_file_2.c
2019-10-04T08:07:59 Create file name: Exec01_file_3.c
2019-10-04T08:07:59 Complete backup: Exec01_file_1.c.bak1
2019-10-04T08:08:01 Complete backup: Exec01_file_1.c.bak2
2019-10-04T08:08:03 Complete backup: Exec01_file_1.c.bak3
2019-10-04T08:08:05 Complete backup: Exec01_file_1.c.bak4
2019-10-04T08:08:07 Complete backup: Exec01_file_1.c.bak5
2019-10-04T08:08:09 Complete backup: Exec01_file_2.c.bak1
2019-10-04T08:08:11 Complete backup: Exec01_file_2.c.bak2
2019-10-04T08:08:13 Complete backup: Exec01_file_2.c.bak3
2019-10-04T08:08:15 Complete backup: Exec01_file_2.c.bak4
2019-10-04T08:08:17 Complete backup: Exec01_file_2.c.bak5
2019-10-04T08:08:19 Complete backup: Exec01_file_3.c.bak1
2019-10-04T08:08:21 Complete backup: Exec01_file_3.c.bak2
2019-10-04T08:08:23 Complete backup: Exec01_file_3.c.bak3
2019-10-04T08:08:25 Complete backup: Exec01_file_3.c.bak4
2019-10-04T08:08:27 Complete backup: Exec01_file_3.c.bak5
=========================================================

> 工夫したところ
1. 実行されているファイル名を抽出すること
ファイル名は文字列を上手く結合することによって表現しました。

2. 実行時間を可視化
shellでは`data`から日時が取ってこれるのでそれを利用しました。

# ExExec01.py


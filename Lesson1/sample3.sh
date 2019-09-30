for file in *.c
do
  echo $file
  cp $file $file.bak
done
exit

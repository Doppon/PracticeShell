mkdir Exec01_dir
cd Exec01_dir

COUNT=0
while [ $COUNT -ne 3 ]
do
  COUNT=`expr ${COUNT} + 1`
  touch Exec01_file
  echo "Just create file name: Exec01_file${COUNT}"
  sleep 0.5
done

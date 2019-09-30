mkdir Exec01_dir
cd Exec01_dir

COUNT=0
FILE_NAME="Exec01_file"

while [ $COUNT -ne 3 ]
do
  COUNT=`expr ${COUNT} + 1`
  touch "${FILE_NAME}_${COUNT}.c"
  echo "Just create file name: ${FILE_NAME}_${COUNT}.c"
  sleep 2
done

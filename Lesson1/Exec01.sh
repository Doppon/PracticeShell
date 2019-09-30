mkdir Exec01_dir
cd Exec01_dir

COUNT=0
FILE_NAME="Exec01_file"

while [ $COUNT -ne 3 ]
do
  COUNT=`expr ${COUNT} + 1`
  touch "${FILE_NAME}_${COUNT}.c"
  echo "Just create file name: ${FILE_NAME}_${COUNT}.c"
done

for file in *.c
do
  cp $file $file.bak
  echo "Just Complete backup: ${file}"
  sleep 2
done

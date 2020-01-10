COUNT=0
FILE_NAME="Exec01_file"
DIR_NAME="Exec01_dir"

mkdir $DIR_NAME
cd $DIR_NAME

while [ $COUNT -ne 3 ] # -ne: not equal to
do
  COUNT=`expr ${COUNT} + 1`
  touch "${FILE_NAME}_${COUNT}.c"
done

for file in *.c
do
  BACKUP_COUNT=0
  while [ $BACKUP_COUNT -ne 5 ] # -ne: not equal to
  do
    BACKUP_COUNT=`expr ${BACKUP_COUNT} + 1`
    cp $file "${file}.bak${BACKUP_COUNT}"
    sleep 2
  done
done

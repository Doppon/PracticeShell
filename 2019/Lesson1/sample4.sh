COUNT=0
while [ $COUNT -ne 10 ]
do
  COUNT=`expr ${COUNT} + 1`
  echo "count: ${COUNT}"
  sleep 0.5
done

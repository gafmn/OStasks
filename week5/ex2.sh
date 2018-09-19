for i in {1..1000}
do
 num=$(tail -n 1 file.txt)
 echo "$(($num + 1))" >> file.txt
done
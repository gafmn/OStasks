./ex2.sh &
while true; do
	if  ln file.txt file.txt.lock 
	then 
		sleep 1
	else
		./ex2.sh
		rm file.txt.lock
		break
	fi
done

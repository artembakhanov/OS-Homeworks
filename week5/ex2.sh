# The first argument should be name of the file.

while true; do
	if ln $1 $1.lock; then
		sleep 0.5
	else
		if [[ $# -ne 1 ]]; then 
			echo "Please enter name of the file."
			exit 1
		elif [[ ! -e $1 ]]; then 
			echo "The file does not exist. Should I create it? [y/n]: "
			read ans
			if [[ $ans == "y" ]] || [[ $ans == "Y" ]]; then
				touch $1
				echo "1" > $1 # add 1 to the first line (kostyl?? of course no)
			else
				echo "Error. Exiting..."
				exit 1
			fi
		fi
	
		lines=(`cat $1`)
		new_num=$(( ${lines[${#lines[@]}-1]}+1 )) # get last element here
		echo "$new_num" >> $1
		rm $1.lock
		break
	fi
done

# The critical region is data of the opened file.
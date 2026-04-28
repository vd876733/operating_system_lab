clear
while true
do 
	echo -e "\n1. New File  2. Display  3. Insert  4. Search  5. Modify  6. Delete  7. Exit"
	echo -n "Enter your option: "
	read ch

	case $ch in

	1)
		echo -n "Enter File name: "
		read fname
		if [ -e "$fname" ]; then
			echo "File Already Exists"
		else
			touch "$fname"
			echo "File Created Successfully"
		fi
		;;

	2)
		echo -n "Enter file name: "
		read fname
		if [ -e "$fname" ]; then
			echo "The content of File: "
			sort -n "$fname"
		else 
			echo "File Not Exists"
		fi
		;;

	3)
		echo -n "Enter File name: "
		read fname
		if [ -e "$fname" ]; then
			echo -n "Enter the Roll Number: "
			read Roll

			if grep -w "$Roll" "$fname" > /dev/null
			then
				echo "Record Already Present"
			else 
				echo -n "Enter Name: "
				read name
				echo "$Roll $name" >> "$fname"
				echo "Record Inserted Successfully"
			fi
		else 
			echo "File not Exists"
		fi
		;;

	4)
		echo -n "Enter File name: "
		read fname
		if [ -e "$fname" ]; then
			echo -n "Enter the Roll number to search: "
			read Roll

			if grep -w "$Roll" "$fname" > /dev/null
			then
				echo "Record Found:"
				grep -w "$Roll" "$fname"
			else
				echo "Record not found"
			fi	
		else
			echo "File doesn't Exist"
		fi
		;;

	5)
		echo -n "Enter the File name: " 
		read fname
		if [ -e "$fname" ]; then
			echo -n "Enter the roll number: "
			read Roll

			if grep -w "$Roll" "$fname" > /dev/null
			then
				echo -n "Enter new Roll number and Name: "
				read nroll nname

				if grep -w "$nroll" "$fname" > /dev/null
				then
					echo "Record Already present, try another roll number"
				else
					grep -vw "$Roll" "$fname" > temp
					echo "$nroll $nname" >> temp
					mv temp "$fname"
					echo "Record Modified successfully"
				fi
			else 
				echo "Record not Present"
			fi
		else 
			echo "File doesn't Exist"
		fi
		;;

	6)
		echo -n "Enter the File name: "
		read fname
		if [ -e "$fname" ]; then
			echo -n "Enter the Roll number: "
			read Roll

			if grep -w "$Roll" "$fname" > /dev/null
			then
				grep -vw "$Roll" "$fname" > temp
				mv temp "$fname"
				echo "Record Deleted Successfully"
			else 
				echo "Record Doesn't Exist"
			fi
		else 
			echo "File Doesn't Exist"
		fi
		;;

	7)
		exit
		;;

	*)
		echo "Wrong Input"
		;;
	esac
done

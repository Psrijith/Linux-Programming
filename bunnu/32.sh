if [ "$#" -ge 1 ];then
    for file in "$@";do 
    	if [ -f "$file" ];then
    		echo "file"
    	elif [ -d "$file" ];then
    		echo "directory"
    	fi
    done
else
    echo "no inputs"
fi


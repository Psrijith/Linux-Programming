read p
f=0
s=1
n=1
echo "0"
echo "1" 
for((i=0;i<$((p-2));i++))do 
	echo "$n"
	f=$s
	s=$n
	n=$((f+s))
done

	

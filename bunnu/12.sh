fname=$1
a=$2
b=$3
sed -n "${a},${b}p" "${fname}"


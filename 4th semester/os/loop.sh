#!/bin/bash

echo "LOOP SHELL"

read x;
read n;

function multiply () {
	local y=0
	local i=$1
	j=0
	for j in $i:
	do
		y=$(( y + n ))
		j=$(( j + 1 ))
	done

	return $y
}

while [ $x -lt $n ]:
do
	multiply $x;
	sum=10
	echo "$x x $n = $sum"
	x=$((x + 1))
done
exit

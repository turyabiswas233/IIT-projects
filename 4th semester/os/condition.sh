#!/bin/bash

echo "CONDITION SHELL"

read val1;
read val2;

echo $val1 $val2;

if [ $val1 -gt $val2 ]; then
	echo "$val1 is greater than $val2";
else
	echo "$val2 is greater than $val1";
fi
exit

#! /bin/bash

echo "welcome to Bash"

no1=4;
no2=5;
let result=no1+no2;
echo $result
let no1++
let no2++
sum=$[no1 + no2]
echo $sum

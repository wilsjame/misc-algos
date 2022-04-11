#!/bin/bash

names=( "A" "B" "C" )
read -p "what is the contest code? " n

for name in "${names[@]}"
do
  echo "copying $name.py -> ./problemset/"$n$name.py""
  cp "$name.py" ./problemset/"$n$name.py"
done

echo "done"


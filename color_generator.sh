o#!/bin/bash

printf '0x22222222\n' > .colors
for i in `seq 1 256`;
do
    r=$(( $RANDOM % 256 ))
    g=$(( $RANDOM % 256 ))
    b=$(( $RANDOM % 256 ))
   # r=$(( $(($RANDOM * $i)) % 256 ))
   # g=$(( $(($RANDOM * $i)) % 256 ))
   # b=$(( $(($RANDOM * $i)) % 256 ))
    x=$(( $((r << 16)) + $((g << 8)) + $b))
    printf '0x%02x%02x%02x%02x\n' 0 $r $g $b >> .colors
done

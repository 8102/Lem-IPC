#!/bin/bash

nb_team=$1
nb_player_by_team=$2

if [ $# -ne 2 ]
   then
       echo "./player_generator [nb_team] [nb_player_by_team]"
   exit
fi
for i in $(seq 1  $nb_team);
do
    for j in $(seq 1 $nb_player_by_team);
    do
	./lemipc $i &
       done
done

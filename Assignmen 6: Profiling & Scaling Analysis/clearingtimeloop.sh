#!/bin/bash
for i in {1..8}
do
	echo "#Cores:" $i >> clearingtimeresults.log 
	(time ./clearingtime.sh $i) 2>> clearingtimeresults.log
	echo "" >> clearingtimeresults.log
done

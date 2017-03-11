#!/bin/bash
LIMIT="1000"

for i in `seq 1 $LIMIT`;
do
	echo "Loop step"
	if [ ! -f file.lock ]
	then
		ln file file.lock;
	else
		continue;
	fi

	LAST=$(tail -1 file)
	echo "Write to file"
	echo $(expr $LAST + 1) >> file
	rm file.lock
done

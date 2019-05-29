#!/bin/bash

./tc < $1 > temp.c

gcc -pthread -Ischeduler scheduler/scheduler.c temp.c

rm temp.c

#!/bin/bash

echo "%CPU  PROCESO  USER" 
ps -eo %cpu,comm,user,uid  | tail -n +2 | sort | tail -n 3


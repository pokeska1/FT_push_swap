#!/bin/bash

echo -en "\033[32m________Block 1 int____________\n\033[0m"
ARG="1"; ./push_swap $ARG | wc -l 
echo -en "\033[31m2 - ARG=1!\n\033[0m"
echo -en "\033[32m_______________________________\n\033[0m"
echo -en "\033[32m\n\033[0m"
echo -en "\033[32m################################\n\033[0m"
echo -en "\033[32m________Block 2 int____________\n\033[0m"
ARG="1 2"; ./push_swap $ARG | wc -l 
echo -en "\033[31m2 - ARG=1 2!\n\033[0m"
ARG="2 1"; ./push_swap $ARG | wc -l 
echo -en "\033[31m2 - ARG=2 1!\n\033[0m"
echo -en "\033[32m_______________________________\n\033[0m"
echo -en "\033[32m\n\033[0m"
echo -en "\033[32m################################\n\033[0m"

echo -en "\033[32m________Block 3 int____________\n\033[0m"
echo -en "\033[31m2 - ARG=1 2 3!\n\033[0m"
ARG="1 2 3 "; ./push_swap $ARG | wc -l 
echo -en "\033[31m2 - ARG=1 3 2!\n\033[0m"
ARG="1 3 2"; ./push_swap $ARG | wc -l 
echo -en "\033[31m2 - ARG=2 1 3!\n\033[0m"
ARG="2 1 3 "; ./push_swap $ARG | wc -l 
echo -en "\033[31m2 - ARG=2 3 1!\n\033[0m"
ARG="2 3 1"; ./push_swap $ARG | wc -l 
echo -en "\033[31m2 - ARG=3 1 2!\n\033[0m"
ARG="3 1 2 "; ./push_swap $ARG | wc -l 
echo -en "\033[31m2 - ARG=3 2 1!\n\033[0m"
ARG="3 2 1"; ./push_swap $ARG | wc -l 
echo -en "\033[32m________________________________\n\033[0m"
echo -en "\033[32m\n\033[0m"
echo -en "\033[32m################################\n\033[0m"

echo -en "\033[32m________Block 4 int_____________\n\033[0m"
echo -en "\033[31m2 - ARG=1 2 3 4!\n\033[0m"
ARG="1 2 3 4"; ./push_swap $ARG | wc -l 
echo -en "\033[31m2 - ARG=1 2 4 3!\n\033[0m"
ARG="1 2 4 3"; ./push_swap $ARG | wc -l
echo -en "\033[31m2 - ARG=1 3 2 4!\n\033[0m"
ARG="1 3 2 4"; ./push_swap $ARG | wc -l
echo -en "\033[31m2 - ARG=1 3 4 2!\n\033[0m"
ARG="1 3 4 2"; ./push_swap $ARG | wc -l
echo -en "\033[31m2 - ARG=1 4 3 2!\n\033[0m"
ARG="1 4 3 2"; ./push_swap $ARG | wc -l
echo -en "\033[31m2 - ARG=1 4 2 3!\n\033[0m"
ARG="1 4 2 3"; ./push_swap $ARG | wc -l
echo -en "\033[31m2 - ARG=4 3 2 1!\n\033[0m"
ARG="4 3 2 1"; ./push_swap $ARG | wc -l
echo -en "\033[31m2 - ARG=2 1 4 3!\n\033[0m"
ARG="2 1 4 3"; ./push_swap $ARG | wc -l
echo -en "\033[32m_______________________________\n\033[0m"
echo -en "\033[32m\n\033[0m"
echo -en "\033[32m################################\n\033[0m"



echo -en "\033[32m________Block 5 int____________\n\033[0m"
echo -en "\033[31m1 - ARG=1 2 3 4 5!\n\033[0m"
ARG="1 2 3 4 5"; ./push_swap $ARG | wc -l 
echo -en "\033[31m2 - ARG=2 3 4 5 1!\n\033[0m"
ARG="2 3 4 5 1"; ./push_swap $ARG | wc -l  
echo -en "\033[31m3 - ARG=2 5 4 3 1!\n\033[0m"
ARG="2 5 4 3 1"; ./push_swap $ARG | wc -l  
echo -en "\033[31m4 - ARG=9 8 7 6 5!\n\033[0m"
ARG="9 8 7 6 5"; ./push_swap $ARG | wc -l  
echo -en "\033[31m5 - ARG=8 7 6 5 9!\n\033[0m"
ARG="8 7 6 5 9"; ./push_swap $ARG | wc -l  
echo -en "\033[31m6 - ARG=9 6 7 8 5!\n\033[0m"
ARG="9 6 7 8 5"; ./push_swap $ARG | wc -l  
echo -en "\033[31m7 - ARG=8 5 6 7 9!\n\033[0m"
ARG="8 5 6 7 9"; ./push_swap $ARG | wc -l  
echo -en "\033[32m________________________________\n\033[0m"
echo -en "\033[32m\n\033[0m"
echo -en "\033[32m################################\n\033[0m"


echo -en "\033[32m_______Block 100 int____________\n\033[0m"

echo -en "\033[32m________________________________\n\033[0m"
echo -en "\033[32m\n\033[0m"
echo -en "\033[32m################################\n\033[0m"


echo -en "\033[32m________Block 500 int___________\n\033[0m"

echo -en "\033[32m________________________________\n\033[0m"
echo -en "\033[32m\n\033[0m"
echo -en "\033[32m################################\n\033[0m"
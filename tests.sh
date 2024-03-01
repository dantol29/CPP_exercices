#!/bin/bash

cmd='./file'

PURPLE='\033[0;35m'
BLUE='\033[0;34m'
GREEN='\033[0;32m'
RED='\033[0;31m'
RESET='\033[0m' 

cat /etc/os-release > 42.42

echo -e "\n${PURPLE}Too many arguments: ${RESET}"
echo -e "${BLUE}${cmd} 42.42 2 3 4${RESET}"
echo -e "Output: $(${cmd} 42.42 2 3 4)"
grep "xxx" 42.42.replace
if [ $? -eq 2 ]; then
	echo -e "${GREEN}OK${RESET}\n"
else
	echo -e "${RED}KO${RESET}\n"
fi

echo -e "${PURPLE}File does not exist: ${RESET}"
echo -e "${BLUE}${cmd} ranDoMname 2 3${RESET}"
echo -e "Output: $(${cmd} ranDoMname 2 3)"
grep "xxx" ranDoMname.replace
if [ $? -eq 2 ]; then
	echo -e "${GREEN}OK${RESET}\n"
else
	echo -e "${RED}KO${RESET}\n"
fi
echo -e "${PURPLE}No matches found: ${RESET}"
echo -e "${BLUE}${cmd} 42.42 xxx zzz${RESET}"
echo -e "Output: $(${cmd} 42.42 xxx zzz)"
grep "xxx" 42.42.replace
if [ $? -eq 2 ]; then
	echo -e "${GREEN}OK${RESET}\n"
else
	echo -e "${RED}KO${RESET}\n"
fi

echo -e "${PURPLE}Replace 1 character: ${RESET}"
echo -e "${BLUE}${cmd} 42.42 N Z${RESET}"
echo -e "Output: $(${cmd} 42.42 N Z)"
grep "N" 42.42.replace
if [ $? -eq 1 ]; then
	echo -e "${GREEN}OK${RESET}\n"
else
	echo -e "${RED}KO${RESET}\n"
fi

echo -e "${PURPLE}Replace a string: ${RESET}"
echo -e "${BLUE}${cmd} 42.42 NAME LOL${RESET}"
echo -e "Output: $(${cmd} 42.42 NAME LOL)"
grep "NAME" 42.42.replace
if [ $? -eq 1 ]; then
	echo -e "${GREEN}OK${RESET}\n"
else
	echo -e "${RED}KO${RESET}\n"
fi

echo -e "${PURPLE}Replace a string that repeats: ${RESET}"
echo -e "${BLUE}${cmd} 42.42 URL HAHA${RESET}"
echo -e "Output: $(${cmd} 42.42 URL HAHA)"
grep "URL" 42.42.replace
if [ $? -eq 1 ]; then
	echo -e "${GREEN}OK${RESET}\n"
else
	echo -e "${RED}KO${RESET}\n"
fi

echo -e "${PURPLE}Replace a string with empty space: ${RESET}"
echo -e "${BLUE}${cmd} 42.42 URL \"     \"${RESET}"
echo -e "Output: $(${cmd} 42.42 URL "      ")"
grep "URL" 42.42.replace
if [ $? -eq 1 ]; then
	echo -e "${GREEN}OK${RESET}\n"
else
	echo -e "${RED}KO${RESET}\n"
fi

rm -rf 42.42
rm -rf 42.42.replace
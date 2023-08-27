#!/bin/sh

echo "Compiling..."

read -p "Which operating system are you using: (1) Linux, (2) MacOS: " os

if [ "$os" = "1" ]; then
    make linux
    elif [ "$os" = "2" ]; then
    make bonus
else
    echo "Invalid choice!"
    exit
fi

clear

echo "Welcome to So Long!"

while [ 1 ]; do
    read -p "Choose a map from 1 to 4, or write 'exit' to exit: " n
    
    if [ "$n" = "1" ]; then
        ./so_long ./maps/astro.ber
        elif [ "$n" = "2" ]; then
        ./so_long ./maps/lol.ber
        elif [ "$n" = "3" ]; then
        ./so_long ./maps/mtf.ber
        elif [ "$n" = "4" ]; then
        ./so_long ./maps/enemies.ber
        elif [ "$n" = "exit" ]; then
        exit
    else
        echo "Invalid choice!"
    fi
done

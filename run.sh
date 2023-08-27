#!/bin/sh

echo "Compiling..."

make

clear

echo "Welcome to So Long!"

while [ 1 ]; do
    read -p "Choose a map from 1 to 4, or write 'exit' to exit: " n
    
    if [ $n -eq 1 ]; then
        ./so_long ./maps/astro.ber
        elif [ $n -eq 2 ]; then
        ./so_long ./maps/lol.ber
        elif [ $n -eq 3 ]; then
        ./so_long ./maps/mtf.ber
        elif [ $n -eq 3 ]; then
        ./so_long ./maps/enemies.ber
        elif [ $n = "exit" ]; then
        exit
    else
        echo "Invalid choice!"
    fi
done

#!/bin/bash
 
for file in *.asm; do
    ./m4caller "${file%.*}"
done

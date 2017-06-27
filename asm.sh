#!/bin/sh

IR_BRANCH=(B BNZ BZ)
IR_ALL=(LD ST ADD CMP MLT LI ADDI)+$IR_BRANCH

cat input.txt | \
    sed -e "s/#/\/\//g" | \
    sed -E "s/$IR_ALL/\1/" | \
    sed -E "s/$IR_ALL/s/$/);/" | \
    sed -E "s/:/:\n/g" | \
    sed -E "$IR_BLANCH/s/://g" | \
    sed -E "s/[<space>|<tab>]//g"


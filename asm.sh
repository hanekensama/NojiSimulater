#!/bin/bash

IR_BRANCH="(B|BNZ|BZ)"
IR_ALL="(LD|ST|ADD|CMP|MLT|LI|ADDI|B|BNZ|BZ)"

echo '#include "asm.h"'
echo ''
echo 'int main() {' 

cat /dev/stdin | \
    sed -E "s/ //g" | \
    sed -e "s/#/\/\//g" | \
    sed -E "/$IR_BRANCH.*:$/s/:$//" | \
    sed -E "s/$IR_ALL/  \1(/" | \
    sed -E "/$IR_ALL/s/$/);/" | \
    sed -E "s/:/:\n/g" | \
    sed -E "s/B\(HALT\);/\/* & *\//i"

echo '  reg();'
echo '  return 0;'
echo '}'
echo '' 

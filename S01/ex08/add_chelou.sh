echo $FT_NBR2 + $FT_NBR1 | tr 'mrdoc' '01234' | tr '\\\"\?\!' '1234' | tr "\'" "0" | xargs echo 'obase=13; ibase=5;' | bc | tr 0123456789ABC 'gtaio luSnemf'

#!/bin/bash

cd /home/abdessamad/push_swap

make re 2>&1 | tail -1

echo "=== Testing 3-number permutations ==="
for ARG in "1 2 3" "1 3 2" "2 1 3" "2 3 1" "3 1 2" "3 2 1"; do
    echo -n "$ARG: "
    ./push_swap $ARG | ./checker_linux $ARG
done

echo ""
echo "=== Testing 4-number permutations ==="
for a in 1 2 3 4; do
    for b in 1 2 3 4; do
        for c in 1 2 3 4; do
            for d in 1 2 3 4; do
                if [ "$a" != "$b" ] && [ "$a" != "$c" ] && [ "$a" != "$d" ] && [ "$b" != "$c" ] && [ "$b" != "$d" ] && [ "$c" != "$d" ]; then
                    echo -n "$a $b $c $d: "
                    ./push_swap $a $b $c $d | ./checker_linux $a $b $c $d
                fi
            done
        done
    done
done

echo ""
echo "=== Testing 5-number permutations ==="
for a in 1 2 3 4 5; do
    for b in 1 2 3 4 5; do
        for c in 1 2 3 4 5; do
            for d in 1 2 3 4 5; do
                for e in 1 2 3 4 5; do
                    if [ "$a" != "$b" ] && [ "$a" != "$c" ] && [ "$a" != "$d" ] && [ "$a" != "$e" ] && [ "$b" != "$c" ] && [ "$b" != "$d" ] && [ "$b" != "$e" ] && [ "$c" != "$d" ] && [ "$c" != "$e" ] && [ "$d" != "$e" ]; then
                        echo -n "$a $b $c $d $e: "
                        ./push_swap $a $b $c $d $e | ./checker_linux $a $b $c $d $e
                    fi
                done
            done
        done
    done
done

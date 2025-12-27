#!/bin/bash

ARGS=$(shuf -i 1-9000 -n 500 | tr '\n' ' ')

result=$(./push_swap $ARGS | ./checker_linux $ARGS)
mine=$(./push_swap $ARGS | ./checker $ARGS)

echo "42 = $result"
echo "Mine = $mine"

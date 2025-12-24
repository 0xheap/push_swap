#!/bin/bash

ARGS=$(shuf -i 1-500 -n 500 | tr '\n' ' ')

result=$(./push_swap $ARGS | ./checker_linux $ARGS)

echo $result

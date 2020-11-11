#!/bin/bash

echo 'What size input?'
read input
./RandomGenerator $input | ./sorting_test -mqicd

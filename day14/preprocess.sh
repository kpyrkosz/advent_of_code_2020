#!/bin/bash

sed -E 's/^mask = /m /g;s/mem\[(.*)\] =/w \1/g'

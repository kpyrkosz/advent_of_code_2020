#!/bin/bash

sed 's/^$/-/g' input | tr \\n \  | sed 's/ - /\n/g' > cleaned

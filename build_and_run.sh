#!/usr/bin/env bash
source ./venv/bin/activate

output=$(make -C ./libIMDB/ 2>&1)

if [ $? -ne 0 ]; then
    echo "Build Failed"
    echo "$output"
    exit 1
fi

python CA5.py

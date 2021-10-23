#!/usr/bin/env sh

go build -o ./rick-roll-server
./rick-roll-server &

make -C db compile
cd db && ./database &

wait

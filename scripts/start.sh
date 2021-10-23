#!/usr/bin/env sh

# kill children one SIGINT
trap 'trap " " SIGTERM; kill 0; wait' SIGINT SIGTERM

go build -o ./rick-roll-server
./rick-roll-server &

make -C db compile
cd db && ./database &

wait

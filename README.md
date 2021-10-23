## Intro
An extremely convoluted yet necessary solution to the Rickroll epidemic.

## Architecture
- Website
    - Interfaces with webserver through simple http requests
    - User can enter url and will get a response detailing if the link is a rick roll
- Webserver
    - Returns the webpage at `/` or receives a url to detect at `/search?query=<query>`
- Rick roll detector service
    - A go service running a rpc server. Way over the top.
- In-memory database
    - Cache search queries
- Two micro services written in go. One service accepts rpc client requests to check if a given url references Rick Astley. The other service handles http requests and client A server which either returns a html file or

## TODO
- Give more in depth detail about decisions made for architecture (why, what, how, etc.)
- Having trouble with running in a docker container, will come back to it later.

## Running
- `./scripts/start.sh` will compile and run the database and webserver

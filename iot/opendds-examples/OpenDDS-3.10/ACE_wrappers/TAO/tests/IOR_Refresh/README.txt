$Id: README.txt 2646 2015-08-28 00:38:05Z mesnierp $

Auto Tests:
1. server uses api to set refresh, shared profile
2. server uses 1 endpoint per profile
3. server has multiple acceptors
4. server uses named host
5. server uses resource factory setting

Manual test:
disconnect/disable one or more network interfaces
start server
start client with disabled ip address
enable network interfaces
start client with same ip address


all:subsystem BIN

subsystem:
	cd SocketClass && $(MAKE)
	cp ./SocketClass/Socket.* ./

BIN:bin/tcpRec bin/tcpsend

bin/tcpRec:TCPRecv.o Socket.o
	g++ -g -o bin/tcpRec TCPRecv.o Socket.o

bin/tcpsend:TCPSend.o Socket.o
	g++ -g -o bin/tcpsend TCPSend.o Socket.o

TCPRecv.o:TCPRecv.cpp
	g++ -g -c TCPRecv.cpp

TCPSend.o:TCPSend.cpp
	g++ -g -c TCPSend.cpp

clean:
	rm *.o bin/tcpRec bin/tcpsend
	cd SocketClass && make clean

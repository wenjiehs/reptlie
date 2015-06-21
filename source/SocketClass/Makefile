
VPATH=SocketClass

CC=g++
OPTION=-g

sockcpp=SocketException.cpp Address.cpp Datagram.cpp CommonSocket.cpp TCP.cpp UDP.cpp
socklib=SocketException.o   Address.o  Datagram.o   CommonSocket.o   TCP.o   UDP.o



#all:bin/TCPReceive  bin/TCPSend
#bin/TCPReceive:TCPRecv.o $(socklib)
#		$(CC) $(OPTION) -o bin/TCPReceive TCPRecv.o $(socklib)
#bin/TCPSend:TCPSend.o $(socklib)
#		$(CC) $(OPTION) -o bin/TCPSend  TCPSend.o $(socklib)
#TCPRecv.o:
#		$(CC) -c $(OPTION)  TCPRecv.cpp
#TCPSend.o:
#		$(CC) -c $(OPTION)  TCPSend.cpp
#$(socklib):  $(sockcpp)  Socket.h
#		$(CC) -c $(OPTION)  $(sockcpp)

socket.o:Socket.cpp
	$(CC) $(OPTION) -c Socket.cpp

clean:
	rm *.o
#		rm bin/TCPReceive bin/TCPSend *.o

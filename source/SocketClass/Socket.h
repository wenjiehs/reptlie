/**
* > File Name: Socket.h
* > Author: wenjie
* > Mail: 564369394@qq.com
* > Created Time: Sat 20 Jun 2015 07:36:21 PM PDT
*/

#ifndef _SOCKET_H
#define _SOCKET_H

#include <iostream>
#include <sstream>
#include <exception>
#include <string>
#include <vector>
#include <fstream>

#ifdef __cplusplus
extern "C"
{
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <netdb.h>
}
#endif

#define SOCKET_MAX_BUFFER_LEN 1024

using namespace std;

namespace Socket
{
    typedef int SocketId;
    typedef string Ip;
    typedef unsigned int Port;

    ///Custom exception class
    class SocketException : public exception
    {
    public:
        SocketException(const string &);
        ~SocketException() throw();

        virtual const char * what() const throw();
        friend ostream& operator<< (ostream &out, SocketException &e);
    private:
        string _error;
    };
    
    ///Package Ip Address
    struct Address : protected sockaddr_in
    {
    public:
        Address();
        Address(Port);
        Address(Ip, Port);
        Address(struct sockaddr_in);
        Address(const Address&);

        Ip ip(void);///< Returns Ip Address
        Ip ip(Ip);///< Ip set and the return address
       
        Port port(void);///< Returns the port number
        Port port(Port);///< Set the port number and returns

        friend ostream& operator<<(ostream&, Address&);
    private:
        void _address(Ip ip, Port port);
    };

    template <class DataType>
    struct Datagram
    {
    public:
        Address address;
        DataType data;
        unsigned int received_bytes;
        unsigned int received_elements;

        template<class T>
        void operator=(const Datagram<T> &);
    };

    class CommonSocket
    {
    public:
        CommonSocket(void);
        CommonSocket(int);
        ~CommonSocket(void);

        void open();
        void close();

        virtual void listen_on_port(Port);
    protected:
        SocketId _socket_id;
        int _socket_type;
        bool _opened;
        bool _binded;

    private:
        void _socket();
    };

    class TCP : public CommonSocket
    {
    public:
        TCP();
        TCP(const TCP &);

        Ip ip(void);
        Port port();
        Address address();
         
        void listen_on_port(Port, unsigned int );
        void connect_to(Address);

        TCP accept_client();

        template<class T> int send(const T* ,size_t);
        template<class T> int receive(T*, size_t);

        void send_file(string);
        void receive_file(string);

    private:
        Address _address;

    };

    class UDP : public CommonSocket
    {
    public:
        UDP();
        UDP(const UDP&);

        template <class T> int send(Ip, Port, const T*, size_t);
        template <class T> int send(Address, const T*, size_t);
        template <class T> int send(Ip, Port, T);
        template <class T> int send(Address, T);
        template <class T> int send(Ip, Port, vector<T>);
        template <class T> int send(Address, vector<T>);
                
        template <class T> int receive(Address*, T*, size_t, unsigned int*);
        template <class T> Datagram<T*> receive(T*, size_t);
        template <class T, size_t N> Datagram<T[N]> receive(size_t);
        template <class T> Datagram<T> receive(void);
        template <class T> Datagram<vector<T> > receive(size_t);
    };
}


#endif

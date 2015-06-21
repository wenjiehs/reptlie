/**
* > File Name: Address.cpp
* > Author: wenjie
* > Mail: 564369394@qq.com
* > Created Time: Sat 20 Jun 2015 08:45:26 PM PDT
*/

#ifndef _ADDRESS_CPP_
#define _ADDRESS_CPP_

#include"Socket.h"

namespace Socket
{
    void Address::_address(Ip ip, Port port)
    {
        this->sin_family = AF_INET;
        this->ip(ip);
        this->port(port);
    }
    
    Address::Address()
    {
        _address("0.0.0.0", 0);
    }

    Address::Address(Port port)
    {
        _address("0.0.0.0", port);
    }

    Address::Address(Ip ip, Port port)
    {
        _address(ip, port);
    }

    Address::Address(struct sockaddr_in address)
    {
        _address(inet_ntoa(address.sin_addr), address.sin_port);
    }

    Address::Address(const Address& address)
    {
        this->sin_family = address.sin_family;
        this->sin_addr = address.sin_addr;
        this->sin_port = address.sin_port; 
    }

    Ip Address::ip(void)
    {
        return inet_ntoa(this->sin_addr);
    }

    Ip Address::ip(Ip ip)
    {
        if(inet_aton(ip.c_str(), &this->sin_addr) == 0)
        {
            stringstream error;
            error << "[ip] with [ip = " << ip << "] invalid ip address provided";
            throw SocketException(error.str());
        }
        return this->ip();
    }

    Port Address::port(void)
    {
        return ntohs(this->sin_port);
    }
    
    Port Address::port(Port port)
    {
        this->sin_port = htons(port);
        return this->port();
    }

    ostream& operator<< (ostream &out, Address &address)
    {
        out << address.ip() << ":" <<address.port();
        return out;
    }

}
#endif

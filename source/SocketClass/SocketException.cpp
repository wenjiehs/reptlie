/**
* > File Name: SocketException.cpp
* > Author: wenjie
* > Mail: 564369394@qq.com
* > Created Time: Sat 20 Jun 2015 08:33:29 PM PDT
*/

#ifndef _SOCKETEXCEPTION_CPP_
#define _SOCKETEXCEPTION_CPP_

#include"Socket.h"

namespace Socket
{
    SocketException::SocketException(const string &message)
    {
        this->_error;
    }

    SocketException::~SocketException() throw()
    {
        
    }

    const char * SocketException::what() const throw()
    {
        return this->_error.c_str();
    }

    ostream& operator<<(ostream &out, SocketException &e)
    {
        out<<e.what();
        return out;
    }

}

#endif

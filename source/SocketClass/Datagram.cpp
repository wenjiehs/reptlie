/**
* > File Name: Datagram.cpp
* > Author: wenjie
* > Mail: 564369394@qq.com
* > Created Time: Sat 20 Jun 2015 09:16:51 PM PDT
*/

#ifndef _DATAGRAM_CPP
#define _DATAGRAM_CPP

#include"Socket.h"

namespace Socket
{
    template<class DataType>
    template<class T>
    void Datagram<DataType>::operator= (const Datagram<T>&datagram)
    {
        this->address = datagram.address;
        this->data = datagram.data;
    }
}


#endif

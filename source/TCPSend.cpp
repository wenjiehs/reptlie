/**
* > File Name: TCPSend.cpp
* > Author: wenjie
* > Mail: 564369394@qq.com
* > Created Time: Sat 20 Jun 2015 11:48:46 PM PDT
*/

#include "Socket.h"

using namespace std;

#define IP   "127.0.0.1"
#define PORT 10000

int main(void)
{
    try
    {
        Socket::TCP server;
        server.connect_to(Socket::Address(IP, PORT));

        cout << "sending ..." << endl;
        server.send_file("input.bmp");    
    }

    catch (Socket::SocketException &e)
    {
        cout << e << endl;    
    }
    return 0;

}


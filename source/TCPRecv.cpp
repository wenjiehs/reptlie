/**
* > File Name: TCPRecv.cpp
* > Author: wenjie
* > Mail: 564369394@qq.com
* > Created Time: Sat 20 Jun 2015 11:24:31 PM PDT
*/
#include "Socket.h"

using namespace std;

int main(void)
{
    try
    {
        Socket::TCP server;   
        server.listen_on_port(10000, 5);
        Socket::TCP client = server.accept_client();
        cout << "receiving ..." << endl;
        client.receive_file("output.bmp");    
    }
    
    catch (Socket::SocketException &e)
    {
        cout << e << endl;    
    }
    return 0;

}

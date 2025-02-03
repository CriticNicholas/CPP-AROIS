#include<Interface.hpp>

#define Ip "127.0.0.1"
#define Port 65432

void Read(Network::Socket* Socket)
{
    while(true)
    {
        std::cout << Socket->Read() << std::endl;
    }

}

int main()
{
    setlocale(LC_ALL, "RUS");

    Network::Socket Socket(Ip, Port);

    Socket.Host();

    std::cout << "[*] Server started on " << Ip << ':' << Port << std::endl;

    std::thread Reader(Read, &Socket);

    std::this_thread::sleep_for(std::chrono::seconds(10));

    Socket.Write("shutdown");

    Reader.detach();

    Socket.Close();
}
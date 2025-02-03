#include<Interface.hpp>

#define Ip "127.0.0.1"
#define Port 65432

void Write(Network::Socket* Socket, Implant::PseudoImplant* PseudoImplant)
{
    while(true)
    {
        Socket->Write(PseudoImplant->GetAll());
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

int main()
{
    setlocale(LC_ALL, "RUS");

    Implant::PseudoImplant PseudoImplant;
    Network::Socket Socket(Ip, Port);

    Socket.Connect();

    std::cout << "[+] Connect to the server " << Ip << ':' << Port << std::endl;

    std::thread Writer(Write, &Socket, &PseudoImplant);

    while(true)
    {
        std::string Command;

        Command = Socket.Read();

        if(Command == "shutdown")
        {
            Socket.Close();

            Writer.detach();

            return 0;
        }
    }


    return -1;
}
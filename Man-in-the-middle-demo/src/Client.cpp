#include"Interface/Interface.hpp"

int main()
{
    Implant::PseudoImplant PseudoImplant;
    Network::Socket Socket("127.0.0.1", 2001);

    Socket.Connect();

    for(int i = 0; i < 125; ++i)
    {
        Socket.Write(PseudoImplant.GetRandomParameters());
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }

    Socket.Close();

    return 0;
}
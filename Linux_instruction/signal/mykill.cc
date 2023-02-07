#include <iostream>
#include <unistd.h>
#include <signal.h>
#include <string>
#include <stdlib.h>

void Usage(const std::string& proc)
{
    std::cerr << "Usage:\n\t" << proc << " -signum pid" << std::endl;
}
int main(int argc,char* argv[])
{
    if(argc != 3)
    {
        Usage(argv[0]);
        exit(-1);
    }

    std::string signo = argv[1];//获取 -signum eg:-9
    signo = signo.substr(1);//获取signum eg:9

    kill((pid_t)atoi(argv[2]),atoi(signo.c_str()));//系统指令

    std::cout << "kill done" << std::endl;
    return 0;
}
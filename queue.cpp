#include <arpa/inet.h>
#include <queue>
#include <thread>
#include <sys/socket.h> // For socket functions
#include <netinet/in.h> // For sockaddr_in
#include <cstdlib> // For exit() and EXIT_FAILURE
#include <iostream> // For cout
#include <unistd.h> // For read

void buidQueue(std::queue<int> &rcvData,int element){
    int recv_data=socket(AF_INET,SOCK_STREAM,0);
    sockaddr_in server_address;
    server_address.sin_family=AF_INET;
    server_address.sin_port=htons(2222);
    server_address.sin_addr.s_addr=inet_addr("127.0.0.1");
     rcvData.push(element);
 }
void processQueue(std::queue<int> &rcvData,std::queue<int> &prcData){
   if (!rcvData.empty()){
    std::cout<<rcvData.front()<<std::endl;
    prcData.push(rcvData.front());
    std::cout << "processed data" << prcData.back()<< std::endl;
    rcvData.pop();

   }else{
       std::cout<<"we are done ! \n";
   }
}
int main(int argc, char *argv[])
{
   std::queue<int> rcvData ;
   std::queue<int> prcData ;

   std::thread readDataFromPort(buidQueue,std::ref(rcvData),3);
   readDataFromPort.join();
   std::thread processDataFromPort(processQueue,std::ref(rcvData),std::ref(prcData));
   processDataFromPort.join();
   //std::thread sendDataToPort();
  
   return 0;
}



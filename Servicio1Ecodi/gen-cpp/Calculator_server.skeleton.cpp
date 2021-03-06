// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "Calculator.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using boost::shared_ptr;

using namespace  ::tutorial;

class CalculatorHandler : virtual public CalculatorIf {
 public:
  CalculatorHandler() {
    // Your initialization goes here
  }

  int32_t Solicitud(const int32_t sol) {
    // Your implementation goes here
    printf("Solicitud\n");
  }

  void Generar3D(std::string& _return, const std::string& alto) {
    // Your implementation goes here
    printf("Generar3D\n");
  }

  void ping() {
    // Your implementation goes here
    printf("ping\n");
  }

};

int main(int argc, char **argv) {
  int port = 9090;
  shared_ptr<CalculatorHandler> handler(new CalculatorHandler());
  shared_ptr<TProcessor> processor(new CalculatorProcessor(handler));
  shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}


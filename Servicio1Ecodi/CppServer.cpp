/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements. See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership. The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License. You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied. See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

#include <thrift/concurrency/ThreadManager.h>
#include <thrift/concurrency/PosixThreadFactory.h>
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/server/TThreadPoolServer.h>
#include <thrift/server/TThreadedServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TTransportUtils.h>
#include <QFile>
#include <QTextStream>
#include <QDebug>

#include <iostream>
#include <stdexcept>
#include <sstream>
#include "gen-cpp/Calculator.h"
using namespace std;
using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;
using namespace apache::thrift::server;

using namespace tutorial;
using namespace boost;

class CalculatorHandler : public CalculatorIf {
 public:
  CalculatorHandler() {}

  void ping() {
    printf("pingpong\n");
  }
  int Solicitud(int sol)
{
	return sol*22;
}

void  Generar3D(std::string& _return, const std::string& alto)
{

    QFile archivo("/home/ricky/Escritorio/Compiladores2/build-Servicio1Ecodi-Desktop_Qt_5_4_1_GCC_64bit-Debug/entrada");
    archivo.open(QIODevice::WriteOnly | QIODevice::Truncate);
    QTextStream text(&archivo);
    QString txt=alto.data();
    text<<txt;
    archivo.close();
    system("./analizador entrada > resultado.txt");
    unsigned int microseconds;

    microseconds=100;
    usleep(microseconds);
    QFile leerfile("salida.txt");
    leerfile.open(QIODevice::ReadOnly);
    QTextStream textoleer(&leerfile);
    QString txta;
    txta=textoleer.readAll();

    _return= txta.toStdString();
}
};

int main(int argc, char **argv) {

  shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());
  shared_ptr<CalculatorHandler> handler(new CalculatorHandler());
  shared_ptr<TProcessor> processor(new CalculatorProcessor(handler));
  shared_ptr<TServerTransport> serverTransport(new TServerSocket(9090));
  shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());

  TSimpleServer server(processor,
                       serverTransport,
                       transportFactory,
                       protocolFactory);



  printf("Starting the server...\n");
  server.serve();
  printf("done.\n");
  return 0;
}

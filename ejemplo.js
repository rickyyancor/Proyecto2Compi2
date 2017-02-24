var thrift = require('thrift');
var Calculator = require('./gen-nodejs/Calculator');
var ttypes = require('./gen-nodejs/tutorial_types');

transport = thrift.TBufferedTransport();
protocol = thrift.TBinaryProtocol();

var connection = thrift.createConnection("localhost", 9090, {
  transport : transport,
  protocol : protocol
});

connection.on('error', function(err) {
  
});

// Create a Calculator client with the connection
var client = thrift.createClient(Calculator, connection);


client.Generar3D("2>1||9<1&&2==5;",function(err,response){
console.log(response);
connection.end();
});

client.ping(function(err, response) {
  console.log('ping()');
connection.end();
});



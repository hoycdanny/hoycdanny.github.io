var ProtoBuf = require("protobufjs");
var mqtt = require('mqtt');
var builder = ProtoBuf.load('./company.proto'),
    Company = builder.build('Company'),
    Employee = Company.Employee;

var employee = new Employee("James Bond", 007);

var buffer_message = employee.toBuffer();

var client = mqtt.connect('mqtt://test.mosquitto.org');

client.on('connect', function() {
   client.publish('MyCompany', buffer_message);
   client.end();
});

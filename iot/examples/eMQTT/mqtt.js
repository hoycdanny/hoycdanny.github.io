var mqtt = require('mqtt')
var client  = mqtt.connect('mqtt://10.28.120.28')

client.on('connect', function () {
  console.log('Conneted MQTT');
  client.subscribe('DL303/CO2')
  client.publish('DL303/Msg', 'i.m.a.c-Cloud')
})

client.on('message', function (topic, message) {
  console.log(message.toString())
  //client.end()
})

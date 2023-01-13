const MongoClient = require("mongodb").MongoClient;
const mqtt = require("mqtt");
const client = mqtt.connect("mqtt://test.mosquitto.org");

const pipeline = [
  {
    //$project: { documentKey: false },
    $match: {
      'operationType': 'insert',
      // 'fullDocument.topic': 'log',
    },
  }
];
MongoClient.connect('mongodb+srv://user1:azerty@cluster0.kqxrfop.mongodb.net')
  .then(client => {
    console.log("Connected correctly to server");
    // specify db and collections
    const db = client.db("db2");
    const collection = db.collection("data");

    const changeStream = collection.watch(pipeline);
    // start listen to changes
    changeStream.on("change", function(change) {
      const Document = change.fullDocument;
      console.log(`DB:\tDevice:${Document.deviceID}\tTopic:${Document.topic}\tData:${Document.data}`);
    });
    // insert few data with timeout so that we can watch it happening
  })
  .catch(err => {
    console.error(err);
  });

client.on("connect", function() {
  console.log("MQTT Connecetde");
});

client.on("message", function(topic, msg) {
  // console.log(topic, " : ", msg.toString());
  console.log("MQTT\t", topic, "\t", msg.toString());
});

client.on("connect", function() {
  console.log("connected  " + client.connected);
});

//handle errors
client.on("error", function(error) {
  console.log("Can't connect" + error);
  process.exit(1);
});

//////////////

var options = {
  retain: true,
  qos: 1,
};
var topic = "testtopic";
var logTopic = "YCHF/#";
// var dataTopic = "data/DZ00889654";

console.log("subscribing to topics");
client.subscribe(logTopic, { qos: 1 }); //single topic
// client.subscribe(dataTopic, { qos: 1 }); //single topic

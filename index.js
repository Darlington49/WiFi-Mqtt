const express = require("express");
// const xterm = require("xterm");
const app = express();
const http = require("http");
const server = http.createServer(app);
const MongoClient = require("mongodb").MongoClient;
const mqtt = require("mqtt");
const client = mqtt.connect("mqtt://test.mosquitto.org");
const { Server } = require("socket.io");
const io = new Server(server);

const pipeline = [
  {
    //$project: { documentKey: false },
    $match: {
      operationType: "insert",
      // 'fullDocument.topic': 'log',
    },
  },
];
MongoClient.connect("mongodb+srv://user1:azerty@cluster0.kqxrfop.mongodb.net")
  .then((client) => {
    console.log("Connected correctly to server");
    // specify db and collections
    const db = client.db("db2");
    const DataCollection = db.collection("data");
    const LogCollection = db.collection("log");

    const DataChangeStream = DataCollection.watch(pipeline);
    // start listen to changes
    DataChangeStream.on("change", function (change) {
      const Document = change.fullDocument;
      console.log(
        `DB:\t\tDevice:${Document.deviceID}\tTopic:${Document.topic}\tData:${Document.data}`
      );
      // console.log(change);
      io.emit("data", change.fullDocument);
    });

    const LogChangeStream = LogCollection.watch(pipeline);
    // start listen to changes
    LogChangeStream.on("change", function (change) {
      const Document = change.fullDocument;
      console.log(
        `DB:\t\tDevice:${Document.deviceID}\tTopic:${Document.topic}\tData:${Document.data}`
      );
      io.emit("log", change.fullDocument);

      // console.log(change);
    });
  })
  .catch((err) => {
    console.error(err);
  });

client.on("connect", function () {
  console.log("MQTT Connecetde");
});

client.on("message", function (topic, msg) {
  // console.log(topic, " : ", msg.toString());
  console.log("MQTT\t", topic /* , "\t", msg.toString()*/);
});

client.on("connect", function () {
  console.log("connected  " + client.connected);
});

//handle errors
client.on("error", function (error) {
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

app.get("/", (req, res) => {
  res.sendFile(__dirname + "/index.html");
});

app.get("/xterm.js", (req, res) => {
  res.sendFile(__dirname + "/node_modules/xterm/lib/xterm.js");
});

app.get("/xterm.css", (req, res) => {
  res.sendFile(__dirname + "/node_modules/xterm/css/xterm.css");
});
server.listen(3000, () => {
  console.log("listening on *:3000");
});

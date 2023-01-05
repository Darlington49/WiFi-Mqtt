const mqtt = require("mqtt");
const client = mqtt.connect("mqtt://test.mosquitto.org");

// const express = require("express");
// const app = express();
// const port = process.env.PORT;

// app.use(express.static("public"));
// app.use("/static", express.static("public"));

// // app.get("/", (req, res) => {
// //   res.send("Hello World!");
// // });
// // sendFile will go here
// app.get("/", function (req, res) {
//   res.sendFile(path.join(__dirname, "/index.html"));
// });
// app.get("/payloads", function (req, res) {

//   Payload.find({}).then(function (payloads) {
//     res.send(payloads);
//   });
// });
// app.listen(port, () => {
//   console.log(`Example app listening on port ${port}`);
// });

// const mongoose = require("mongoose");
// const { Payload } = require("./Payload");
// const connect = mongoose
//   // .connect(mongoURI, {
//   .connect(process.env.mongoURI, {
//     // useNewUrlParser: true,
//     // useUnifiedTopology: true,
//     // useCreateIndex: true,
//     // useFindAndModify: false,
//   })
//   .then(() => console.log("MongoDB Connected..."))
//   .catch((err) => console.log(err));

//publish
function publish(topic, msg, options) {
  console.log("publishing", msg);

  if (client.connected == true) {
    client.publish(topic, msg, options);
  }
  count += 1;
}

client.on("connect", function () {
  //   client.subscribe("presence", function (err) {
  //     if (!err) {
  //       client.publish("presence", "Hello mqtt");
  //     }
  //   });
});

client.on("message", function (topic, msg) {
  // msg is Buffer
  // console.log("\t\tmessage : " + msg.toString());
  // console.log("\t\ttopic  : " + topic);
  console.log(topic, " : ", msg.toString());
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
var gpstopic = "DZ00889654/#";

console.log("subscribing to topics");
client.subscribe(gpstopic, { qos: 1 }); //single topic

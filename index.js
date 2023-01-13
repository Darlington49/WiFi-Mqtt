<!-- <!DOCTYPE html>
<html>
 <head>
   <title>Socket.IO chat</title>
   <style>
     body { margin: 0; padding-bottom: 3rem; font-family: -apple-system, BlinkMacSystemFont, "Segoe UI", Roboto, Helvetica, Arial, sans-serif; }

     #messages { list-style-type: none; margin: 0; padding: 0; }
     #messages > li { padding: 0.5rem 1rem; }
     #messages > li:nth-child(odd) { background: #efefef; }
   </style>
 </head>
 <body>
<h1>Hello </h1> 
   <script src="https://cdn.socket.io/4.5.4/socket.io.min.js"></script>
   <script>
     console.log("start Script");
       var socket = io();
       var messages = document.getElementById('messages');

       socket.on('data', function(msg) {
         console.log('data:\t',msg);
       });

          socket.on('log', function(msg) {
         console.log('log:\t',msg);
       });

     
   </script>
</body>
</html> -->

<!DOCTYPE html>
<html>
  <head>
    <title>Socket.IO chat</title>
    <style>
      body {
        margin: 0;
        padding-bottom: 3rem;
        font-family: -apple-system, BlinkMacSystemFont, "Segoe UI", Roboto,
          Helvetica, Arial, sans-serif;
        background:black;
      }


      #messages {
        list-style-type: none;
        margin: 0;
        padding: 0;
        color:white
      }
/*       #messages > li {
        padding: 0.5rem 1rem;
      } */

    </style>
  </head>
  <body>
    <ul id="messages"></ul>

    <script src="https://cdn.socket.io/4.5.4/socket.io.min.js"></script>
    <script>
      console.log("start Script");
      var socket = io();
      var form = document.getElementById("form");

      socket.on("data", function (msg) {
        console.log("data:\t", msg);
        var item = document.createElement("li");
        item.textContent = `Topic:\t${msg.topic}\tData:${msg.data}\tDevice:${msg.deviceID}`;
        messages.appendChild(item);
        window.scrollTo(0, document.body.scrollHeight);
      });

      socket.on("log", function (msg) {
        console.log("log:\t", msg);
        var item = document.createElement("li");
        item.textContent = `Topic:\t${msg.topic}\tData:${msg.data}\tDevice:${msg.deviceID}`;
        messages.appendChild(item);
        window.scrollTo(0, document.body.scrollHeight);
      });
    </script>
  </body>
</html>

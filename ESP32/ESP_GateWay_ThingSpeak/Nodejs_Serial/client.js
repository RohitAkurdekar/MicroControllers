const axios = require('axios')

const {esp, myJsonData} = require('./esp32')

myVal = ['0','1']

myHumid=0

const URL="https://api.thingspeak.com/update.json"


const REQUEST_BODY = {
    api_key: "YourAPIkey",
    field1: myHumid
}


esp.on("sensorValue",(err,value)=>{
    // console.log(value.toString('utf-8'));
    // console.log(".")
    if(err){
        console.log(err);
        return;
    }
    // {data : 45 } 

    abc = value.toString('utf-8')

    myArr = (abc.split(":"))

    try{

        myVal = myArr[1].split("}")
        console.log()
    }
    catch(error)
    {

    }

    // myVal = myArr[1]

    myHumid = parseInt(myVal[0])

    REQUEST_BODY.field1 = myHumid



    console.log("val: ",REQUEST_BODY.field1)


// Make a GET request to Server
axios.post(URL /*HOST + PORT + PATH*/, REQUEST_BODY)
    .then((response)=>{
        const RESPONSE_BODY  = JSON.stringify(response.data, null,2);
        console.log("Data: "+RESPONSE_BODY+". Response Code: "+ response.status)
    }).catch(error=>{
        console.log(error);
    })

    // myHumid = value
    // console.log("myJson: ",myJsonData)
})

// TODO Write HTTP or CoAP or Websocket clients to exchange the data
// Example send it to ThingSpeak or Dweet platforms


// ---------------------------------------------------------------------------


// Program to make a simple GET request and parse the Response Body
// const HOST = "https://api.thingspeak.com:";
// const PORT = "443"
// const PATH = "/update.json"


// console.log("myJson: ",myJsonData)
//6YXQKBOP80VVCRUU
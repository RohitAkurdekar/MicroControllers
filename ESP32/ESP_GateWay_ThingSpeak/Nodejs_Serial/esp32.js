/*----------------------------------------------
 * Description: A program to open a serial port and receive the data. 
   JSON data format is expected
 * ---------------------------------------*/
const serialport = require('serialport');
const events = require("events");

const esp = new events();

myJsonData = {"humid":32.15}

// Define the port path and baudrate here
const portESP = new serialport.SerialPort({
    path: "/dev/ttyUSB1",
    baudRate: 115200
})

portESP.on('open',()=>{
    console.log("Port opened!")
})

// Handle the data on Port; JSON parser used
portESP.on('data',(data) => {
    // console.log(data.toString('utf-8'))
    this.myJsonData = data.toString('utf-8')
    esp.emit("sensorValue",null,this.myJsonData.toString());
    // data = JSON.parse(data.toString('utf-8'))
    // esp.emit("sensorValue",null,data.toString());

    // console.log("data: ",data)

    /** 
    try{
        // data = "{\"Humid\":32.56}"

        // console.log("myDAtatry:",data)

        myJsonData = JSON.parse(data.toString('utf-8'))
        data = JSON.parse(data.toString('utf-8'))

        console.log("data: ",this.myJsonData)

        esp.emit("sensorValue",null,data);
    } catch(error){
        console.log("myDAta:",data.toString('utf-8'))
        // esp.emit("sensorValue",{message: "JSON parsing error"},null)
    }/**/
})

// Send the data on serial port; String as parameter
const sendData = (data)=>{
    portESP.write(Buffer.from(data))
}

module.exports = {
    esp,
    sendData,
    myJsonData
}

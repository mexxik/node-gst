var module = require('./build/Release/streamer');

var streamer = new module.Streamer();
streamer.init();

var pipeline = new module.Pipeline();
pipeline.parseLaunch("url");
pipeline.start();

//console.log('GST version: ' + streamer.getVersion());
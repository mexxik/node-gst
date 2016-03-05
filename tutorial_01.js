var module = require('./build/Release/streamer');

var streamer = new module.Streamer();
streamer.init();

console.log('starting');

var pipeline = new module.Pipeline();
pipeline.parseLaunch("playbin uri=http://docs.gstreamer.com/media/sintel_trailer-480p.webm");
pipeline.start();

//console.log('GST version: ' + streamer.getVersion());
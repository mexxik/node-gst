var gst      = require('./../../index');

var streamer = gst.createStreamer();
streamer.init();

console.log('starting tutorial 01 - Hello World!');

var pipeline = gst.createPipeline();
var bus = gst.createBus(pipeline);

//bus.watch();

pipeline.on('eos', function() {
    console.log('end of stream');
});

pipeline.parseLaunch("playbin uri=http://docs.gstreamer.com/media/sintel_trailer-480p.webm");
pipeline.start();

var gst      = require('./../../index');

var streamer = gst.createStreamer();
streamer.init();

console.log('starting');

var pipeline = gst.createPipeline();

pipeline.on('eos', function() {
    console.log('end of stream');
});

pipeline.parseLaunch("playbin uri=http://docs.gstreamer.com/media/sintel_trailer-480p.webm");
pipeline.start();

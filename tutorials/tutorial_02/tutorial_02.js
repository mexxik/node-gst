var gst      = require('./../../index');

var streamer = gst.createStreamer();
streamer.init();

console.log('starting tutorial 02 - GStreamer concepts!');

var pipeline = gst.createPipeline();
//pipeline.new('test-pipeline');

var source = gst.createElement('videotestsrc', 'video_source');
var sink = gst.createElement('autovideosink', 'video_sink');

pipeline.add(source);
pipeline.add(sink);
streamer.link(source, sink);

pipeline.start();

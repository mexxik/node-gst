var module = require('./build/Release/streamer');

var streamer = new module.Streamer();
//var element = new module.Element();
var pipeline = streamer.createPipeline('test-pipeline');

console.log('GST version: ' + streamer.getVersion());

//console.log(module.hello());
var events  = require('events');
var util    = require('util');

var s       = require('./build/Release/streamer');

module.exports = {
    createStreamer: function() {
        var streamer = new s.Streamer();
        inherits(streamer, events.EventEmitter);
        return streamer;
    },
    createPipeline: function() {
        var pipeline = new s.Pipeline();
        inherits(pipeline, events.EventEmitter);
        return pipeline;
    }
};

function inherits(target, source) {
    for (var p in source.prototype) {
        target.__proto__[p] = source.prototype[p];
    }
}



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
    },
    createElement: function(type, name) {
        var element = new s.Element(type, name);
        inherits(element, events.EventEmitter);
        return element;
    }
};

function inherits(target, source) {
    for (var p in source.prototype) {
        target.__proto__[p] = source.prototype[p];
    }
}



var EventEmitter = require('events').EventEmitter;


var s = require('./build/Release/streamer');

module.exports = {
    createStreamer: function() {
        var streamer = new s.Streamer();
        inherits(streamer, EventEmitter);
        return streamer;
    },
    createPipeline: function() {
        var pipeline = new s.Pipeline();
        inherits(pipeline, EventEmitter);
        return pipeline;
    },
    createElement: function(type, name) {
        var element = new s.Element(type, name);
        inherits(element, EventEmitter);
        return element;
    },
    createBus: function(pipeline) {
        var bus = new s.Bus(pipeline);
        inherits(bus, EventEmitter);
        return bus;
    }
};

function inherits(target, source) {
    for (var p in source.prototype) {
        target.__proto__[p] = source.prototype[p];
    }
}



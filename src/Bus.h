#ifndef NODE_GST_BUS_H
#define NODE_GST_BUS_H

#include <node.h>
#include <node_object_wrap.h>

#include <gst/gst.h>

#include "Pipeline.h"
#include "Element.h"

class Bus : public Element {
public:

    static v8::Persistent<v8::Function> constructor;
    static void Initialize(v8::Local<v8::Object> exports);

    static void New(const v8::FunctionCallbackInfo<v8::Value>& info);
    static void Watch(const v8::FunctionCallbackInfo<v8::Value>& info);

    static gboolean BusCallback(GstBus *bus, GstMessage *message, gpointer data);

    inline GstBus *gstBus() { return _gstBus; }
    inline void gstBus(GstBus *value) { _gstBus = value; }

    inline guint watchId() { return _watchId; }
    inline void watchId(guint value) { _watchId = value; }

private:
    GstBus *_gstBus;
    guint _watchId;
    GMainLoop *loop;

    Bus();
    ~Bus();


};

class WatchHelper {
public:
    Bus *bus;
};


#endif // NODE_GST_BUS_H


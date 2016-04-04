#include "Bus.h"

using namespace v8;

Persistent<Function> Bus::constructor;

Bus::Bus() {

}

Bus::~Bus() {

}

void Bus::Initialize(Local<Object> exports) {
    Isolate* isolate = exports->GetIsolate();

    Local<FunctionTemplate> tpl = FunctionTemplate::New(isolate, New);
    tpl->InstanceTemplate()->SetInternalFieldCount(1);
    tpl->SetClassName(String::NewFromUtf8(isolate, "Bus"));

    NODE_SET_PROTOTYPE_METHOD(tpl, "watch", Watch);

    constructor.Reset(isolate, tpl->GetFunction());
    exports->Set(String::NewFromUtf8(isolate, "Bus"), tpl->GetFunction());
}

void Bus::New(const FunctionCallbackInfo<Value>& info) {
    Bus *bus = ObjectWrap::Unwrap<Bus>(info.This());

    if (info.Length() > 0) {
        Pipeline *pipeline = ObjectWrap::Unwrap<Pipeline>(info[0]->ToObject());
        GstBus *gstBus = gst_pipeline_get_bus(GST_PIPELINE(pipeline->gstElement()));
        //bus->gstBus(gstBus);
    }

    info.GetReturnValue().Set(info.This());
}

void Bus::Watch(const FunctionCallbackInfo<Value>& info) {
    //Bus *bus = ObjectWrap::Unwrap<Bus>(info.This());

    /*WatchHelper *watchHelper = new WatchHelper();
    watchHelper->bus = bus;

    guint watchId = gst_bus_add_watch(bus->gstBus(), bus->BusCallback, (void*)watchHelper);
    bus->watchId(watchId);*/
}
/*gboolean BusCallback(GstBus *bus, GstMessage *message, gpointer data) {


    return TRUE;
}*/
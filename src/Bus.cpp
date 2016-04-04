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
        bus->gstBus(gstBus);
    }

    info.GetReturnValue().Set(info.This());
}

void Bus::Watch(const FunctionCallbackInfo<Value>& info) {
    //g_print("watching\n");

    Isolate *isolate = info.GetIsolate();

    Bus *bus = ObjectWrap::Unwrap<Bus>(info.This());
    GstBus *gstBus = bus->gstBus();

    GstMessage *msg;
    gboolean terminate = FALSE;

    do {
        msg = gst_bus_timed_pop_filtered(gstBus, GST_CLOCK_TIME_NONE,
                                         GstMessageType(GST_MESSAGE_STATE_CHANGED | GST_MESSAGE_ERROR | GST_MESSAGE_EOS));

        switch (GST_MESSAGE_TYPE(msg)) {
            case GST_MESSAGE_STATE_CHANGED:
                g_print("state changed\n");

                /*bus->Emit(info,
                          String::NewFromUtf8(isolate, "stateChanged"),
                          String::NewFromUtf8(isolate, "data"));
*/
                break;

        }
    } while(!terminate);

    /*WatchHelper *watchHelper = new WatchHelper();
    watchHelper->bus = bus;

    guint watchId = gst_bus_add_watch(bus->gstBus(), bus->BusCallback, (void*)watchHelper);
    bus->watchId(watchId);*/
}
/*gboolean BusCallback(GstBus *bus, GstMessage *message, gpointer data) {


    return TRUE;
}*/
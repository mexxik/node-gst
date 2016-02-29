//
// Created by Max Golovanchuk on 1/28/16.
//

#include "Pipeline.h"

using namespace v8;

Nan::Persistent<FunctionTemplate> Pipeline::constructor;

Pipeline::Pipeline() {

}

Pipeline::~Pipeline() {

}

void Pipeline::Initialize(Nan::ADDON_REGISTER_FUNCTION_ARGS_TYPE target) {
    Nan::HandleScope scope;

    Local<FunctionTemplate> ctor = Nan::New<FunctionTemplate>(Pipeline::New);
    constructor.Reset(ctor);
    ctor->InstanceTemplate()->SetInternalFieldCount(1);
    ctor->SetClassName(Nan::New("Pipeline").ToLocalChecked());

    //Local<ObjectTemplate> proto = ctor->PrototypeTemplate();
    Nan::SetPrototypeMethod(ctor, "parseLaunch", ParseLaunch);
    Nan::SetPrototypeMethod(ctor, "start", Start);
    Nan::SetPrototypeMethod(ctor, "play", Play);

    Nan::Set(target, Nan::New("Pipeline").ToLocalChecked(), ctor->GetFunction());
}

NAN_METHOD(Pipeline::ParseLaunch) {
    if (info[0]->IsString()) {
        String::Utf8Value url(info[0]);
        GstElement *gstPipeline = gst_parse_launch("playbin uri=http://docs.gstreamer.com/media/sintel_trailer-480p.webm", NULL);

        Pipeline *pipeline = Nan::ObjectWrap::Unwrap<Pipeline>(info.This());
        pipeline->gstElement(gstPipeline);
        //pipeline->_gstPipeline = gstPipeline;

        info.GetReturnValue().Set(info.This());
    }
}

NAN_METHOD(Pipeline::Start) {
    Pipeline *pipeline = Nan::ObjectWrap::Unwrap<Pipeline>(info.This());
    pipeline->Play(info);

    GstBus *bus = gst_element_get_bus(pipeline->gstElement());

    //GstMessage *msg = gst_bus_timed_pop_filtered(bus, GST_CLOCK_TIME_NONE, GST_MESSAGE_EOS);
}
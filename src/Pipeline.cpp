#include "Pipeline.h"

using namespace v8;

Persistent<Function> Pipeline::constructor;

Pipeline::Pipeline() {

}

Pipeline::~Pipeline() {

}

void Pipeline::Initialize(Local<Object> exports) {
    Isolate* isolate = exports->GetIsolate();

    Local<FunctionTemplate> tpl = FunctionTemplate::New(isolate, New);
    tpl->InstanceTemplate()->SetInternalFieldCount(1);
    tpl->SetClassName(String::NewFromUtf8(isolate, "Pipeline"));

    //Local<ObjectTemplate> proto = ctor->PrototypeTemplate();
    //Nan::SetPrototypeMethod(ctor, "parseLaunch", ParseLaunch);
    //Nan::SetPrototypeMethod(ctor, "start", Start);
    //Nan::SetPrototypeMethod(ctor, "play", Play);

    NODE_SET_PROTOTYPE_METHOD(tpl, "start", Start);
    NODE_SET_PROTOTYPE_METHOD(tpl, "new", New);
    NODE_SET_PROTOTYPE_METHOD(tpl, "parseLaunch", ParseLaunch);
    NODE_SET_PROTOTYPE_METHOD(tpl, "add", Add);

    //Nan::Set(target, Nan::New("Pipeline").ToLocalChecked(), ctor->GetFunction());
    constructor.Reset(isolate, tpl->GetFunction());
    exports->Set(String::NewFromUtf8(isolate, "Pipeline"), tpl->GetFunction());
}

void Pipeline::New(const FunctionCallbackInfo<Value>& info) {
    Pipeline* pipeline = ObjectWrap::Unwrap<Pipeline>(info.This());
    GstElement* gstElement;
    if (info[0]->IsString()) {
        String::Utf8Value name(info[0]->ToString());
        gstElement = gst_pipeline_new(*name);
    }
    else {
        gstElement = gst_pipeline_new(NULL);
    }

    pipeline->gstElement(gstElement);
}

void Pipeline::ParseLaunch(const FunctionCallbackInfo<Value>& info) {
    if (info[0]->IsString()) {


        String::Utf8Value command(info[0]->ToString());
        //std::string prefix("playbin uri=");
        //std::string uri(*arg);

        //std::string command = prefix + uri;
        std::cout << *command << std::endl;
        GstElement *gstPipeline = gst_parse_launch(*command, NULL);

        Pipeline *pipeline = ObjectWrap::Unwrap<Pipeline>(info.This());
        pipeline->gstElement(gstPipeline);
        //pipeline->_gstPipeline = gstPipeline;

        info.GetReturnValue().Set(info.This());
    }
}

void Pipeline::Start(const FunctionCallbackInfo<Value>& info) {
    //Isolate *isolate = info.GetIsolate();


    Pipeline *pipeline = ObjectWrap::Unwrap<Pipeline>(info.This());

    pipeline->Play(info);

    //GstBus *bus = gst_element_get_bus(pipeline->gstElement());



    //GstMessage *msg = gst_bus_timed_pop_filtered(bus, GST_CLOCK_TIME_NONE, GST_MESSAGE_EOS);
/*
    if(msg != NULL) {
        //GError *err;
        //gchar *debugInfo;

        switch(GST_MESSAGE_TYPE(msg)) {
            case GST_MESSAGE_ERROR:
                std::cout << "error" << std::endl;
                break;

            case GST_MESSAGE_EOS:
                std::cout << "eos" << std::endl;

                //pipeline->Emit(info, String::NewFromUtf8(isolate, "eos"));
                break;
        }
    }*/
}

void Pipeline::Add(const FunctionCallbackInfo<Value>& info) {
    Pipeline* pipeline = ObjectWrap::Unwrap<Pipeline>(info.This());
    Element* element = ObjectWrap::Unwrap<Element>(info[0]->ToObject());

    gst_bin_add(GST_BIN(pipeline->gstElement()), element->gstElement());
}
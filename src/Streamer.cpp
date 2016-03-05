//
// Created by Max Golovanchuk on 1/7/16.
//

#include "Streamer.h"

using namespace v8;
using namespace std;

Persistent<Function> Streamer::constructor;

Streamer::Streamer() {

}

Streamer::~Streamer() {

}

void Streamer::Initialize(v8::Local<v8::Object> exports) {
    Isolate* isolate = exports->GetIsolate();

    Local<FunctionTemplate> tpl = FunctionTemplate::New(isolate, New);
    tpl->InstanceTemplate()->SetInternalFieldCount(1);
    tpl->SetClassName(String::NewFromUtf8(isolate, "Streamer"));


    NODE_SET_PROTOTYPE_METHOD(tpl, "init", Init);

    //Nan::Set(target, Nan::New("Pipeline").ToLocalChecked(), ctor->GetFunction());
    constructor.Reset(isolate, tpl->GetFunction());
    exports->Set(String::NewFromUtf8(isolate, "Streamer"), tpl->GetFunction());
}

void Streamer::New(const FunctionCallbackInfo<Value>& info) {
    Streamer* streamer = new Streamer();
    streamer->Wrap(info.This());
    info.GetReturnValue().Set(info.This());
}

void Streamer::Init(const FunctionCallbackInfo<Value>& info) {
    guint _majorVersion;
    guint _minorVersion;
    guint _microVersion;
    guint _nanoVersion;

    gst_init(NULL, NULL);

    gst_version (&_majorVersion, &_minorVersion, &_microVersion, &_nanoVersion);
}

/*void Streamer::GetVersion(const FunctionCallbackInfo<Value> &args) {
    Isolate* isolate = args.GetIsolate();

    Streamer* streamer = ObjectWrap::Unwrap<Streamer>(args.Holder());

    string major = to_string(streamer->_majorVersion);
    string minor = to_string(streamer->_minorVersion);
    string micro = to_string(streamer->_microVersion);
    string version = major + "." + minor + "." + micro;
    args.GetReturnValue().Set(String::NewFromUtf8(isolate, version.c_str()));
}*/

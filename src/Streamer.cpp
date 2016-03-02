//
// Created by Max Golovanchuk on 1/7/16.
//

#include "Streamer.h"

using namespace v8;
using namespace std;

Nan::Persistent<FunctionTemplate> Streamer::constructor;

Streamer::Streamer() {

}

Streamer::~Streamer() {

}

void Streamer::Initialize(Nan::ADDON_REGISTER_FUNCTION_ARGS_TYPE target) {
    Nan::HandleScope scope;

    Local<FunctionTemplate> ctor = Nan::New<FunctionTemplate>(Pipeline::New);
    constructor.Reset(ctor);
    ctor->InstanceTemplate()->SetInternalFieldCount(1);
    ctor->SetClassName(Nan::New("Streamer").ToLocalChecked());

    //Local<ObjectTemplate> proto = ctor->PrototypeTemplate();
    Nan::SetPrototypeMethod(ctor, "init", Init);

    Nan::Set(target, Nan::New("Streamer").ToLocalChecked(), ctor->GetFunction());
}

NAN_METHOD(Streamer::New) {
    Streamer* streamer = new Streamer();
    streamer->Wrap(info.This());
    info.GetReturnValue().Set(info.This());
}

NAN_METHOD(Streamer::Init) {
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

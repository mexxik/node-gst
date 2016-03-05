//
// Created by Max Golovanchuk on 1/7/16.
//

#ifndef MLG_STREAMER_STREAMER_H
#define MLG_STREAMER_STREAMER_H

#include <string>

#include <node.h>
#include <node_object_wrap.h>

extern "C" {
    #include <gst/gst.h>
}

#include "Element.h"
#include "Pipeline.h"

#include <nan.h>

class Streamer : public Nan::ObjectWrap {
public:
    //static void Init(v8::Handle<v8::Object> target);
    static v8::Persistent<v8::Function> constructor;
    static void Initialize(v8::Local<v8::Object> exports);
    static void New(const v8::FunctionCallbackInfo<v8::Value>& info);
    //static NAN_METHOD(New);

    static void Init(const v8::FunctionCallbackInfo<v8::Value>& info);
    //static NAN_METHOD(Init);

    inline guint majorVersion() { return _majorVersion; }
    inline void majorVersion(guint value) {_majorVersion = value; }

private:
    //static v8::Persistent<v8::Function> constructor;

    Streamer();
    ~Streamer();

    //static void GetVersion(const v8::FunctionCallbackInfo<v8::Value>& args);
    //static void CreatePipeline(const v8::FunctionCallbackInfo<v8::Value>& args);
    //static void CreateElement(const v8::FunctionCallbackInfo<v8::Value>& args);

    guint _majorVersion;
    guint _minorVersion;
    guint _microVersion;
    guint _nanoVersion;
};


#endif //MLG_STREAMER_STREAMER_H

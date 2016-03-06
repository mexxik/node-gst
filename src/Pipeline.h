//
// Created by Max Golovanchuk on 1/28/16.
//

#ifndef MLG_STREAMER_PIPELINE_H
#define MLG_STREAMER_PIPELINE_H

#include <string>
#include <iostream>

#include <node.h>
#include <node_object_wrap.h>

#include <nan.h>

#include <gst/gst.h>

#include "Element.h"

class Pipeline : public Element{
public:

    static v8::Persistent<v8::Function> constructor;
    static void Initialize(v8::Local<v8::Object> exports);
    //static NAN_METHOD(New);
    //static NAN_METHOD(ParseLaunch);
    //static NAN_METHOD(Start);
    static void New(const v8::FunctionCallbackInfo<v8::Value>& info);
    static void ParseLaunch(const v8::FunctionCallbackInfo<v8::Value>& info);
    static void Start(const v8::FunctionCallbackInfo<v8::Value>& info);
    static void Add(const v8::FunctionCallbackInfo<v8::Value>& info);

    //static NAN_METHOD(Play);

    //inline GstElement *gstPipeline() { return _gstPipeline; }
    //inline void gstPipeline(GstElement *value) { _gstPipeline = value; }

    //GstElement *_gstPipeline;
private:

    Pipeline();
    ~Pipeline();

    //GstElement *_gstPipeline;
};


#endif //MLG_STREAMER_PIPELINE_H

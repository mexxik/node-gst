#ifndef NODE_GST_PIPELINE_H
#define NODE_GST_PIPELINE_H

#include <string>
#include <iostream>

#include <node.h>
#include <node_object_wrap.h>

#include <gst/gst.h>

#include "Element.h"

class Pipeline : public Element{
public:

    static v8::Persistent<v8::Function> constructor;
    static void Initialize(v8::Local<v8::Object> exports);

    static void New(const v8::FunctionCallbackInfo<v8::Value>& info);
    static void ParseLaunch(const v8::FunctionCallbackInfo<v8::Value>& info);
    static void Start(const v8::FunctionCallbackInfo<v8::Value>& info);
    static void Add(const v8::FunctionCallbackInfo<v8::Value>& info);

private:

    Pipeline();
    ~Pipeline();
};


#endif // NODE_GST_PIPELINE_H

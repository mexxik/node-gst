//
// Created by Max Golovanchuk on 1/8/16.
//

#ifndef MLG_STREAMER_ELEMENT_H
#define MLG_STREAMER_ELEMENT_H

#include <node.h>
#include <node_object_wrap.h>

#include <gst/gst.h>


class Element : public node::ObjectWrap {
public:

    static v8::Persistent<v8::Function> constructor;
    static void Initialize(v8::Local<v8::Object> exports);
    //static NAN_METHOD(New);
    static void New(const v8::FunctionCallbackInfo<v8::Value>& info);

    //static NAN_METHOD(Play);
    static void Play(const v8::FunctionCallbackInfo<v8::Value>& info);

    inline GstElement *gstElement() { return _gstElement; }
    inline void gstElement(GstElement *value) { _gstElement = value; }


protected:
    Element();
    ~Element();

    void Emit(const v8::FunctionCallbackInfo<v8::Value>& info, v8::Local<v8::String> name);

    GstElement *_gstElement;
};


#endif //MLG_STREAMER_ELEMENT_H

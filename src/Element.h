//
// Created by Max Golovanchuk on 1/8/16.
//

#ifndef MLG_STREAMER_ELEMENT_H
#define MLG_STREAMER_ELEMENT_H

#include <node.h>
#include <node_object_wrap.h>

#include <nan.h>

#include <gst/gst.h>

class Element : public Nan::ObjectWrap{
public:

    static Nan::Persistent<v8::FunctionTemplate> constructor;
    static void Initialize(Nan::ADDON_REGISTER_FUNCTION_ARGS_TYPE target);
    static NAN_METHOD(New);

    static NAN_METHOD(Play);

    inline GstElement *gstElement() { return _gstElement; }
    inline void gstElement(GstElement *value) { _gstElement = value; }


protected:
    Element();
    ~Element();

    GstElement *_gstElement;
};


#endif //MLG_STREAMER_ELEMENT_H

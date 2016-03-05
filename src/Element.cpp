//
// Created by Max Golovanchuk on 1/8/16.
//

#include "Element.h"

using namespace v8;

Persistent<Function> Element::constructor;

Element::Element() {

}

Element::~Element() {
    gst_object_unref(_gstElement);
}

void Element::Initialize(Local<Object> exports) {
    //Nan::HandleScope scope;
    Isolate* isolate = exports->GetIsolate();

    Local<FunctionTemplate> tpl = FunctionTemplate::New(isolate, New);
    tpl->InstanceTemplate()->SetInternalFieldCount(1);
    tpl->SetClassName(String::NewFromUtf8(isolate, "Element"));

    //Local<ObjectTemplate> proto = ctor->PrototypeTemplate();
    //Nan::SetPrototypeMethod(ctor, "play", Play);
    NODE_SET_PROTOTYPE_METHOD(tpl, "play", Play);

    //Nan::Set(target, Nan::New("Element").ToLocalChecked(), ctor->GetFunction());
    constructor.Reset(isolate, tpl->GetFunction());
    exports->Set(String::NewFromUtf8(isolate, "Element"), tpl->GetFunction());
}

void Element::New(const FunctionCallbackInfo<Value>& info) {
    Element* element = new Element();
    element->Wrap(info.This());
    info.GetReturnValue().Set(info.This());
}

//NAN_METHOD(Element::Play) {
void Element::Play(const FunctionCallbackInfo<Value>& info) {
    Element *element = Nan::ObjectWrap::Unwrap<Element>(info.This());

    gst_element_set_state(element->gstElement(), GST_STATE_PLAYING);

    info.GetReturnValue().Set(info.This());
}

void Element::Emit(const FunctionCallbackInfo<Value>& info, Local<String> name) {
    Handle<Value> params[] = {
        name
    };

    Nan::MakeCallback(info.This(), "emit", 1, params);
}

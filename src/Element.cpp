//
// Created by Max Golovanchuk on 1/8/16.
//

#include "Element.h"

using namespace v8;

Nan::Persistent<FunctionTemplate> Element::constructor;

Element::Element() {

}

Element::~Element() {
    gst_object_unref(_gstElement);
}

void Element::Initialize(Nan::ADDON_REGISTER_FUNCTION_ARGS_TYPE target) {
    Nan::HandleScope scope;

    Local<FunctionTemplate> ctor = Nan::New<FunctionTemplate>(Element::New);
    constructor.Reset(ctor);
    ctor->InstanceTemplate()->SetInternalFieldCount(1);
    ctor->SetClassName(Nan::New("Element").ToLocalChecked());

    //Local<ObjectTemplate> proto = ctor->PrototypeTemplate();
    Nan::SetPrototypeMethod(ctor, "play", Play);

    Nan::Set(target, Nan::New("Element").ToLocalChecked(), ctor->GetFunction());
}

NAN_METHOD(Element::New) {
    Element* element = new Element();
    element->Wrap(info.This());
    info.GetReturnValue().Set(info.This());
}

NAN_METHOD(Element::Play) {
    Element *element = Nan::ObjectWrap::Unwrap<Element>(info.This());

    gst_element_set_state(element->gstElement(), GST_STATE_PLAYING);

    info.GetReturnValue().Set(info.This());
}

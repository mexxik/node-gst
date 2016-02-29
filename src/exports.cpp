//
// Created by Max Golovanchuk on 1/7/16.
//

#include <node.h>

#include "Streamer.h"
#include "Element.h"
#include "Pipeline.h"

using namespace v8;

NAN_MODULE_INIT(init) {
    Streamer::Initialize(target);
    Element::Initialize(target);
    Pipeline::Initialize(target);
}

/*void InitAll(Local<Object> exports) {
    Streamer::Init(exports);
    Element::Init(exports);
}*/

/*void Method(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();
    args.GetReturnValue().Set(String::NewFromUtf8(isolate, "world"));
}

void init(Local<Object> exports) {
    NODE_SET_METHOD(exports, "hello", Method);
}*/

//NODE_MODULE(addon, init)

NODE_MODULE(streamer, init)
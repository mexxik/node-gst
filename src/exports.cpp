//
// Created by Max Golovanchuk on 1/7/16.
//

#include <node.h>

#include "Streamer.h"
#include "Element.h"
#include "Pipeline.h"
#include "Bus.h"

using namespace v8;

void InitAll(Local<Object> exports) {
    Streamer::Initialize(exports);
    Element::Initialize(exports);
    Pipeline::Initialize(exports);
    Bus::Initialize(exports);
}

NODE_MODULE(streamer, InitAll)


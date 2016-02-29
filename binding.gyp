{
  "targets": [
    {
      "target_name": "streamer",
      "sources": [
        "src/exports.cpp",
        "src/Streamer.cpp",
        "src/Element.cpp",
        "src/Pipeline.cpp"
      ],
      "cflags" : [ "-std=c++1", "-stdlib=libc++" ],
      "conditions": [
        [ "OS!='win'", {
          "cflags+": [ "-std=c++11" ],
          "cflags_c+": [ "-std=c++11" ],
          "cflags_cc+": [ "-std=c++11" ]
        }],
        [ "OS=='mac'", {
          "xcode_settings": {
            "OTHER_CPLUSPLUSFLAGS" : [ "-std=c++11", "-stdlib=libc++" ],
            "OTHER_LDFLAGS": [ "-stdlib=libc++" ],
            "MACOSX_DEPLOYMENT_TARGET": "10.7"
          }
        }]
      ],
      "link_settings": {
        "libraries": [
          "libgstreamer-1.0.a"
        ],
        "ldflags": [
          "-Wl,-rpath,/Library/Frameworks/GStreamer.framework/Versions/1.0/lib"
        ]
      },
      "include_dirs": [
        "/Library/Frameworks/GStreamer.framework/Headers",
        "<!(node -e \"require('nan')\")"
      ],
      "library_dirs": [
        "/Library/Frameworks/GStreamer.framework/Versions/1.0/lib"
      ]
    }
  ]
}

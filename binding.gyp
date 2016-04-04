{
  "targets": [
    {
      "target_name": "streamer",
      "sources": [
        "src/exports.cpp",
        "src/Streamer.cpp",
        "src/Element.cpp",
        "src/Pipeline.cpp",
        "src/Bus.cpp"
      ],

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
          },
          "include_dirs": [
            "/Library/Frameworks/GStreamer.framework/Headers"
          ],
          "library_dirs": [
            "/Library/Frameworks/GStreamer.framework/Versions/1.0/lib"
          ],
          "link_settings": {
            "libraries": [
              "-lgstreamer-1.0"
            ],
            "ldflags": [
              "-Wl,-rpath,/Library/Frameworks/GStreamer.framework/Versions/1.0/lib"
            ]
          }
        }],
        [ "OS=='linux'", {
            "include_dirs": [
                "<!@(pkg-config gstreamer-1.0 --cflags-only-I | sed s/-I//g)"
              ],
              "libraries": [
                "<!@(pkg-config gstreamer-1.0 --libs)"
              ]
        }]
      ]
    }
  ]
}

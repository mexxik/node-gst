#include <stdio.h>
#include <gst/gst.h>


int
main(int    argc,
     char   *argv[])
{
    const gchar *nano_str;
    guint major, minor, micro, nano;

    gst_init (&argc, &argv);

    gst_version (&major, &minor, &micro, &nano);

    if (nano == 1)
        nano_str = "(CVS)";
    else if (nano == 2)
        nano_str = "(Prerelease)";
    else
        nano_str = "";

    printf ("GStreamer: %d.%d.%d %s\n",
           major, minor, micro, nano_str);




    GstElementFactory *factory;
    factory = gst_element_factory_find("fakesrc");
    if (!factory) {
        g_print("'fakesrc' factory is not found\n");
        return -1;
    }

    GstElement *element;
    //element = gst_element_factory_make("fakesrc", "source");
    element = gst_element_factory_create(factory, "source");
    if (!element) {
        g_print("failed to create element\n");
        return -1;
    }

    g_print("%s element\n", gst_plugin_feature_get_name(GST_PLUGIN_FEATURE(factory)));


    gchar *name;
    g_object_get(G_OBJECT(element), "name", &name, NULL);
    g_print("the name is '%s'\n", name);
    g_free(name);

    gst_object_unref(element);

    return 0;
}
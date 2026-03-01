#include <gst/gst.h>
#include "gst_helloplugin.h"

/* ---- REQUIRED when not using autotools ---- */
#ifndef PACKAGE
#define PACKAGE "helloplugin"
#endif

static gboolean
plugin_init(GstPlugin *plugin)
{
    return gst_element_register(
        plugin,
        "helloplugin",
        GST_RANK_NONE,
        GST_TYPE_HELLOPLUGIN
    );
}

GST_PLUGIN_DEFINE(
    GST_VERSION_MAJOR,
    GST_VERSION_MINOR,
    helloplugin,
    "Hello plugin",
    plugin_init,
    "1.0",
    "LGPL",
    "helloplugin",
    "https://github.com/HardSoftEngineer"
)
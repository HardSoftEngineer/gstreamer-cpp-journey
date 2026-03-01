#pragma once

#include <gst/video/gstvideofilter.h>

G_BEGIN_DECLS

#define GST_TYPE_HELLOPLUGIN (gst_helloplugin_get_type())
G_DECLARE_FINAL_TYPE(GstHelloPlugin, gst_helloplugin, GST, HELLOPLUGIN, GstVideoFilter)

struct _GstHelloPlugin
{
    GstVideoFilter parent;
    GstVideoInfo info;
};

G_END_DECLS

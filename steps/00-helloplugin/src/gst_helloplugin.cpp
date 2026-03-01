#include "gst_helloplugin.h"

GST_DEBUG_CATEGORY_STATIC(gst_helloplugin_debug);
#define GST_CAT_DEFAULT gst_helloplugin_debug

G_DEFINE_TYPE(GstHelloPlugin, gst_helloplugin, GST_TYPE_VIDEO_FILTER)

/* ---------- Pad templates ---------- */

static GstStaticPadTemplate sink_template =
GST_STATIC_PAD_TEMPLATE(
    "sink",
    GST_PAD_SINK,
    GST_PAD_ALWAYS,
    GST_STATIC_CAPS(
        "video/x-raw, "
        "format=RGBA, "
        "width=640, "
        "height=640"
    )
);

static GstStaticPadTemplate src_template =
GST_STATIC_PAD_TEMPLATE(
    "src",
    GST_PAD_SRC,
    GST_PAD_ALWAYS,
    GST_STATIC_CAPS(
        "video/x-raw, "
        "format=RGBA, "
        "width=640, "
        "height=640"
    )
);

/* ---------- set_info ---------- */

static gboolean
gst_helloplugin_set_info(GstVideoFilter *filter,
                        GstCaps *incaps,
                        GstVideoInfo *ininfo,
                        GstCaps *outcaps,
                        GstVideoInfo *outinfo)
{
    GstHelloPlugin *self = GST_HELLOPLUGIN(filter);
    self->info = *ininfo;
    return TRUE;
}

/* ---------- transform_frame_ip ---------- */

static GstFlowReturn
gst_helloplugin_transform_frame_ip(GstVideoFilter *filter,
                                  GstVideoFrame *frame)
{
    guint8 *data = static_cast<guint8 *>(GST_VIDEO_FRAME_PLANE_DATA(frame, 0));
    gint width = GST_VIDEO_FRAME_WIDTH(frame);
    gint height = GST_VIDEO_FRAME_HEIGHT(frame);
    gint stride = GST_VIDEO_FRAME_PLANE_STRIDE(frame, 0);

    // line
    int y = height / 2;
    for (int x = 0; x < width; ++x) {
        guint8 *pixel = data + y * stride + x * 4;

        pixel[0] = 255; // R
        pixel[1] = 0;   // G
        pixel[2] = 0;   // B
        pixel[3] = 255; // A
    }

    return GST_FLOW_OK;
}

/* ---------- class_init ---------- */

static void
gst_helloplugin_class_init(GstHelloPluginClass *klass)
{
    GstElementClass *element_class = GST_ELEMENT_CLASS(klass);
    GstVideoFilterClass *video_filter_class = GST_VIDEO_FILTER_CLASS(klass);

    gst_element_class_set_static_metadata(
        element_class,
        "Hello Plugin",
        "Filter/Effect/Video",
        "Draws simple red line overlay",
        "HardSoftEngineer"
    );

    gst_element_class_add_pad_template(
        element_class,
        gst_static_pad_template_get(&sink_template)
    );

    gst_element_class_add_pad_template(
        element_class,
        gst_static_pad_template_get(&src_template)
    );

    video_filter_class->set_info = gst_helloplugin_set_info;
    video_filter_class->transform_frame_ip = gst_helloplugin_transform_frame_ip;

    GST_DEBUG_CATEGORY_INIT(gst_helloplugin_debug,
                            "helloplugin",
                            0,
                            "HelloPlugin debug");
}

/* ---------- init ---------- */

static void
gst_helloplugin_init(GstHelloPlugin *self)
{
}

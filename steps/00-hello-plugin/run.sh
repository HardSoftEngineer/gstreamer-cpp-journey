#!/usr/bin/env bash

set -o pipefail

SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

cd "$SCRIPT_DIR"

export GST_PLUGIN_PATH="$SCRIPT_DIR/build"

# echo "test check helloplugin"
# gst-inspect-1.0 helloplugin

echo "run gst-launch-1.0 helloplugin"
gst-launch-1.0 videotestsrc ! \
video/x-raw,format=RGBA,width=640,height=640 ! \
helloplugin ! autovideosink

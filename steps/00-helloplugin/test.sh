#!/usr/bin/env bash

set -o pipefail

SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

cd "$SCRIPT_DIR"

export GST_PLUGIN_PATH="$SCRIPT_DIR/build"

echo "test gst-inspect helloplugin"
gst-inspect-1.0 helloplugin

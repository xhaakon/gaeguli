/**
 *  Copyright 2019 SK Telecom Co., Ltd.
 *    Author: Jeongseok Kim <jeongseok.kim@sk.com>
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 */

#ifndef __GAEGULI_INTERNAL_H__
#define __GAEGULI_INTERNAL_H__

#define HOSTINFO_JSON_FORMAT \
"{ \
   \"host\": \"%s\", \
   \"port\": %" G_GUINT32_FORMAT ", \
   \"mode\": %" G_GINT32_FORMAT " \
}"

#define GAEGULI_PIPELINE_VSRC_STR       "%s ! capsfilter name=caps ! decodebin ! %s ! clockoverlay name=overlay ! tee name=tee allow-not-linked=1 "

#define GAEGULI_PIPELINE_GENERAL_VIDEOCONVERT_STR    "\
        videoconvert ! video/x-raw,format=I420"

#define GAEGULI_PIPELINE_GENERAL_H264ENC_STR    "\
        queue name=enc_first ! x264enc tune=zerolatency bitrate=%d ! \
        h264parse ! queue "

#define GAEGULI_PIPELINE_GENERAL_H265ENC_STR    "\
        queue name=enc_first ! x265enc tune=zerolatency bitrate=%d ! \
        h265parse ! queue "

#define GAEGULI_PIPELINE_NVIDIA_TX1_VIDEOCONVERT_STR    "\
        nvvidconv ! video/x-raw(memory:NVMM),format=I420"

#define GAEGULI_PIPELINE_NVIDIA_TX1_H264ENC_STR    "\
        queue name=enc_first ! \
        omxh264enc insert-sps-pps=true insert-vui=true control-rate=1 bitrate=%d ! queue "

#define GAEGULI_PIPELINE_NVIDIA_TX1_H265ENC_STR    "\
        queue name=enc_first ! \
        omxh264enc insert-sps-pps=true insert-vui=true control-rate=1 bitrate=%d ! queue "

#define GAEGULI_PIPELINE_MUXSINK_STR    "\
        mpegtsmux name=muxsink_first ! tsparse set-timestamps=1 smoothing-latency=1000 ! \
        filesink name=muxink_last location=%s buffer-mode=unbuffered"

#endif // __GAEGULI_INTERNAL_H__

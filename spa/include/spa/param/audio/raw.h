/* Simple Plugin API
 * Copyright (C) 2016 Wim Taymans <wim.taymans@gmail.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin St, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#ifndef __SPA_AUDIO_RAW_H__
#define __SPA_AUDIO_RAW_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <endian.h>

enum spa_audio_format {
	SPA_AUDIO_FORMAT_UNKNOWN,
	SPA_AUDIO_FORMAT_ENCODED,
	SPA_AUDIO_FORMAT_S8,
	SPA_AUDIO_FORMAT_U8,
	SPA_AUDIO_FORMAT_S16_LE,
	SPA_AUDIO_FORMAT_S16_BE,
	SPA_AUDIO_FORMAT_U16_LE,
	SPA_AUDIO_FORMAT_U16_BE,
	SPA_AUDIO_FORMAT_S24_32_LE,
	SPA_AUDIO_FORMAT_S24_32_BE,
	SPA_AUDIO_FORMAT_U24_32_LE,
	SPA_AUDIO_FORMAT_U24_32_BE,
	SPA_AUDIO_FORMAT_S32_LE,
	SPA_AUDIO_FORMAT_S32_BE,
	SPA_AUDIO_FORMAT_U32_LE,
	SPA_AUDIO_FORMAT_U32_BE,
	SPA_AUDIO_FORMAT_S24_LE,
	SPA_AUDIO_FORMAT_S24_BE,
	SPA_AUDIO_FORMAT_U24_LE,
	SPA_AUDIO_FORMAT_U24_BE,
	SPA_AUDIO_FORMAT_S20_LE,
	SPA_AUDIO_FORMAT_S20_BE,
	SPA_AUDIO_FORMAT_U20_LE,
	SPA_AUDIO_FORMAT_U20_BE,
	SPA_AUDIO_FORMAT_S18_LE,
	SPA_AUDIO_FORMAT_S18_BE,
	SPA_AUDIO_FORMAT_U18_LE,
	SPA_AUDIO_FORMAT_U18_BE,
	SPA_AUDIO_FORMAT_F32_LE,
	SPA_AUDIO_FORMAT_F32_BE,
	SPA_AUDIO_FORMAT_F64_LE,
	SPA_AUDIO_FORMAT_F64_BE,

#if __BYTE_ORDER == __BIG_ENDIAN
	SPA_AUDIO_FORMAT_S16 = SPA_AUDIO_FORMAT_S16_BE,
	SPA_AUDIO_FORMAT_U16 = SPA_AUDIO_FORMAT_U16_BE,
	SPA_AUDIO_FORMAT_S24_32 = SPA_AUDIO_FORMAT_S24_32_BE,
	SPA_AUDIO_FORMAT_U24_32 = SPA_AUDIO_FORMAT_U24_32_BE,
	SPA_AUDIO_FORMAT_S32 = SPA_AUDIO_FORMAT_S32_BE,
	SPA_AUDIO_FORMAT_U32 = SPA_AUDIO_FORMAT_U32_BE,
	SPA_AUDIO_FORMAT_S24 = SPA_AUDIO_FORMAT_S24_BE,
	SPA_AUDIO_FORMAT_U24 = SPA_AUDIO_FORMAT_U24_BE,
	SPA_AUDIO_FORMAT_S20 = SPA_AUDIO_FORMAT_S20_BE,
	SPA_AUDIO_FORMAT_U20 = SPA_AUDIO_FORMAT_U20_BE,
	SPA_AUDIO_FORMAT_S18 = SPA_AUDIO_FORMAT_S18_BE,
	SPA_AUDIO_FORMAT_U18 = SPA_AUDIO_FORMAT_U18_BE,
	SPA_AUDIO_FORMAT_F32 = SPA_AUDIO_FORMAT_F32_BE,
	SPA_AUDIO_FORMAT_F64 = SPA_AUDIO_FORMAT_F64_BE,
	SPA_AUDIO_FORMAT_S16_OE = SPA_AUDIO_FORMAT_S16_LE,
	SPA_AUDIO_FORMAT_U16_OE = SPA_AUDIO_FORMAT_U16_LE,
	SPA_AUDIO_FORMAT_S24_32_OE = SPA_AUDIO_FORMAT_S24_32_LE,
	SPA_AUDIO_FORMAT_U24_32_OE = SPA_AUDIO_FORMAT_U24_32_LE,
	SPA_AUDIO_FORMAT_S32_OE = SPA_AUDIO_FORMAT_S32_LE,
	SPA_AUDIO_FORMAT_U32_OE = SPA_AUDIO_FORMAT_U32_LE,
	SPA_AUDIO_FORMAT_S24_OE = SPA_AUDIO_FORMAT_S24_LE,
	SPA_AUDIO_FORMAT_U24_OE = SPA_AUDIO_FORMAT_U24_LE,
	SPA_AUDIO_FORMAT_S20_OE = SPA_AUDIO_FORMAT_S20_LE,
	SPA_AUDIO_FORMAT_U20_OE = SPA_AUDIO_FORMAT_U20_LE,
	SPA_AUDIO_FORMAT_S18_OE = SPA_AUDIO_FORMAT_S18_LE,
	SPA_AUDIO_FORMAT_U18_OE = SPA_AUDIO_FORMAT_U18_LE,
	SPA_AUDIO_FORMAT_F32_OE = SPA_AUDIO_FORMAT_F32_LE,
	SPA_AUDIO_FORMAT_F64_OE = SPA_AUDIO_FORMAT_F64_LE,
#elif __BYTE_ORDER == __LITTLE_ENDIAN
	SPA_AUDIO_FORMAT_S16 = SPA_AUDIO_FORMAT_S16_LE,
	SPA_AUDIO_FORMAT_U16 = SPA_AUDIO_FORMAT_U16_LE,
	SPA_AUDIO_FORMAT_S24_32 = SPA_AUDIO_FORMAT_S24_32_LE,
	SPA_AUDIO_FORMAT_U24_32 = SPA_AUDIO_FORMAT_U24_32_LE,
	SPA_AUDIO_FORMAT_S32 = SPA_AUDIO_FORMAT_S32_LE,
	SPA_AUDIO_FORMAT_U32 = SPA_AUDIO_FORMAT_U32_LE,
	SPA_AUDIO_FORMAT_S24 = SPA_AUDIO_FORMAT_S24_LE,
	SPA_AUDIO_FORMAT_U24 = SPA_AUDIO_FORMAT_U24_LE,
	SPA_AUDIO_FORMAT_S20 = SPA_AUDIO_FORMAT_S20_LE,
	SPA_AUDIO_FORMAT_U20 = SPA_AUDIO_FORMAT_U20_LE,
	SPA_AUDIO_FORMAT_S18 = SPA_AUDIO_FORMAT_S18_LE,
	SPA_AUDIO_FORMAT_U18 = SPA_AUDIO_FORMAT_U18_LE,
	SPA_AUDIO_FORMAT_F32 = SPA_AUDIO_FORMAT_F32_LE,
	SPA_AUDIO_FORMAT_F64 = SPA_AUDIO_FORMAT_F64_LE,
	SPA_AUDIO_FORMAT_S16_OE = SPA_AUDIO_FORMAT_S16_BE,
	SPA_AUDIO_FORMAT_U16_OE = SPA_AUDIO_FORMAT_U16_BE,
	SPA_AUDIO_FORMAT_S24_32_OE = SPA_AUDIO_FORMAT_S24_32_BE,
	SPA_AUDIO_FORMAT_U24_32_OE = SPA_AUDIO_FORMAT_U24_32_BE,
	SPA_AUDIO_FORMAT_S32_OE = SPA_AUDIO_FORMAT_S32_BE,
	SPA_AUDIO_FORMAT_U32_OE = SPA_AUDIO_FORMAT_U32_BE,
	SPA_AUDIO_FORMAT_S24_OE = SPA_AUDIO_FORMAT_S24_BE,
	SPA_AUDIO_FORMAT_U24_OE = SPA_AUDIO_FORMAT_U24_BE,
	SPA_AUDIO_FORMAT_S20_OE = SPA_AUDIO_FORMAT_S20_BE,
	SPA_AUDIO_FORMAT_U20_OE = SPA_AUDIO_FORMAT_U20_BE,
	SPA_AUDIO_FORMAT_S18_OE = SPA_AUDIO_FORMAT_S18_BE,
	SPA_AUDIO_FORMAT_U18_OE = SPA_AUDIO_FORMAT_U18_BE,
	SPA_AUDIO_FORMAT_F32_OE = SPA_AUDIO_FORMAT_F32_BE,
	SPA_AUDIO_FORMAT_F64_OE = SPA_AUDIO_FORMAT_F64_BE,
#endif
};

/** Extra audio flags */
#define SPA_AUDIO_FLAG_NONE		(0)		/*< no valid flag */
#define SPA_AUDIO_FLAG_UNPOSITIONED	(1 << 0)	/*< the position array explicitly
							 *  contains unpositioned channels. */

/** Layout of the audio samples for the different channels.  */
enum spa_audio_layout {
	SPA_AUDIO_LAYOUT_INVALID,
	SPA_AUDIO_LAYOUT_INTERLEAVED,		/*< interleaved audio */
	SPA_AUDIO_LAYOUT_NON_INTERLEAVED,	/*< non-interleaved audio */
};

/** Audio information description */
struct spa_audio_info_raw {
	enum spa_audio_format format;	/*< format, one of enum spa_audio_format */
	uint32_t flags;			/*< extra flags */
	enum spa_audio_layout layout;	/*< sample layout */
	uint32_t rate;			/*< sample rate */
	uint32_t channels;		/*< number of channels */
	uint32_t channel_mask;		/*< channel mask */
};

#define SPA_AUDIO_INFO_RAW_INIT(...)		(struct spa_audio_info_raw) { __VA_ARGS__ }

#ifdef __cplusplus
}  /* extern "C" */
#endif

#endif /* __SPA_AUDIO_RAW_H__ */

/*
 * Copyright (C) 2018 Karol Herbst <kherbst@redhat.com>
 * All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef NVUVM_IOCTL_H
#define NVUVM_IOCTL_H

#include <sys/ioctl.h>
#include <inttypes.h>

/* see kernel/nvidia-uvm/uvm_ioctl.h inside the nvidia binary driver */
#define __KERNEL__
#include <uvm_ioctl.h>
#include <uvm_linux_ioctl.h>
#undef __KERNEL__

static inline UInt nvuvm_sizeof_ioctl(UInt ioctl)
{
	switch (ioctl) {
#define CASE(i) case (i): return sizeof(i##_PARAMS)
	CASE(UVM_CREATE_RANGE_GROUP);
	CASE(UVM_DISABLE_SYSTEM_WIDE_ATOMICS);
	CASE(UVM_IS_8_SUPPORTED);
	CASE(UVM_INITIALIZE);
	CASE(UVM_MAP_EXTERNAL_ALLOCATION);
	CASE(UVM_MEM_MAP);
	CASE(UVM_PAGEABLE_MEM_ACCESS);
	CASE(UVM_REGISTER_CHANNEL);
	CASE(UVM_REGISTER_GPU);
	CASE(UVM_REGISTER_GPU_VASPACE);
#undef CASE
	default: return 0;
	}
}

#endif

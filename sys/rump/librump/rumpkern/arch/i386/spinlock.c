/*	$NetBSD: spinlock.c,v 1.1 2010/05/31 22:31:07 pooka Exp $	*/

/*-
 * Copyright (c) 2000, 2006 The NetBSD Foundation, Inc.
 * All rights reserved.
 *
 * This code is derived from software contributed to The NetBSD Foundation
 * by Jason R. Thorpe and Andrew Doran.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *      
 * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <sys/cdefs.h>
__KERNEL_RCSID(0, "$NetBSD: spinlock.c,v 1.1 2010/05/31 22:31:07 pooka Exp $");

#define _HARDKERNEL /* XXX: non-inline prototypes */
#include <x86/lock.h>
#undef _HARDKERNEL

/*
 * Spinlocks, from src/sys/arch/x86/include/lock.h
 */
void
__cpu_simple_lock_init(__cpu_simple_lock_t *lockp)
{

	*lockp = __SIMPLELOCK_UNLOCKED;
	__insn_barrier();
}

int
__cpu_simple_lock_try(__cpu_simple_lock_t *lockp)
{
	uint8_t val;

	val = __SIMPLELOCK_LOCKED;
	__asm volatile ("xchgb %0,(%2)" : 
	    "=r" (val)
	    :"0" (val), "r" (lockp));
	__insn_barrier();
	return val == __SIMPLELOCK_UNLOCKED;
}

void
__cpu_simple_lock(__cpu_simple_lock_t *lockp)
{

	while (!__cpu_simple_lock_try(lockp))
		/* nothing */;
	__insn_barrier();
}

void
__cpu_simple_unlock(__cpu_simple_lock_t *lockp)
{

	__insn_barrier();
	*lockp = __SIMPLELOCK_UNLOCKED;
}

#	$NetBSD: Makefile,v 1.5 2012/05/30 05:20:36 macallan Exp $

DRIVER=		xf86-video-nv
DRIVER_NAME=	nv_drv

SRCS=		nv_cursor.c nv_dac.c nv_dga.c nv_driver.c nv_hw.c
SRCS+=		nv_setup.c nv_shadow.c nv_video.c nv_xaa.c riva_cursor.c
SRCS+=		riva_dac.c riva_dga.c riva_driver.c riva_hw.c
SRCS+=		riva_setup.c riva_shadow.c riva_xaa.c g80_cursor.c
SRCS+=		g80_dac.c g80_display.c g80_dma.c g80_driver.c g80_exa.c
SRCS+=		g80_output.c g80_sor.c g80_xaa.c
MAN=		nv.4

.if ${MACHINE} == "macppc"
CPPFLAGS+= -DAVOID_VGAHW
.endif

.include "../Makefile.xf86-driver"

#	$NetBSD: Makefile,v 1.15 2009/12/13 05:01:33 nakayama Exp $

.if (${MACHINE_ARCH} == "i386" || \
     ${MACHINE} == "hpcmips" || \
     ${MACHINE} == "hpcsh" || \
     ${MACHINE} == "macppc" || \
     ${MACHINE} == "sparc" || \
     ${MACHINE} == "zaurus")
PROG=	apmd
SRCS=	apmd.c apmsubr.c
.endif

MAN=	apmd.8

LDADD+=	-lutil
DPADD+=	${LIBUTIL}

.include <bsd.prog.mk>

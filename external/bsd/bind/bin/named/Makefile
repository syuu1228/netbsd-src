#	$NetBSD: Makefile,v 1.4 2011/09/11 18:55:24 christos Exp $

.include <bsd.own.mk>

PROG=	named
MAN=	named.8 lwresd.8 named.conf.5
BINDIR=	/usr/sbin
LINKS=	${BINDIR}/named ${BINDIR}/lwresd

.include "${.CURDIR}/../Makefile.inc"

DIST=${IDIST}/bin/named
CPPFLAGS+=-I${DIST}/include -I${DIST}/unix/include -DCONFIGARGS=\"defaults\"
CPPFLAGS+=-DNO_VERSION_DATE

.if defined(HAVE_GCC)
.for f in client
COPTS.${f}.c+=  -fno-strict-aliasing
.endfor
.endif

.PATH: ${DIST}/unix ${DIST}

SRCS_UNIX=	os.c dlz_dlopen_driver.c
SRCS=	builtin.c client.c config.c control.c controlconf.c \
	interfacemgr.c listenlist.c log.c logconf.c \
	lwaddr.c lwdclient.c lwderror.c \
	lwdgabn.c lwdgnba.c lwdgrbn.c lwdnoop.c lwresd.c lwsearch.c \
	main.c notify.c query.c server.c sortlist.c statschannel.c \
	tkeyconf.c tsigconf.c \
	update.c xfrout.c zoneconf.c ${SRCS_UNIX}

.include <bsd.prog.mk>

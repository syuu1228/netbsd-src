#	$NetBSD: Makefile,v 1.2 2008/05/19 13:41:21 ad Exp $

.include "../Makefile.inc"

.PATH:	${S}/fs/cd9660

KMOD=	cd9660
SRCS=	cd9660_bmap.c cd9660_lookup.c cd9660_node.c cd9660_rrip.c \
	cd9660_util.c cd9660_vfsops.c cd9660_vnops.c

.include <bsd.kmodule.mk>

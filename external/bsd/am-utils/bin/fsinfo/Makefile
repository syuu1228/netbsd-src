#	$NetBSD: Makefile,v 1.4 2011/05/26 12:56:25 joerg Exp $

.include "${.CURDIR}/../Makefile.inc"

PROG=	fsinfo

DIST=	${IDIST}/fsinfo
.PATH:	${DIST}

SRCS=	fsi_analyze.c fsi_dict.c fsi_gram.y fsi_lex.l fsi_util.c fsinfo.c \
	wr_atab.c wr_bparam.c wr_dumpset.c wr_exportfs.c wr_fstab.c
MAN+=	fsinfo.8


YPREFIX.fsi_gram.y =	fsi_yy
LPREFIX.fsi_lex.l =	fsi_yy
CPPFLAGS.fsi_lex.c += -Dyylval=fsi_yylval -Dyyerror=fsi_yyerror
CPPFLAGS.fsi_util.c += -Dyyerror=fsi_yyerror -Dyyparse=fsi_yyparse
CPPFLAGS.fsinfo.c += -Dyyparse=fsi_yyparse

CWARNFLAGS.clang+=	-Wno-unneeded-internal-declaration

FSINFOOBJDIR!=cd ${.CURDIR} && ${PRINTOBJDIR}

CPPFLAGS+=	-I${DIST} -I${FSINFOOBJDIR}
YHEADER=	1

.include <bsd.prog.mk>

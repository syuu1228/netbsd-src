/*	$NetBSD: checkrev.c,v 1.1.1.1 2012/03/23 21:20:08 christos Exp $	*/

/*
 * Copyright (C) 2009 by Darren Reed.
 *
 * See the IPFILTER.LICENCE file for details on licencing.
 *
 * Id
 */

#include <sys/ioctl.h>
#include <fcntl.h>

#include "ipf.h"
#include "netinet/ipl.h"

int checkrev(ipfname)
	char *ipfname;
{
	static int vfd = -1;
	struct friostat fio;
	ipfobj_t obj;

	bzero((caddr_t)&obj, sizeof(obj));
	obj.ipfo_rev = IPFILTER_VERSION;
	obj.ipfo_size = sizeof(fio);
	obj.ipfo_ptr = (void *)&fio;
	obj.ipfo_type = IPFOBJ_IPFSTAT;

	if ((vfd == -1) && ((vfd = open(ipfname, O_RDONLY)) == -1)) {
		perror("open device");
		return -1;
	}

	if (ioctl(vfd, SIOCGETFS, &obj)) {
		perror("ioctl(SIOCGETFS)");
		close(vfd);
		vfd = -1;
		return -1;
	}

	if (strncmp(IPL_VERSION, fio.f_version, sizeof(fio.f_version))) {
		return -1;
	}
	return 0;
}

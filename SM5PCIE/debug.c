#include <stdio.h>

#define DUMP_COLUMN	16

void dump(void *data, unsigned long len)
{
	unsigned long i;

	for (i = 0; i < len; ++i) {
		if (i % DUMP_COLUMN == 0)
			printf("%04lx: ", i);
		if (i % DUMP_COLUMN == DUMP_COLUMN - 1)
			printf("%02x\r\n", ((uint8_t *)data)[i]);
		else
			printf("%02x ", ((uint8_t *)data)[i]);
	}
	printf("\r\n");
}

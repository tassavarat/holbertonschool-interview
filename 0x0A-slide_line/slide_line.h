#ifndef SLIDE_LINE_H
#define SLIDE_LINE_H

#include <stdlib.h>

#define SLIDE_LEFT	-1
#define SLIDE_RIGHT	 1

#define SWAP(line, empt, i)				\
	do {					\
		if (line[i])			\
		{				\
			line[empt] ^= line[i];	\
			line[i] ^= line[empt];	\
			line[empt] ^= line[i];	\
			break;			\
		}				\
	} while (0)

#define MERGE(line, i, direction)					\
	do {								\
		if (line[i] == line[i - direction])			\
		{							\
			line[i] += line[i - direction];			\
			line[i - direction] ^= line[i - direction];	\
			i -= direction;					\
		}							\
	} while (0)

int slide_line(int *line, size_t size, int direction);

#endif /* SLIDE_LINE_H */

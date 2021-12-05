// https://leetcode.com/problems/longest-common-prefix/

#include "header.h"

static char prefix[10000];

char* longestCommonPrefix(char** strs, int strsSize) {
	int pos;
	char *p = prefix;
	
	pos = 0;
	
	if (strsSize == 0) {
		goto exit;
	}
	
	while(1) {
		int i;
		char cmp_ch = strs[0][pos];
		
		if (cmp_ch == '\0') {
			goto exit;
		}
		
		for (i = 1; i < strsSize; i++) {
			char ch = strs[i][pos];
			if ((ch == '\0') || (ch != cmp_ch)) {
				goto exit;
			}
		}
		
		*p++ = cmp_ch;
		pos++;
	}

exit:
	*p = '\0';
	return prefix;
}

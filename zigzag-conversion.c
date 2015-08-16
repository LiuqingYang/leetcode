// https://leetcode.com/problems/zigzag-conversion/
// Yang Liuqing
// yllqq@outlook.com


char* convert(char* s, int numRows) {
	int group_len = 2 * numRows - 2;
	int len = strlen(s);
	char *output, *output_p;

	//Init
	output = malloc(sizeof(char) * (len + 1));
	output_p = output;

	//Calc
	if (group_len == 0)
	{
		memcpy(output, s, len + 1);
		return output;
	}
	for (int i = 0; i < numRows; i++)
	{
		char *s_p = s;
		int group_pos1 = i;
		int group_pos2 = group_len - i;
		if (i == 0 || i == (numRows - 1)) group_pos2 = -1;
		while (1)
		{
			if (s_p + group_pos1 >= s + len) break;
			else *output_p++ = *(s_p + group_pos1);

			if (group_pos2 == -1)
			{
				s_p += group_len;
				continue;
			}
			else if (s_p + group_pos2 >= s + len) break;
			else *output_p++ = *(s_p + group_pos2);
			s_p += group_len;
		}
	}

	//Free&return
	output[len] = '\0';
	return output;
}

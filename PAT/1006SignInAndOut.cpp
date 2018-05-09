#include <cstdio>
#include <cstring>

using namespace std;

int main(void) {
	char first[30], last[30], temp_name[30];
	int unlock = 86401, lock = 0, cnt;
	int in_hour, in_min, in_sec, out_hour, out_min, out_sec;
	scanf("%d", &cnt);
	while (cnt--) {
		scanf("%s %d:%d:%d %d:%d:%d", temp_name, &in_hour, &in_min, &in_sec,
				&out_hour, &out_min, &out_sec);
		// to seconds
		in_sec += in_hour * 3600 + in_min * 60;
		out_sec += out_hour * 3600 + out_min * 60;
		if (in_sec < unlock) {
			unlock = in_sec;
			strcpy(first, temp_name);
		}
		if (out_sec > lock) {
			lock = out_sec;
			strcpy(last, temp_name);
		}
	}

	printf("%s %s\n", first, last);

	return 0;
}
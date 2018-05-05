#include <cstdio>

int board[3][3];

int get_winner() {
	// judge winner
	// check row
	// check multipile
	int multi;
	for (int i = 0; i < 3; ++i) {
		multi = board[i][0] * board[i][1] * board[i][2];
		if (multi == 8) {
			return 2;
		} else if (multi == 1) {
			return 1;
		}
	}
	// check col
	for (int i = 0; i < 3; ++i) {
		multi = board[0][i] * board[1][i] * board[2][i];
		if (multi == 8) {
			return 2;
		} else if (multi == 1) {
			return 1;
		}
	}
	// check cross
	multi = board[0][0] * board[1][1] * board[2][2];
	if (multi == 8) {
		return 2;
	} else if (multi == 1) {
		return 1;
	}
	multi = board[0][2] * board[1][1] * board[2][0];
	if (multi == 8) {
		return 2;
	} else if (multi == 1) {
		return 1;
	}
	
	return 0;
}

int get_zeroes() {
	int sum = 0;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			sum += board[i][j] == 0 ? 1 : 0;
		}
	}
//	printf("zeroes: %d\n", sum);
	return sum;
}

// set one 0 to 1
int can_win() {
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (board[i][j] == 0) {
				board[i][j] = 1;
				if (get_winner() == 1) {
					return get_zeroes() + 1;
				}
				board[i][j] = 0;
			}
		}
	}
	
	return 0;
}

int main() {
	int cnt;
	scanf("%d", &cnt);
	while (cnt-- > 0) {
		// input board
		for (int i = 0; i < 3; ++i) {
			scanf("%d %d %d", &board[i][0], &board[i][1], &board[i][2]);
		}
		// judge if have people win
		// Alice 1, Bob 2, None 0
		int winner = get_winner();
		//printf("Winner: %d\n", winner);
		if (winner == 1) {
			printf("%d\n", get_zeroes() + 1);
			continue;
		} else if (winner == 2) {
			printf("%d\n", -get_zeroes() - 1);
			continue;
		}
		// who will win??
		printf("%d\n", can_win());
	}
	
	return 0;
}

/*
3
1 2 1
2 1 2
0 0 0
2 1 1
0 2 1
0 0 2
0 0 0
0 0 0
0 0 0
*/

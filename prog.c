int main() {
	char c;
	int i, j, k;

	c = 9;
	i = 10;
	j = 20;
	k = ((i*3) + (j-5)) / 9;

	if (k > 10) {
		k = 5;
	}
	else {
		k = 0;
	}

	while (k < 10) {
		k = k+1;
	}
}



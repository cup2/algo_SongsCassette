#include <iostream>

void generateSequence(int* sequence, int S, int A, int B, int M, int n);
void sortToMgoodSongs(int* sequence, int first, int last, int m);
int findSumToM(int* sequence, int  m);

int main() {
	int n;
	std::cin >> n;
	int m;
	std::cin >> m;
	int S;
	std::cin >> S; 
	int A;
	std::cin >> A;
	int B;
	std::cin >> B;
	int M;
	std::cin >> M;
	int* sequence = new int[n];
	generateSequence(sequence, S, A, B, M, n);
	sortToMgoodSongs(sequence, 0, n - 1, m); 
	std::cout << findSumToM(sequence, m);
	return 0;
}

void generateSequence(int* sequence, int S, int A, int B, int M, int n) {
	sequence[0] = S;
	for (int i = 1; i < n; ++i) {
		sequence[i] = ((A * sequence[i - 1] + B) % M);
	}
}

void sortToMgoodSongs(int* sequence, int first, int last, int m) {
	int needElementsInLeft = m;
	int elemleft = 0;
	int left = first;
	int right = last;

	while (elemleft != needElementsInLeft) {
		left = first;
		right = last;
		int pivot = sequence[(left + right) / 2];
		do
		{
			while (sequence[left] < pivot) {
				left++;
			}

			while (sequence[right] > pivot) {
				right--;
			}

			if (left <= right)
			{
				std::swap(sequence[left], sequence[right]);
				right--;
				left++;
			}
		} while (left <= right);


		elemleft = left - first;
		if ((elemleft) > needElementsInLeft) {
			last = left - 1;
		}
		else if ((elemleft) < needElementsInLeft) {
			first = left;
			needElementsInLeft = needElementsInLeft - elemleft;
		}
	}
}

int findSumToM(int* sequence, int  m) {
	int sum = 0;
	for (int i = 0; i < m; i++) {
		sum += sequence[i];
	}
	return sum;
}

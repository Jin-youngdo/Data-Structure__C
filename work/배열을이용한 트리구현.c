// �迭�� �̿��� Ʈ�� ����
#include <stdio.h>

char tree[7];
// ��Ʈ ��� �ʱ�ȭ
int root(char key) {
	if (tree[0] != '\0')
		printf("Tree already had root");
	else
		tree[0] = key;
	return 0;
}

// �θ� ��� ���� ���ʿ� �ڽ� ��� ����
int set_left(char key, int parent) {
	if (tree[parent] == '\0')
		printf("�ε���%d�� %c ���� �Ұ� [�θ� ��� ������]\n", (parent*2)+1, key);
	else
		tree[(parent * 2)+1] = key;
	return 0;
}

// �θ� ��� ���� �����ʿ� �ڽ� ��� ����
int set_right(char key, int parent) {
	if (tree[parent] == '\0')
		printf("�ε���%d�� %c ���� �Ұ� [�θ� ��� ������]\n", (parent*2)+2, key);
	else
		tree[(parent * 2) + 2] = key;
	return 0;
}

// Ʈ�� ���
int print_tree() {
	int cnt = 0;
	int n = 1;
	printf("\n    < tree >");
	while (cnt != 7) {
		if (cnt == (n-1)) {
			printf("\n");
			n = n * 2;
		}
		if (cnt == 0) {
			printf("        %c", tree[cnt]);
			cnt++;
		}
		else if (cnt < 3) {
			printf(" %5c", tree[cnt]);
			cnt++;
		}
		else if(3<=cnt<7) {
			printf("  %c ", tree[cnt]);
			cnt++;
		}
	}
	return 0;
}

int main(void) {

	root('A');

	set_left('B', 0);
	set_right('C', 0);

	set_left('D', 1);
	set_right('E', 1);
	set_left('F', 2);
	set_right('G', 2);

	print_tree();
	return 0;
}
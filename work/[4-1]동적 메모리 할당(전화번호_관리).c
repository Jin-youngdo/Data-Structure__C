// ���� �޸� �Ҵ� - ��ȭ��ȣ ���� ����
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define STR_SIZE 11
#define MAX 100

typedef struct {
	char name[STR_SIZE];
	char phone[STR_SIZE];
	int ringtone;
} CONTACT;

int main(void) {

	CONTACT* arr[MAX] = { NULL };
	int cnt=0, i = 0;

	while (cnt < MAX) {

		char str[STR_SIZE] = "";
		char phone[12] = "";
		printf("����ó�� ����մϴ�. �̸�(.�Է½� ����)? ");
		scanf("%s", str);

		if (strcmp(str, ".") == 0) 
			break;

		arr[cnt] = (CONTACT*)malloc(sizeof(CONTACT));
		strcpy(arr[cnt]->name, str);

		printf("��ȭ��ȣ? ");
		scanf("%s", arr[cnt]->phone);
		
		arr[cnt]->ringtone = cnt;
		cnt++;
	}

	printf(" �̸�  ��ȭ��ȣ  ��\n");
	for (i = 0; i < cnt; i++) {
		printf("%3s  %11s  %d\n", arr[i]->name, arr[i]->phone, arr[i]->ringtone);
	}

	// ���� �޸� ��ȯ, �迭 �ʱ�ȭ
	for (i = 0; i < cnt; i++) {
		free(arr[i]);
		arr[i] = NULL;
	}
	return 0;
}
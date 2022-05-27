// 동적 메모리 할당 - 전화번호 관리 예제
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
		printf("연락처를 등록합니다. 이름(.입력시 종료)? ");
		scanf("%s", str);

		if (strcmp(str, ".") == 0) 
			break;

		arr[cnt] = (CONTACT*)malloc(sizeof(CONTACT));
		strcpy(arr[cnt]->name, str);

		printf("전화번호? ");
		scanf("%s", arr[cnt]->phone);
		
		arr[cnt]->ringtone = cnt;
		cnt++;
	}

	printf(" 이름  전화번호  벨\n");
	for (i = 0; i < cnt; i++) {
		printf("%3s  %11s  %d\n", arr[i]->name, arr[i]->phone, arr[i]->ringtone);
	}

	// 동적 메모리 반환, 배열 초기화
	for (i = 0; i < cnt; i++) {
		free(arr[i]);
		arr[i] = NULL;
	}
	return 0;
}
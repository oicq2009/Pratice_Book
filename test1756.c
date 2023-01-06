// 教朋友鏈表  2023年1月6日23:35:24 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Node{
	int st_id;
	char* st_name;
	struct _Node *link;
}Node;


Node *head=NULL;

void create_Node(int id, char *name);

int main() {
	
	int id, i;
	char name[10];
	Node *prin;

	for(i = 0 ; i < 5 ; i++){	
		printf("Input student id : ");
		scanf("%d", &id);
		printf("Input student name : ");
		scanf("%s", name);

		create_Node(id, name);
	}

	/* 
	  prin의 link을 따라가며 node의 st_id와 st_name을 출력 (5회) 
	*/
	for (prin = head; prin != NULL; prin = prin->link) {      // 遍歷整個鏈錶
        printf("%d\t%s \t%\n", prin->st_id, prin->st_name, prin->link);
	}

	return 0;
}


void create_Node(int id, char *name) {
	// function body 구현 

	Node* new = (Node*)malloc(sizeof(Node));     // 堆上申請空間給新結點
	new->st_name = (char*)malloc(strlen(name) + 1);  // 從堆上申請name大小的空間


	// TODO
	// assign id to new->st_id
	// ...  
	new->st_id = id;    // 結構體賦值
	strcpy(new->st_name, name);   // 通過strcpy函式完成字符串拷貝
	new->link = NULL;             // 將 link 初始化為空


	// 若頭結點為空
	if (head == NULL) {
		// TODO
		head = new;    // 則讓新結點作為頭結點
	}
	else {      // 頭結點不為空，則頭結點已存在，向後插入即可
		// TODO
		Node* tmp = head;    // 創建臨時變量存儲頭結點
		while (tmp->link != NULL) {      // 若結點的下一個元素不為空
			tmp = tmp->link;    // 鏈接
		}
		tmp->link = new;  
	}
}



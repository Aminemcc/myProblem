#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/* Linked List Queue sekalian Stack */
typedef struct snode_t {
    int data;
    struct snode_t *next;
} SListNode;

typedef struct slist_t {
    unsigned _size;
    SListNode *_head;
} SinglyList;

void slist_init(SinglyList *list) {
    list->_head = NULL;
    list->_size = 0;
}

bool slist_isEmpty(SinglyList *list) {
    return (list->_head == NULL);
}

void slist_pushFront(SinglyList *list, int value) {
    SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
    if (newNode) {
        list->_size++;
        newNode->data = value;

        if (slist_isEmpty(list)) newNode->next = NULL;
        else newNode->next = list->_head;
        list->_head = newNode;
    }
}

void slist_popFront(SinglyList *list){
    if (!slist_isEmpty(list)) {
        SListNode *temp = list->_head;
        list->_head = list->_head->next;
        free(temp);
        list->_size--;
    }
}

void slist_pushBack(SinglyList *list, int value){
    SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
    if (newNode) {
        list->_size++;
        newNode->data = value;
        newNode->next = NULL;
        
        if (slist_isEmpty(list)) 
            list->_head = newNode;
        else {
            SListNode *temp = list->_head;
            while (temp->next != NULL) 
                temp = temp->next;
            temp->next = newNode;
        }
    }
}

int slist_front(SinglyList *list){
    if (!slist_isEmpty(list)) {
        return list->_head->data;
    }
    return 0;
}


typedef struct nums{
	char *data;
	int angka;
	int basis;
}nums;

typedef struct dynamicarr_t {
    nums *_arr;
    unsigned _size, _capacity;
} DynamicArray;

void dArray_init(DynamicArray *darray){
    darray->_capacity = 2u;
    darray->_size = 0u;
    darray->_arr = (nums*) malloc(sizeof(nums) * 2);
}

bool dArray_isEmpty(DynamicArray *darray){
    return (darray->_size == 0);
}

void dArray_pushBack(DynamicArray *darray, nums value){
    if (darray->_size + 1 > darray->_capacity) {
        unsigned it;
        darray->_capacity *= 2;
        nums *newArr = (nums*) malloc(sizeof(nums) * darray->_capacity);

        for (it=0; it < darray->_size; ++it)
            newArr[it] = darray->_arr[it];
        
        nums *oldArray = darray->_arr;
        darray->_arr = newArr;
        free(oldArray);
    }
    darray->_arr[darray->_size++] = value;
}

nums dArray_back(DynamicArray *darrray){
    if (!dArray_isEmpty(darrray))
        return darrray->_arr[darrray->_size-1];
    nums output;
	output.angka = -1;
    return output;
}

nums dArray_front(DynamicArray *darray){
    if (!dArray_isEmpty(darray))
        return darray->_arr[0];
    nums output;
	output.angka = -1;
    return output;
}

nums dArray_getAt(DynamicArray *darray, unsigned index){
    if (!dArray_isEmpty(darray)) {
        if (index < darray->_size)
            return darray->_arr[index];
    }
    nums output;
	output.angka = -1;
    return output;
}


nums is_palindrom(int angka, int basis){
	nums output;
	output.angka = angka;
	output.basis = basis;
	char *data;
	char dummy[5] = "";
	int digit;
	if(angka == 0){
		output.data = "0";
		printf("Ya\n");
	}
	else{
		bool is_palindrom = true;
		SinglyList queue, stack;
		slist_init(&queue);
		slist_init(&stack);
		while(angka > 0){
			slist_pushFront(&stack, angka % basis);
			slist_pushBack(&queue, slist_front(&stack));
			angka -= slist_front(&stack);
			if(basis > 1) angka /= basis;
			else angka--;
		}
		digit = 0;
		while(basis > 0){
			basis /= 10;
			digit++;
		}
		data = (char*) malloc(sizeof(char) * stack._size * (digit + 1));
		strcpy(data, dummy);
		while(!slist_isEmpty(&stack)){
			if(slist_front(&stack) != slist_front(&queue)){
				is_palindrom = false;
			}
			sprintf(dummy, "%d-", slist_front(&stack));
			strcat(data, dummy);
			slist_popFront(&stack);
			slist_popFront(&queue);
		}
		data[strlen(data) - 1] = '\0';
		if(is_palindrom) printf("Ya\n");
		else printf("Tidak\n");
		output.data = data;
	}
	return output;
}

int main(int argc, char const *argv[]){
    // Buat objek DynamicArray
    DynamicArray history;
    dArray_init(&history);
    int angka, basis;
    char *data;
    nums temp;
    while(1){
    	scanf("%d%d",&angka,&basis);
    	if(angka == -1){
    		if(basis == -1) break;
    		if(basis < 0 || basis >= history._size){
    			printf("Out of range\n");
			}
			else{
	    		temp = dArray_getAt(&history, basis);
	    		printf("%d %d -> %s\n",temp.angka, temp.basis, temp.data);
			}
		}
    	else{
    		temp = is_palindrom(angka, basis);
    		dArray_pushBack(&history, temp);	
		}		
	}
	
    return 0;
}

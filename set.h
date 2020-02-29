#define INT_MIN -2000000007;

struct SET {
    int elements[2000005];
    int pos;
};

void init(struct SET **set) {
	// For initialising set structure.
	*set = (struct SET *)malloc(sizeof(struct SET));
	for(int i = 0; i < 2000005; i++) (*set)->elements[i] = INT_MIN;
	(*set)->pos = 0;
}

int search(struct SET *set , int x) {
	//Returns whether element is present or not . If present it returns its index else -1.
	int idx = -1 , l = 0 , r = set->pos-1;
	while(l <= r) {
		int mid = (l+r)/2;
		if(set->elements[mid] == x) {
			idx = mid;
			break;
		}
		else if(set->elements[mid] > x) r = mid-1;
		else l = mid+1;
	}
	return idx;
}

int upper_bound(struct SET *set , int x) {
	//Returns the index of element just strictly greater than x . If x is largest it returns -1.
	int idx = -1 , l = 0 , r = set->pos-1;
	while(l <= r) {
		int mid = (l+r)/2;
		if(set->elements[mid] > x) {
			idx = mid;
			r = mid-1;
		}
		else l = mid+1;
	}
	return idx;
}

void insert(struct SET **set , int x) {
	// Set insert operation.
	int found = search(*set , x);
	if(found == -1) {
		int idx = upper_bound(*set , x);
		if(idx == -1) {
			(*set)->elements[(*set)->pos] = x;
			(*set)->pos++;
		}
		else {
			int temp;
			for(int i = idx; i < (*set)->pos; i++) {
				temp = (*set)->elements[i];
				(*set)->elements[i] = x;
				x = temp;
			}
			(*set)->elements[(*set)->pos] = x;
			(*set)->pos++;
		}
	}
}

void _remove(struct SET **set , int x) {
	// Set remove operation.
	int idx = search(*set , x);
	if(idx != -1) {
		for(int i = idx+1; i < (*set)->pos; i++) (*set)->elements[i-1] = (*set)->elements[i];
		(*set)->pos--;
		(*set)->elements[(*set)->pos] = INT_MIN;
	}
}

void modify(struct SET **set , int old , int new) {
	// Set modify operation.
	_remove(set , old);
	insert(set , new);
} 

void printset(struct SET *set) {
	// Set print operation.
	printf("Set elements are : \n");
	for(int i = 0; i < set->pos; i++) printf("%d " , set->elements[i]);
	printf("\n");
}

int size(struct SET *set) {
	// Returns the size of set.
	return set->pos;
}

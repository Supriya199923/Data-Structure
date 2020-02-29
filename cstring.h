struct String {
    int maxLength;
    int length;
    char *str;
};

void init(struct String **s , int maxlen) {
    // Initialize the variables.
    if(maxlen > 1000000) {
        printf("Memory Insufficient.\n Try smaller values.\n");
        return;
    }
    else {
        *s = (struct String *)malloc(sizeof(struct String));
        (*s)->maxLength = maxlen;
        (*s)->length = 0;
        (*s)->str = (char *)malloc((*s)->maxLength * sizeof(char));
    }
}

void insert(char *c , struct String **s) {
    // Inserting a string
    int len = 0;
    while(c[len]) len++;
    if(len > 1000000) {
        printf("Given string too large to be inserted.\n");
        return;
    }
    for(int i = 0; i < len; i++) {
        (*s)->str[i] = c[i];
    }
    (*s)->str[len] = '\0';
    (*s)->length = len;
}

void join(struct String **s , char *s1) {
    // Concatenates s1 to s.
    for(int i = 0; s1[i]; i++) {
        (*s)->str[(*s)->length++] = s1[i];
    }
    (*s)->str[(*s)->length] = '\0';
}

char at(int index , struct String *s) {
    // Returns character at index = index(for 0 based indexing).
    if(index <= 999999) {
        return (s->str[index]);
    }
    else {
        printf("Out of Bounds.\n");
        return '\0';
    }
}

void eraseAt(int index , struct String **s) {
    // Erases the character at index = index(For 0 based indexing).
    if(index <= 999999) {
        for(int i = index+1; i < (*s)->length; i++) {
            (*s)->str[i-1] = (*s)->str[i];
        }
        (*s)->str[(*s)->length-1] = (*s)->str[(*s)->length];
        (*s)->length--;
    }
}

void substr(int l, int r, struct String *s, char **sub) {
    if(l > r) {
        printf("Invalid Range.\n");
        return;
    }
    else {
        if(r <= 999999) {
            int lim = (r <= s->length-1)?r:s->length-1;
            *sub = (char *)malloc((lim-l+1)*sizeof(char));
            for(int i = l , k = 0; i <= lim; i++ , k++) (*sub)[k] = s->str[i];
        }
    }
}

void showString(struct String *s) {
    for(int i = 0; i < s->length; i++) printf("%c" , s->str[i]);
    printf("\n");
}

void destruct(struct String **s) {
    free((*s)->str);
}

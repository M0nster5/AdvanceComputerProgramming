struct node{
	int key;
	unsigned char height;
	node* left;
	node* right;
	node(int k) { key = k; left = right = 0; height = 1; }
};

unsigned char height(node* p){
	return p ? p->height : 0;
}

int balanceFactor(node* p){
	return height(p->right) - height(p->left);
}

void fixHeight(node* p){
	unsigned char hL = height(p->left);
	unsigned char hR = height(p->right);
	p->height = (hL>hR ? hL: hR) + 1;
}

node* rotaterRight(node* p){
	node* q = p->left;
	p->left = q->right;
	q->right = p;
	fixHeight(p);
	fixHeight(q);
	return q;
}

node* rotaterLeft(node* q){
	node* p = q->right;
	q->right = p->left;
	p->left = q;
	fixHeight(q);
	fixHeight(p);
	return p;
}

node* balance(node* p){
	fixHeight(p);
	if (balanceFactor(p)==2){
		if (balanceFactor(p->right) < 0){
			p->right = rotaterRight(p->right);
		}
		return rotaterLeft(p);
	}
	if (balanceFactor(p)==-2){
		if(balanceFactor(p->left)>0){
			p->left = rotaterLeft(p->left);
		}
		return rotaterRight(p);
	}
	return p;
}

node* insert(node* p, int k){
	if (!p) return new node(k);
	if (k<p->key)
		p->left = insert(p->left,k);
	else
		p->right = insert(p->right,k);
	return balance(p);
}

node* findmin(node* p)
{
    return p->left?findmin(p->left):p;
}

node* removeMin(node* p){
	if(p->left==0)
		return p->right;
	p->left = removeMin(p->left);
	return balance(p);
}

node* remove(node* p,int k){
	if(!p) return 0;
	if (k<p->key)
		p->left = remove(p->left,k);
	else if(k > p-> key)
		p->right = remove(p->right, k);
	else 
    {
        node* q = p->left;
        node* r = p->right;
        delete p;
        if( !r ) return q;
        node* min = findmin(r);
        min->right = removeMin(r);
        min->left = q;
        return balance(min);
    }
    return balance(p);
}















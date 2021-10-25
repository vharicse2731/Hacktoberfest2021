

// https://practice.geeksforgeeks.org/problems/construct-an-expression-tree/1

et* tree(char p[],int *n){
    et* root=new et(p[*n]);
    if(p[*n]=='+' || p[*n]=='-' || p[*n]=='*' || p[*n]=='/' || p[*n]=='^'){
        (*n)--;
        root->right=tree(p,n);
        (*n)--;
        root->left=tree(p,n);
    }
    else
        root->right=root->left=NULL;
    return root;
}

et* constructTree(char postfix[]){
    int n = strlen(postfix)-1;
    return tree(postfix,&n);
}
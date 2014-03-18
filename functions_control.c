//
//  functions_control.c
//  binary
//
//  Created by Ethan Laur on 3/17/14.
//  Copyright (c) 2014 Ethan Laur. All rights reserved.
//

#include <stdlib.h>
#include "functions.h"

binary_tree * binary_tree_alloc (void         )
{
	return malloc(sizeof(binary_tree));
}

void          binary_tree_init  (binary_tree *tree)
{
	tree->root = NULL;
	tree->nitems = 0;
}

void          binary_tree_free_private(binary_tree_node *t)
{
	if (t == NULL) return;
	binary_tree_free_private(t->left);
	binary_tree_free_private(t->right);
	free(t->data);
}

void          binary_tree_free  (binary_tree *t)
{
	if (t == NULL) return;
	binary_tree_free_private(t->root);
	free(t);
}

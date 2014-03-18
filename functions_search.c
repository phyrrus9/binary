//
//  functions_search.c
//  binary
//
//  Created by Ethan Laur on 3/18/14.
//  Copyright (c) 2014 Ethan Laur. All rights reserved.
//

#include <stdlib.h>
#define __binary_functions_private_h__
#include "functions.h"
#undef __binary_functions_private_h__

struct binary_tree_search_private_struct binary_tree_search_private(binary_tree_node *p, int node,
													   binary_tree_node *l)
{
	struct binary_tree_search_private_struct r;
	if (p == NULL)
	{
		r.parent = NULL;
		r.node = NULL;
		return r;
	}
	else
	{
		if (getkey_private(p->data) == node)
		{
			r.parent = l;
			r.node = p;
			return r;
		}
		r = binary_tree_search_private(p->left, node, p);
		if (r.node == NULL)
		{
			r = binary_tree_search_private(p->right, node, p);
		}
	}
	return r; //code will never get here
}

binary_node   binary_tree_search(binary_tree *tree, int node)
{
	struct binary_tree_search_private_struct r = binary_tree_search_private(tree->root, node, tree->root);
	return r.node == NULL ? NULL : (char *)(r.node->data);
}

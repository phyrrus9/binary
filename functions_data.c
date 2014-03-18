//
//  functions_data.c
//  binary
//
//  Created by Ethan Laur on 3/17/14.
//  Copyright (c) 2014 Ethan Laur. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define __binary_functions_private_h__
#include "functions.h"
#undef __binary_functions_private_h__

struct binary_placement
{
	binary_tree_node *parent;
	char placement;
};

#define getkey(a) getkey_private(a)
#define getdata(a) getkey_private(a)

struct binary_placement find_placement(binary_tree_node *p, binary_node node, binary_tree_node *l)
{
	struct binary_placement ret;
	if (p == NULL)
	{
		ret.parent = l;
		ret.placement = 1;
		if (getkey(l->data) > getkey((node)))
			ret.placement = -1;
	}
	else if (getkey(p->data) > getkey(node))
		return find_placement(p->left, node, p);
	else if (getkey(p->data) < getkey(node))
		return find_placement(p->left, node, p);
	return ret;
}

binary_bool binary_tree_insert(binary_tree *tree, binary_node node)
{
	binary_tree_node *innode = malloc(sizeof(binary_tree_node));
	struct binary_placement location;
	int dsize, key;
	dsize = getsize_private(node);
	key =   getkey_private(node);
	innode->data = malloc(dsize);
	memcpy(innode->data, node, dsize);
	if (tree->root == NULL)
		tree->root = innode;
	else //find where it goes
	{
		location = find_placement(tree->root, node, tree->root);
		if (location.placement == 0)
			return BFALSE;
		else if (location.placement == 1) //right
			location.parent->right = innode;
		else if (location.placement == -1) //left
			location.parent->left = innode;
		else return BFALSE; //this should NEVER happen, but who knows
	}
	++tree->nitems;
	return BTRUE;
}


binary_bool binary_tree_remove(binary_tree *tree, binary_node node)
{
	struct binary_tree_search_private_struct r = binary_tree_search_private(tree->root, getkey_private(node), tree->root);
	binary_tree *t = binary_tree_alloc();
	if (r.node == NULL) return BFALSE; //not exist
	if (r.node == tree->root) return BFALSE; //attempting to delete whole tree, when should use binary_tree_free instead
	t->root = r.node;
	binary_tree_free(t);
	return BTRUE; //for some reason, it got fucked
}

//
//  tree.h
//  binary
//
//  Created by Ethan Laur on 3/17/14.
//  Copyright (c) 2014 Ethan Laur. All rights reserved.
//

#ifndef binary_tree_h
#define binary_tree_h

typedef struct binary_tree_node
{
	binary_node *data;
	struct binary_tree_node *left, *right;
} binary_tree_node;

typedef struct binary_tree
{
	void *root;
	int nitems;
} binary_tree;

#endif

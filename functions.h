//
//  functions.h
//  binary
//
//  Created by Ethan Laur on 3/17/14.
//  Copyright (c) 2014 Ethan Laur. All rights reserved.
//

#ifndef binary_functions_h
#define binary_functions_h

#include "node.h"
#include "tree.h"

typedef enum binary_bool { BFALSE, BTRUE } binary_bool;

binary_tree * binary_tree_alloc (void         );
void          binary_tree_free  (binary_tree *);
void          binary_tree_init  (binary_tree *);
binary_bool   binary_tree_insert(binary_tree *, binary_node);
binary_bool   binary_tree_remove(binary_tree *, binary_node);
binary_node   binary_tree_search(binary_tree *, int);

#define binary_tree_getkey(a)  (((char *)a))
#define binary_tree_getdata(a) (((char *)a + (2 * sizeof(int))))

#ifdef __binary_functions_private_h__
	struct binary_tree_search_private_struct
	{
		binary_tree_node *node, *parent;
	};
	struct binary_tree_search_private_struct binary_tree_search_private(binary_tree_node *, int,
														   binary_tree_node *);
	#define getkey_private(a)  (*(int *)binary_tree_getkey(a))
	#define getdata_private(a) (*(int *)binary_tree_getdata(a))
	#define getsize_private(a) (*(int *)binary_tree_getkey(a + sizeof(int)))
#endif

#endif

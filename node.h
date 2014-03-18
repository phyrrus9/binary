//
//  node.h
//  binary
//
//  Created by Ethan Laur on 3/17/14.
//  Copyright (c) 2014 Ethan Laur. All rights reserved.
//

/*
 node must be the following:
 a struct: where the first si bytes are the ID
           the second si bytes must be the size of the struct
		 the rest can be data
		 where si is sizeof(int)
 */

#ifndef binary_node_h
#define binary_node_h

typedef void * binary_node;
#define binary_node_id(a)   ((void *)((char *)(a)+0))
#define binary_node_size(a) ((void *)((char *)(a)+sizeof(int)))

#endif

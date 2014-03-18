#include "../binary.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
struct testnode
{
	int key;
	int size;
	char data[32];
};

int main(int argc, char * * argv)
{
	struct testnode n;
	int i;
	binary_tree *t;
	binary_node g;
	n.size = sizeof(struct testnode);
	t = binary_tree_alloc();
	binary_tree_init(t);
	for (i = 1; i < argc; i++)
	{
		n.key = i - 1;
		strcpy(n.data, argv[i]);
		binary_tree_insert(t, &n);
		g = binary_tree_search(t, i - 1);
		if (g == NULL) printf("Not found\n");
		else
		printf("Key: %d\tData: %s\n",
			*(int *)binary_tree_getkey(g),
			binary_tree_getdata(g)
		);
	}
	printf("Done!\n");
}

#include "binary_trees.h"

/**
 * create_node - create binary tree node
 * @n: value of node
 * @par: pointer to parent node
 *
 * Return: newly created node
 */
avl_t *create_node(int n, avl_t *par)
{
	avl_t *new = malloc(sizeof(*new));

	if (!new)
		return (NULL);
	new->n = n;
	new->parent = par;
	new->left = NULL;
	new->right = NULL;
	return (new);
}

/**
 * binary_traversal - traverse array in binary search pattern and create nodes
 * @par: pointer to parent node
 * @a: array of node values
 * @l: left index
 * @r: right index
 *
 * Return: final created node, NULL on malloc failure
 */
avl_t *binary_traversal(avl_t *par, int *a, int l, int r)
{
	avl_t *new;
	int m;

	if (l > r)
		return (NULL);
	m = (l + r) / 2;
	new = create_node(a[m], par);
	if (!new)
		return (NULL);
	new->left = binary_traversal(new, a, l, m - 1);
	new->right = binary_traversal(new, a, m + 1, r);
	return (new);
}

/**
 * sorted_array_to_avl - build AVL tree from array
 * @array: pointer to first element of array
 * @size: size of array
 *
 * Return: pointer to root node of created tree, NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	return (binary_traversal(NULL, array, 0, size - 1));
}

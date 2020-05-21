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
 * @root: double pointer to root node
 * @par: pointer to parent node
 * @a: array of node values
 * @m: middle index
 * @l: left index
 * @r: right index
 * @dir: specifies direction of child node to create, can be 'l' or  'r'
 *
 * Return: final created node, NULL on malloc failure
 */
avl_t *binary_traversal(avl_t **root, avl_t *par, int *a, int m, int l, int r,
		char dir)
{
	if (l > r)
		return (par);
	m = (l + r) / 2;
	if (dir == 'l')
		par = par->left = create_node(a[m], par);
	else if (dir == 'r')
		par = par->right = create_node(a[m], par);
	else
		par = *root = create_node(a[m], *root);
	if (!par)
	{
		*root = NULL;
		return (*root);
	}
	binary_traversal(root, par, a, m, l, m - 1, 'l');
	binary_traversal(root, par, a, m, m + 1, r, 'r');
	return (par);
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
	avl_t *root = NULL, *node = NULL;

	binary_traversal(&root, node, array, (0 + size - 1) / 2, 0, size - 1,
			'\0');
	return (root);
}

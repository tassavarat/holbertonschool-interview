#include "binary_trees.h"

/**
 * avl_check - check if BST and balance properties are satisfied
 * @node: pointer to root node of tree to check
 * @min: min range value node->n must be greater than
 * @max: max range value node->n must be less than
 * @height: current height of tree
 *
 * Return: 1 if valid AVL tree, 0 if not
 */
int avl_check(const binary_tree_t *node, int min, int max, int *height)
{
	int height_l, height_r;

	height_r = height_l = 0;
	if (!node)
		return (1);
	if (node->n <= min || node->n >= max)
		return (0);
	if (!avl_check(node->left, min, node->n, &height_l) ||
			!avl_check(node->right, node->n, max, &height_r))
		return (0);
	*height = (height_l > height_r ? height_l : height_r) + 1;
	return (abs(height_l - height_r) < 2);
}

/**
 * binary_tree_is_avl - check if binary tree is a valid AVL tree
 * @tree: pointer to root node of tree to check
 *
 * Return: 1 if valid AVL tree, 0 if not
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int height = 0;

	if (!tree)
		return (0);
	return (avl_check(tree, INT_MIN, INT_MAX, &height));
}

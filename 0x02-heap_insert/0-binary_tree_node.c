#include "binary_trees.h"

/**
 * binary_tree_node - creates a binary tree node
 * @parent: pointer to parent node of node to create
 * @value: value ot put in the new node
 *
 * Return: pointer to new node, NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new = malloc(sizeof(*new));

	if (!new)
		return (NULL);
	new->n = value;
	if (!parent)
		new->parent = NULL;
	else
		new->parent = parent;
	new->left = NULL;
	new->right = NULL;
	return (new);
}

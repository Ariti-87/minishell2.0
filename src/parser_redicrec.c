/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_redicrec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arincon <arincon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:36:39 by arincon           #+#    #+#             */
/*   Updated: 2023/10/17 10:50:42 by arincon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include "minishell.h"
void	ft_parser_redirec(t_data *data, t_token *list)
{

}

void	ft_split_node(t_token *head, char *str)
{
	char	*space_pos = ft_strchr(str, ' ')

	if (space_pos == NULL)
		return ;

}

void split_string(t_token *head, const char *input) {
    // Recherche de l'emplacement du premier espace
    const char *space_pos = strchr(input, ' ');

    if (space_pos == NULL) {
        // Si aucun espace n'est trouvé, tout le texte est dans le premier nœud
        head->str = strdup(input);
        head->type = ALPHANUM; // Ou SEPARATOR, selon vos besoins
    } else {
        // Allouer le premier nœud et copier la première partie de la chaîne
        head->str = strndup(input, space_pos - input);
        head->type = ALPHANUM; // Ou SEPARATOR, selon vos besoins

        // Allouer le deuxième nœud et copier la deuxième partie de la chaîne
        t_token *second_node = ft_token((char *)space_pos + 1, '\0');
        second_node->type = ft_type_token(space_pos[1]);

        // Mettre à jour les pointeurs next
        head->next = second_node;
    }
}

int main() {
    t_token *head = ft_token(NULL, '\0');
    const char *input = "Premier mot Deuxième mot";

    split_string(head, input);

    // Afficher les nœuds
    t_token *current = head;
    while (current != NULL) {
        printf("Type: %d, String: %s\n", current->type, current->str);
        current = current->next;
    }

    // Libérer la mémoire
    current = head;
    while (current != NULL) {
        t_token *temp = current;
        current = current->next;
        free(temp->str);
        free(temp);
    }

    return 0;
 */

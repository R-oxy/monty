#include "monty.h"

/**
 * main - main function of monty program
 * @argc: number of arguments
 * @argv: pointer to array of strings of arguments
 * Return: 0 on success, -1 on failure
 */
int main(int argc, char *argv[])
{
	FILE *fp;
	stack_t *stack = NULL;
	char *line = NULL;
	char *opcode;
	char *n;
	unsigned int line_number;
	size_t len = 0;
	ssize_t read;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	line_number = 0;
	while ((read = custom_getline(&line, &len, fp)) != -1)
	{
		line_number++;
		opcode = strtok(line, DELIMITERS);
		if (opcode == NULL || strncmp(opcode, "#", 1) == 0)
			continue;
		if (strcmp(opcode, "push") == 0)
		{
			n = strtok(NULL, DELIMITERS);
			push(&stack, line_number, n);
		}
		else
			opcode_struct(opcode, &stack, line_number);
	}

	free_all(stack, line, fp);
	return (EXIT_SUCCESS);
}

/**
 * frees - To free the stack
 * @head: pointer to the stack
 * Return: nothing
 */
void frees(stack_t *head)
{
	stack_t *tmp;

	if (head == NULL)
		return;
	while (head->prev)
	{
		head = head->prev;
	}

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

/**
 * custom_getline - Read a line from a file
 * @lineptr: Pointer to the buffer where the line will be stored
 * @n: Pointer to the variable that holds the size of the buffer
 * @stream: File stream to read from
 * Return: Number of characters read, or -1 on failure
 */
ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream)
{
	char *buffer = NULL;
	size_t buffer_size = 0;
	ssize_t read = 0;
	int c;
	char *new_ptr = realloc(buffer, buffer_size);

	if (lineptr == NULL || n == NULL || stream == NULL)
	{
		return (-1);
	}

	while ((c = fgetc(stream)) != EOF)
	{
		if ((size_t)(read + 1) >= buffer_size)
		{
			buffer_size += 128;
			if (new_ptr == NULL)
			{
				free(buffer);
				return (-1);
			}
			buffer = new_ptr;
		}
		buffer[read] = c;
		read++;

		if (c == '\n')
			break;
	}

	if (read == 0)
	{
		free(buffer);
		return (-1);
	}

	buffer[read] = '\0';
	*lineptr = buffer;
	*n = buffer_size;

	return (read);
}

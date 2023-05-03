#include "brainfrick.h"

int memory_cells[MEMORY_CELLS] = {0};
size_t p = 0;

char *load_source(const char *path)
{
    char *buffer = 0;
    long length;
    FILE *f = fopen(path, "rb");

    if (f)
    {
        fseek(f, 0, SEEK_END);
        length = ftell(f);
        fseek(f, 0, SEEK_SET);
        buffer = (char *)malloc((length + 1) * sizeof(char));
        if (buffer)
        {
            fread(buffer, sizeof(char), length, f);
        }
        fclose(f);
    }
    buffer[length] = '\0';

    return buffer;
}

void decode_execute(const char *source)
{
    size_t program_length = strlen(source);
    char instruction;

    for (size_t i = 0; i < program_length; i++)
    {
        instruction = source[i];
        switch (instruction)
        {
        case '>': 
            move_pointer_right();
            break;
        case '<':
            move_pointer_left();
            break;
        case '+':
            inc_mem_cell();
            break;
        case '-':
            dec_mem_cell();
            break;
        case '.':
            ouput_char();
            break;
        case ',':
            input_char();
            break;
        case '[':
            i = jump_forward(source, i);
            break;
        case ']':
            i = jump_back(source, i);
            break;
        default:
            break;
        }
    }
}

void move_pointer_right() 
{ 
    p++; 
}

void move_pointer_left() 
{ 
    p--; 
}

void inc_mem_cell() 
{ 
    memory_cells[p]++; 
}

void dec_mem_cell() 
{ 
    memory_cells[p]--; 
}

void ouput_char() 
{ 
    printf("%c", memory_cells[p]); 
}

void input_char()
{
    char c;
    scanf("%c", &c);
    memory_cells[p] = c;
}

size_t jump_forward(const char *source, size_t index)
{
    size_t i = index;
    if (memory_cells[p] == 0)
    {
        size_t counter = 1;
        while (counter != 0)
        {
            i++;

            if (source[i] == '[')
            {
                counter++;
            }
            else if (source[i] == ']')
            {
                counter--;
            }
        }

        return i;
    }

    return i;
}

size_t jump_back(const char *source, size_t index)
{
    size_t i = index;
    if (memory_cells[p] != 0)
    {
        size_t counter = 1;
        while (counter != 0)
        {
            i--;
            
            if (source[i] == '[')
            {
                counter--;
            }
            else if (source[i] == ']')
            {
                counter++;
            }
        }
    }

    return i;
}
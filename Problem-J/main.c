#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *names[16] = {"NULL", "STOP", "LOAD", "STORE", "JUMP", "JNEG", "JZERO", "",
                   "ADD", "SUB", "SHL", "SHR", "AND", "OR", "NOT", "XOR"};

short memory[512];
short ac;
int pc;
int running;

int get(int address)
{
    if (address < 0 || address > 511) {
        running = 0;
        return 0;
    }
    return memory[address];
}

void read_cell()
{
    int index, address, opcode, mode, i;
    char word[32], symbol;
    scanf("%d:", &index);
    scanf("%31s", word);
    if (word[0] == '-' || word[0] == '+' || (word[0] >= '0' && word[0] <= '9')) {
        memory[index] = atoi(word);
    } else {
        scanf(" %c%d", &symbol, &address);
        opcode = 0;
        for (i = 0; i < 16; i++) {
            if (strcmp(word, names[i]) == 0) opcode = i;
        }
        mode = 0;
        if (symbol == '@') mode = 1;
        if (symbol == '*') mode = 2;
        if (symbol == '+') mode = 3;
        if (address < 0) memory[index] = 32768 + opcode * 2048 + mode * 512 - address;
        else memory[index] = opcode * 2048 + mode * 512 + address;
    }
    while (getchar() != '\n');
}

void step()
{
    unsigned short word;
    int opcode, mode, address, operand;
    if (pc < 0 || pc > 511) {
        running = 0;
        return;
    }
    word = memory[pc];
    pc++;
    opcode = (word >> 11) & 15;
    mode = (word >> 9) & 3;
    address = word & 511;
    if (word >> 15) address = -address;
    if (mode == 0) operand = address;
    else if (mode == 1) operand = get(address);
    else if (mode == 2) operand = get(get(address));
    else operand = get(ac + address);
    if (!running) return;
    if (opcode == 1) running = 0;
    else if (opcode == 2) ac = operand;
    else if (opcode == 3) {
        if (operand < 0 || operand > 511) running = 0;
        else memory[operand] = ac;
    }
    else if (opcode == 4) pc = operand;
    else if (opcode == 5 && ac < 0) pc = operand;
    else if (opcode == 6 && ac == 0) pc = operand;
    else if (opcode == 8) ac = ac + operand;
    else if (opcode == 9) ac = ac - operand;
    else if (opcode == 10) ac = (operand < 0 || operand > 15) ? 0 : (unsigned short)ac << operand;
    else if (opcode == 11) ac = (operand < 0 || operand > 15) ? (ac < 0 ? -1 : 0) : ac >> operand;
    else if (opcode == 12) ac = ac & operand;
    else if (opcode == 13) ac = ac | operand;
    else if (opcode == 14) ac = ~ac;
    else if (opcode == 15) ac = ac ^ operand;
}

int main()
{
    int z, n, k, i, index;
    scanf("%d", &z);
    while (z--) {
        memset(memory, 0, sizeof(memory));
        ac = 0;
        pc = 0;
        running = 1;
        scanf("%d %d", &n, &k);
        while (getchar() != '\n');
        for (i = 0; i < n; i++) read_cell();
        while (running) step();
        for (i = 0; i < k; i++) {
            scanf("%d", &index);
            printf(i ? " %d" : "%d", memory[index & 511]);
        }
        printf("\n");
    }
    return 0;
}
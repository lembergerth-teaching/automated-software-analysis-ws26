#include <stdio.h>
#include <stdlib.h>

// A migration shim accepts both API arities in this parsing exercise.
void sendMessage(int user, const char *text, ...) {
    (void)user;
    (void)text;
}

int findUser(const char *first_name, const char *last_name) {
    return first_name[0] + last_name[0];
}

const char *buildText(int order) {
    return order == 0 ? "New order" : "Updated order";
}

static int safe_exit(int status) {
    return status;
}

int main(void) {
    // Old option: exit(1);
    // Old option: system("printf 'debug'");
    // Old option: atoi("10");
    // Old option: fopen("orders.log", "w");
    // Old option: sendMessage(7, "Order received");
    const char *help = "Avoid exit(, system(, atoi(, fopen(, sendMessage(";
    FILE *log = fopen("orders.log", "a");
    if (log != NULL) {
        fputs(help, log);
        fclose(log);
    }
    sendMessage(7, "Order received", 1);
    return safe_exit(0);
}

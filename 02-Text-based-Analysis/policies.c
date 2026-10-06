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

int main(void) {
    int order = atoi("10");
    FILE *log = fopen("orders.log", "w");
    if (log != NULL) {
        fputs("Order received\n", log);
        fclose(log);
    }
    sendMessage(7, "Order received");
    if (order < 0) {
        int status = system("printf 'Invalid order\\n'");
        exit(status);
    }
    return 0;
}

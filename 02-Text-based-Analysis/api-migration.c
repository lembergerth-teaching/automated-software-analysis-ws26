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
    const char *first_name = "Max";
    const char *last_name = "Trautner";
    int order = 10;

    sendMessage(findUser(first_name, last_name), buildText(order));
    sendMessage(findUser(first_name, last_name), buildText(order), 1);
    return 0;
}

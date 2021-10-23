#include "db.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

void expect(char *msg, int expr) {
    printf("%s\n", msg);
    assert(expr);
}

int main() {
    /* setup */
    char *filename = "test.db";
    db_t *db = create_db(filename);
    int res;

    db_item_t item1 = { Safe };
    res = set_item(db, "test.com", &item1);
    expect("can set value", res == 0);

    expect("can retrieve value", get_item(db, "test.com").rating == item1.rating);

    expect("can save db", save_db(db) == 0);

    db = load_db(filename);
    expect("can load values from saved db", get_item(db, "test.com").rating == item1.rating);

    /* cleanup */
    remove(filename);
    free(db);

    return 0;
}


#include "Drawer.h"

int main()
{
    Field field;
    Drawer d(&field);

    field.addParticle(55, 25, 200);
    field.addParticle(155, 35, -200);
    field.addParticle(255, 145, 200);
    field.addParticle(456, 145, -400);

    d.run();

    return 0;
}
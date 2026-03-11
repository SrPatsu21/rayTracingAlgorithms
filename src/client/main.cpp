#include "rtweekend.h"

#include "hittable.h"
#include "hittable_list.h"
#include "triangle.h"
#include "camera.h"

int main() {

    // World
    hittable_list world;

    world.add(make_shared<triangle>(
        point3(-0.5, -0.5, -1),
        point3(0, 0.5, -1),
        point3(0.5, -0.5, -1)
    ));

    camera cam;

    cam.aspect_ratio = 16.0 / 9.0;
    cam.image_width = 800;
    cam.samples_per_pixel = 16;

    cam.render(world);
}
#include "rtweekend.h"

#include "hittable.h"
#include "hittable_list.h"
#include "sphere.h"
#include "triangle.h"
#include "camera.h"

int main() {

    // Image

    auto aspect_ratio = 16.0 / 9.0;
    int image_width = 400;

    // Calculate the image height, and ensure that it's at least 1.
    int image_height = int(image_width / aspect_ratio);
    image_height = (image_height < 1) ? 1 : image_height;

    // World

    hittable_list world;

    // world.add(make_shared<sphere>(point3(0, 0, -1), 0.5));
    world.add(make_shared<sphere>(point3(0, -50.5, -1), 50));
    world.add(make_shared<triangle>(
        point3(-1, 1, -3),
        point3(0, 2, -3),
        point3(1, 1, -3)
    ));

    world.add(make_shared<triangle>(
            point3(-1, -1, -3),
            point3(1, -1, -3),
            point3(1, 1, -3)
        )
    );
    world.add(make_shared<triangle>(
            point3(-1, -1, -3),
            point3(1, 1, -3),
            point3(-1, 1, -3)
        )
    );

    camera cam;

    cam.aspect_ratio = 16.0 / 9.0;
    cam.image_width  = 400;

    cam.render(world);
}
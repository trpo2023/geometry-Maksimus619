#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 10

typedef struct {
int x;
int y;
} Point;

typedef struct {
Point points[MAX_POINTS];
int num_points;
} Polygon;

double get_distance(Point p1, Point p2) {
int dx = p2.x - p1.x;
int dy = p2.y - p1.y;
return sqrt(dx*dx + dy*dy);
}

double get_perimeter(Polygon *polygon) {
double perimeter = 0;
int i;
for (i = 0; i < polygon->num_points; i++) {
int j = (i + 1) % polygon->num_points;
perimeter += get_distance(polygon->points[i], polygon->points[j]);
}
return perimeter;
}

double get_area(Polygon *polygon) {
double area = 0;
int i;
for (i = 0; i < polygon->num_points; i++) {
int j = (i + 1) % polygon->num_points;
area += polygon->points[i].x * polygon->points[j].y -
polygon->points[j].x * polygon->points[i].y;
}
return fabs(area / 2.0);
}

void print_polygon(Polygon *polygon) {
int i;
for (i = 0; i < polygon->num_points; i++) {
printf("(%d,%d)", polygon->points[i].x, polygon->points[i].y);
if (i < polygon->num_points - 1) {
printf("->");
}
}
printf("\n");
}

Polygon read_polygon_from_file(char *filename) {
FILE *file;
Polygon polygon = { .num_points = 0 };
file = fopen(filename, "r");
if (file == NULL) {
printf("Unable to open file %s\n", filename);
exit(EXIT_FAILURE);
}
while (fscanf(file, "%d %d", &polygon.points[polygon.num_points].x, &polygon.points[polygon.num_points].y) == 2) {
polygon.num_points++;
if (polygon.num_points >= MAX_POINTS) {
printf("Polygon has too many points\n");
exit(EXIT_FAILURE);
}
}
fclose(file);
return polygon;
}

int main(int argc, char *argv[]) {
if (argc < 2) {
printf("Usage: %s <filename>\n", argv[0]);
exit(EXIT_FAILURE);
}
Polygon polygon = read_polygon_from_file(argv[1]);
printf("Polygon: ");
print_polygon(&polygon);
printf("Perimeter: %.2f\n", get_perimeter(&polygon));
printf("Area: %.2f\n", get_area(&polygon));
return 0;
}

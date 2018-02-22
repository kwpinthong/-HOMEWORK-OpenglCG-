#include <GL/glut.h>
#include <math.h>
static GLfloat dx1 = 0.0, dx2 = 0.0, dx3 = 0.0, dx4 = 0.0;
static GLfloat a = 0.0;
static GLfloat r = 0.43, g = 0.43, b = 0.43;
static GLfloat r1 = 0.0, g1 = 0.0, b1 = 0.0;
static GLfloat r2 = 0.0, g2 = 0.0, b2 = 0.0;
static GLfloat r3 = 0.0, g3 = 0.0, b3 = 0.0;
static GLfloat ry1 = 0.0;
static GLfloat flowerWind = 0.0090;
static GLfloat smoke = 0.0, smoke2 = 0.0;
int random, random1, random2;
int rain;
int starchange;
int time;
void init(void){
	glClearColor(0.0, 0.0, 0.0, 1.0);
}
void circle(float r, float x1, float y1){
	float x, y;
	glBegin(GL_POLYGON);
	for (int i = 0; i <= 360; i++) {
		x = r * cos(i);
		y = r * sin(i);
		glVertex2f(x + x1, y + y1);
	}
	glEnd();
}
void ellipas(float a, float b, float x1, float y1, float ar){
	float x, y, xr, yr;
	glBegin(GL_POLYGON);
	for (int i = 0; i <= 360; i++) {
		x = a * cos(i);
		y = b * sin(i);
		xr = -(x * cos(ar) + y * sin(ar));
		yr = x * sin(ar) - y * cos(ar);
		glVertex2f(xr + x1, yr + y1);
	}
	glEnd();
}
void line(float x1, float y1,float ar){
	float xr, yr;
	glLineWidth(10);
	glColor3f(0.0, 0.09, 0.0);
	glBegin(GL_LINES);
	glVertex2f(x1, -0.5);
	glVertex2f(x1 + ar, y1);
	glEnd();
}
void flower(float r, float x1, float y1,float ar){
	float x, y, xr, yr;
	line(x1, y1, -ar);
	glColor3f(0.86, 0.73, 0.0);
	glBegin(GL_POLYGON_BIT);
	for(int i = 0; i <= 360; i++) {
		x = r * cos(8 * i) * cos(i);
		y = r * cos(8 * i) * sin(i);
		glVertex2f(x + x1 - ar, y + y1);
	}
	glEnd();
	glColor3f(0.06, 0.03, 0.0);
	circle(r/2, x1 - ar, y1);
}
void night(){
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(-1, -0.5);
	glColor3f(0.035, 0.054, 0.086);
	glVertex2f(-1, 1);
	glColor3f(0.0, 0.156, 0.4);
	glVertex2f(1, 1);
	glColor3f(0.027, 0.156, 0.352);
	glVertex2f(1, -0.5);
	glEnd();
}
void star(){
	float r = 0.01;
	if (starchange <= 35) {
		glColor3f(1, 1, 1);
	}
	else {
		glColor3f(0.941, 1, 0.521);
	}
	circle(r, 0.5, 0.87);
	circle(r, -0.1, 0.6);
	circle(r, -0.15, 0.9);
	circle(r, -0.2, 0.4);
	circle(r, -0.25, 0.84);
	circle(r, -0.3, 0.55);
	circle(r, -0.35, 0.35);
	circle(r, -0.4, 0.59);
	circle(r, -0.45, 0.35);
	circle(r, -0.5, 0.65);
	circle(r, -0.55, 0.87);
	circle(r, -0.6, 0.75);
	circle(r, -0.65, 0.63);
	circle(r, -0.7, 0.41);
	circle(r, -0.75, 0.62);
	circle(r, -0.8, 0.53);
	circle(r, -0.85, 0.72);
	circle(r, -0.9, 0.85);
	circle(r, -0.5, 0.86);
	circle(r, 0.0, 0.79);
	circle(r, 0.1, 0.66);
	circle(r, 0.2, 0.81);
	circle(r, 0.3, 0.39);
	circle(r, 0.35, 0.61);
	circle(r, 0.4, 0.54);
	circle(r, 0.5, 0.65);
	circle(r, 0.5, 0.81);
	circle(r, 0.6, 0.75);
	circle(r, 0.7, 0.85);
	circle(r, 0.8, 0.92);
	circle(r, 0.9, 0.77);
}
void daytime()
{
	glBegin(GL_POLYGON);
	glColor3f(0.635, 0.647, 0.662);
	glVertex2f(-1, -0.5);
	glColor3f(0, 0.368, 0.941);
	glVertex2f(-1, 1);
	glColor3f(0.258, 0.552, 1);
	glVertex2f(1, 1);
	glColor3f(0.423, 0.435, 0.458);
	glVertex2f(1, -0.5);
	glEnd();
}
void smallWindow(int n)
{
	float r = 0.025;
	glBegin(GL_POLYGON);
	glVertex2f(0.5 + 0.03 + n * r, -0.23 + 0.08);
	glVertex2f(0.5 + 0.03 + n * r, -0.28 + 0.08);
	glVertex2f(0.5 + 0.045 + n * r, -0.28 + 0.08);
	glVertex2f(0.5 + 0.045 + n * r, -0.23 + 0.08);
	glEnd();
}
void fence(int n)
{
	float i = 0.08;
	glBegin(GL_POLYGON);
	glVertex2f(-1 + n * i, -0.1 - 0.4);
	glVertex2f(-1 + n * i, 0.1 - 0.4);
	glVertex2f(-0.95 + n * i, 0.1 - 0.4);
	glVertex2f(-0.95 + n * i, -0.1 - 0.4);
	glEnd();
	//สายบน
	glLineWidth(100);
	glBegin(GL_LINES);
	glVertex2f(-1.0, -0.38);
	glVertex2f(1.0, -0.38);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-1.0, -0.39);
	glVertex2f(1.0, -0.39);
	glEnd();
	//สายล่าง
	glBegin(GL_LINES);
	glVertex2f(-1.0, -0.45);
	glVertex2f(1.0, -0.45);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-1.0, -0.44);
	glVertex2f(1.0, -0.44);
	glEnd();
}
void house(float r,float g, float b)
{
	float x1 = 0.0, x2 = 0.7;
	float y1 = -0.5, y2 = 0;

	//Sunflower gardan
	flower(0.08, 1, -0.16, flowerWind);
	flower(0.075, 0.9, -0.08, flowerWind);
	flower(0.06, 0.8, -0.2, flowerWind);
	flower(0.068, 0.9, -0.25, flowerWind);
	//howdy
	flower(0.09, 0.7, -0.1, flowerWind);
	glColor3f(1, 1, 1);
	circle(0.09 / 20, 0.73 - flowerWind, -0.1);
	glLineWidth(1);
	glBegin(GL_LINES);
	glVertex2f(0.69 - flowerWind, -0.11);
	glVertex2f(0.72 - flowerWind, -0.11);
	glEnd();
	//
	flower(0.05, -0.07, -0.18, flowerWind);
	flower(0.06, -0.2, -0.17, flowerWind);
	flower(0.07, -0.15, 0, flowerWind);
	flower(0.04, -0.13, -0.27, flowerWind);
	flower(0.07, -0.3, -0.1, flowerWind);
	flower(0.07, -0.4, -0.2, flowerWind);
	flower(0.07, -0.5, -0.08, flowerWind);
	flower(0.04, -0.56, -0.25, flowerWind);
	flower(0.06, -0.62, -0.15, flowerWind);
	flower(0.06, -0.7, -0.2, flowerWind);
	flower(0.08, -0.8, -0.1, flowerWind);
	flower(0.08, -0.9, -0.15, flowerWind);
	//Long Fence
	for (int i = 0; i <= 30; i++) {
		glColor3f(0.11, 0.08, 0.0);
		fence(i);
	}

	//house
	glBegin(GL_POLYGON);
	glColor3f(0.14, 0.16, 0.34);
	glVertex2f(x1, y1);
	glVertex2f(x1, y2);
	glVertex2f(x2, y2);
	glVertex2f(x2, y1);
	glEnd();

	//ป่องไฟบ้าน
	glColor3f(0.0, 0.0, 0.21);
	glBegin(GL_POLYGON);
	glVertex2f(0.55, 0.0);
	glVertex2f(0.55, 0.3);
	glVertex2f(0.65, 0.3);
	glVertex2f(0.65, 0.0);
	glEnd();

	//ขอบป่องไฟบ้าน
	glColor3f(0.0, 0.0, 0.5);
	glBegin(GL_POLYGON);
	glVertex2f(0.53, 0.3);
	glVertex2f(0.53, 0.35);
	glVertex2f(0.67, 0.35);
	glVertex2f(0.67, 0.3);
	glEnd();
	
	//smoke
	float s1 = 0.5 / 8;
	float s2 = 0.2/8;
	glColor3f(0.858, 0.858, 0.858);
	if (smoke <= 30)
		ellipas(s1, s2, 0.63, 0.39,0);
	else if (smoke <= 60)
		ellipas(s1 + 0.02, s2 + 0.02, 0.67, 0.43, 0);
	else if (smoke <= 90)
		ellipas(s1 + 0.04, s2 + 0.04, 0.69, 0.48, 0);

	//หลังคา
	glColor3f(0.0, 0.0, 0.21);
	glBegin(GL_POLYGON);
	glVertex2f(-0.05, 0.3 - 0.3);
	glVertex2f(0.1, 0.5 - 0.3);
	glVertex2f(0.6, 0.5 - 0.3);
	glVertex2f(0.75, 0.3 - 0.3);
	glEnd();

	//ขอบประตู
	glColor3f(0.20, 0.09, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(0.48, y1);
	glVertex2f(0.48, 0.23 - 0.3);
	glVertex2f(0.67, 0.23 - 0.3);
	glVertex2f(0.67, y1);
	glEnd();

	//Door
	glColor3f(0.29, 0.16, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(0.5, y1);
	glVertex2f(0.5, 0.2 - 0.3);
	glVertex2f(0.65, 0.2 - 0.3);
	glVertex2f(0.65, y1);
	glEnd();

	//small window
	for (int i = 0; i <= 3; i++) {
		glColor3f(0.6, 0.6, 0.6);
		smallWindow(i);
	}
	glColor3f(0.6, 0.6, 0.6);
	circle(0.01, 0.63, 0.2 - 0.35 - 0.15);

	//ขอบหน้าต่าง
	glColor3f(0.20, 0.09, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(0.1 - 0.02, 0.05 - 0.35);
	glVertex2f(0.1 - 0.02, 0.2 - 0.3);
	glVertex2f(0.2 + 0.02, 0.2 - 0.3);
	glVertex2f(0.2 + 0.02, 0.05 - 0.35);
	glEnd();

	//window
	glColor3f(r, g, b);
	glBegin(GL_POLYGON);
	glVertex2f(0.1, 0.05 - 0.35);
	glVertex2f(0.1, 0.2 - 0.3);
	glVertex2f(0.2, 0.2 - 0.3);
	glVertex2f(0.2, 0.05 - 0.35);
	glEnd();

	//ขอบหน้าต่าง2
	glColor3f(0.20, 0.09, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(0.3 - 0.02, 0.05 - 0.35);
	glVertex2f(0.3 - 0.02, 0.2 - 0.3);
	glVertex2f(0.4 + 0.02, 0.2 - 0.3);
	glVertex2f(0.4 + 0.02, 0.05 - 0.35);
	glEnd();

	//window2
	glColor3f(r, g, b);
	glBegin(GL_POLYGON);
	glVertex2f(0.3, 0.05 - 0.35);
	glVertex2f(0.3, 0.2 - 0.3);
	glVertex2f(0.4, 0.2 - 0.3);
	glVertex2f(0.4, 0.05 - 0.35);
	glEnd();

	//พื้นดิน
	glBegin(GL_POLYGON);
	glColor3f(0.16, 0.08, 0.0);
	glVertex2f(-1, -0.1 - 0.4);
	glVertex2f(-1, -1);
	glVertex2f(1, -1);
	glVertex2f(1, -0.1 - 0.4);
	glEnd();
}
void car(float x1, float y1, float r, float g, float b)
{
	//ตัวรถ
	glColor3f(r, g, b);
	glBegin(GL_POLYGON);
	glVertex2f(0.1 + x1, -0.9 + y1);
	glVertex2f(0.1 + x1, -0.7 + y1);
	glVertex2f(0.35 + x1, -0.65 + y1);
	glVertex2f(0.45 + x1, -0.55 + y1);
	glVertex2f(0.65 + x1, -0.55 + y1);
	glVertex2f(0.6 + x1, -0.4 + y1);
	glVertex2f(0.9 + x1, -0.4 + y1);
	glVertex2f(0.9 + x1, -0.9 + y1);
	glVertex2f(0.6 + x1, -0.9 + y1);
	glVertex2f(0.6 + x1, -0.6 + y1);
	glVertex2f(1.3 + x1, -0.6 + y1);
	glVertex2f(1.3 + x1, -0.9 + y1);
	glEnd();

	//ท่อรถ
	glBegin(GL_POLYGON);
	glColor3f(0.439, 0.439, 0.439);
	glVertex2f(1.35 + x1, -0.9 + y1);
	glColor3f(0.211, 0.211, 0.211);
	glVertex2f(1.3 + x1, -0.9 + y1);
	glColor3f(0.819, 0.8, 0.8);
	glVertex2f(1.3 + x1, -0.85 + y1);
	glVertex2f(1.35 + x1, -0.85 + y1);
	glEnd();

	//smoke
	float s1 = 0.5 / 14;
	float s2 = 0.2 / 14;
	glColor3f(0.329, 0.329, 0.329);
	if (smoke2 <= 3)
		ellipas(s1, s2, 1.41 + x1, -0.88 + y1, 0);
	else if (smoke2 <= 6)
		ellipas(s1 + 0.02, s2 + 0.02, 1.43 + x1, -0.86 + y1, 0);
	else if (smoke2 <= 9)
		ellipas(s1 + 0.04, s2 + 0.04, 1.45 + x1, -0.84 + y1, 0);


	//ไฟรถ
	glColor3f(0.6, 0.6, 0.6);
	glBegin(GL_POLYGON);
	glVertex2f(0.1 + x1, -0.83 + y1);
	glVertex2f(0.1 + x1, -0.75 + y1);
	glVertex2f(0.15 + x1, -0.75 + y1);
	glVertex2f(0.15 + x1, -0.83 + y1);
	glEnd();

	//กระจก
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.5, 0.5);
	glVertex2f(0.4 + x1, -0.65 + y1);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(0.6 + x1, -0.44 + y1);
	glVertex2f(0.7 + x1, -0.44 + y1);
	glColor3f(0.5, 0.5, 0.5);
	glVertex2f(0.7 + x1, -0.65 + y1);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(0.74 + x1, -0.65 + y1);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(0.74 + x1, -0.44 + y1);
	glVertex2f(0.87 + x1, -0.44 + y1);
	glColor3f(0.5, 0.5, 0.5);
	glVertex2f(0.87 + x1, -0.65 + y1);
	glEnd();

	//handประตู
	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.3, 0.3);
	glVertex2f(0.65 + x1, -0.75 + y1);
	glVertex2f(0.65 + x1, -0.7 + y1);
	glVertex2f(0.7 + x1, -0.7 + y1);
	glVertex2f(0.7 + x1, -0.75 + y1);
	glEnd();

	//ล้อรถ
	glColor3f(0.0, 0.0, 0.0);
	circle(0.11, 0.4 + x1, -0.9 + y1);
	circle(0.11, 1 + x1, -0.9 + y1);
	glColor3f(0.43, 0.43, 0.43);
	circle(0.11 / 1.5, 0.4 + x1, -0.9 + y1);
	circle(0.11 / 1.5, 1 + x1, -0.9 + y1);

	//ลายล้อรถ
	glColor3f(0.3, 0.3, 0.3);
	ellipas(0.005, 0.07, 0.4 + x1, -0.9 + y1, a);
	ellipas(0.07, 0.005, 0.4 + x1, -0.9 + y1, a);
	ellipas(0.005, 0.07, 1 + x1, -0.9 + y1, a);
	ellipas(0.07, 0.005, 1 + x1, -0.9 + y1, a);
}
class rainfall {
public:
	void draw(float x, float y, float p) {
		glLineWidth(1);
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_LINES);
		glVertex2f(0 + x + p, 1 - y);
		glVertex2f(0.02 + x + p, 0.95 - y);
		glEnd();
		glBegin(GL_LINES);
		glVertex2f(0.04 + x + p, 0.9 - y);
		glVertex2f(0.06 + x + p, 0.85 - y);
		glEnd();
		glBegin(GL_LINES);
		glVertex2f(0.08 + x + p, 0.8 - y);
		glVertex2f(0.1 + x + p, 0.75 - y);
		glEnd();
		glBegin(GL_LINES);
		glVertex2f(0.12 + x + p, 0.7 - y);
		glVertex2f(0.14 + x + p, 0.65 - y);
		glEnd();
		glBegin(GL_LINES);
		glVertex2f(0.16 + x + p, 0.6 - y);
		glVertex2f(0.18 + x + p, 0.55 - y);
		glEnd();
		glBegin(GL_LINES);
		glVertex2f(0.2 + x + p, 0.5 - y);
		glVertex2f(0.22 + x + p, 0.45 - y);
		glEnd();
		glBegin(GL_LINES);
		glVertex2f(0.24 + x + p, 0.4 - y);
		glVertex2f(0.26 + x + p, 0.35 - y);
		glEnd();
		glBegin(GL_LINES);
		glVertex2f(0.28 + x + p, 0.3 - y);
		glVertex2f(0.3 + x + p, 0.25 - y);
		glEnd();
		glBegin(GL_LINES);
		glVertex2f(0.32 + x + p, 0.2 - y);
		glVertex2f(0.34 + x + p, 0.15 - y);
		glEnd();
		glBegin(GL_LINES);
		glVertex2f(0.36 + x + p, 0.1 - y);
		glVertex2f(0.38 + x + p, 0.05 - y);
		glEnd();
		//--------------------//
		glBegin(GL_LINES);
		glVertex2f(0.4 + x + p, 0 - y);
		glVertex2f(0.42 + x + p, -0.05 - y);
		glEnd();
		glBegin(GL_LINES);
		glVertex2f(0.44 + x + p, -0.1 - y);
		glVertex2f(0.46 + x + p, -0.15 - y);
		glEnd();
		glBegin(GL_LINES);
		glVertex2f(0.48 + x + p, -0.2 - y);
		glVertex2f(0.5 + x + p, -0.25 - y);
		glEnd();
		glBegin(GL_LINES);
		glVertex2f(0.52 + x + p, -0.3 - y);
		glVertex2f(0.54 + x + p, -0.35 - y);
		glEnd();
		glBegin(GL_LINES);
		glVertex2f(0.56 + x + p, -0.4 - y);
		glVertex2f(0.58 + x + p, -0.45 - y);
		glEnd();
		glBegin(GL_LINES);
		glVertex2f(0.6 + x + p, -0.5 - y);
		glVertex2f(0.62 + x + p, -0.55 - y);
		glEnd();
		glBegin(GL_LINES);
		glVertex2f(0.64 + x + p, -0.6 - y);
		glVertex2f(0.66 + x + p, -0.65 - y);
		glEnd();
		glBegin(GL_LINES);
		glVertex2f(0.68 + x + p, -0.7 - y);
		glVertex2f(0.7 + x + p, -0.75 - y);
		glEnd();
		glBegin(GL_LINES);
		glVertex2f(0.72 + x + p, -0.8 - y);
		glVertex2f(0.74 + x + p, -0.85 - y);
		glEnd();
		glBegin(GL_LINES);
		glVertex2f(0.76 + x + p, -0.9 - y);
		glVertex2f(0.78 + x + p, -0.95 - y);
		glEnd();
		glBegin(GL_LINES);
		glVertex2f(0.8 + x + p, -1 - y);
		glVertex2f(0.82 + x + p, -1.05 - y);
		glEnd();
	}
};
void raining()
{
	rainfall test;
	test.draw(ry1, ry1, 0);
	test.draw(ry1, ry1, 0.1);
	test.draw(ry1, ry1, 0.2);
	test.draw(ry1, ry1, 0.3);
	test.draw(ry1, ry1, 0.4);
	test.draw(ry1, ry1, 0.5);
	test.draw(ry1, ry1, 0.6);
	test.draw(ry1, ry1, 0.7);
	test.draw(ry1, ry1, 0.8);
	test.draw(ry1, ry1, 0.9);
	test.draw(ry1, ry1, 1);
	test.draw(ry1, ry1, 1.1);
	test.draw(ry1, ry1, 1.2);
	test.draw(ry1, ry1, 1.3);
	test.draw(ry1, ry1, 1.4);
	test.draw(ry1, ry1, 1.5);
	test.draw(ry1, ry1, -0.1);
	test.draw(ry1, ry1, -0.2);
	test.draw(ry1, ry1, -0.3);
	test.draw(ry1, ry1, -0.4);
	test.draw(ry1, ry1, -0.5);
	test.draw(ry1, ry1, -0.6);
	test.draw(ry1, ry1, -0.7);
	test.draw(ry1, ry1, -0.8);
	test.draw(ry1, ry1, -0.9);
	test.draw(ry1, ry1, -1);
	test.draw(ry1, ry1, -1.1);
	test.draw(ry1, ry1, -1.2);
	test.draw(ry1, ry1, -1.3);
	test.draw(ry1, ry1, -1.4);
	test.draw(ry1, ry1, -1.5);
	test.draw(ry1, ry1, -1.6);
	test.draw(ry1, ry1, -1.7);
	test.draw(ry1, ry1, -1.8);
	test.draw(ry1, ry1, -1.9);
	test.draw(ry1, ry1, -2);
}
void display(void){
	glClear(GL_COLOR_BUFFER_BIT);
	night();
	house(0.949, 0.854, 0.450); // open light in house
	if (time <= 5000) {
		daytime();
		house(0.0, 0.5, 1.0);
	}

	if (random2 == 1)car(dx4, 0.4, r3, g3, b3);
	if (random1 == 1)car(dx3, 0.2, r2, g2, b2);
	car(dx1 - 0.5, 0, r, g, b); //normal car วิ่งไปเรื่อยๆ
	if (random == 1)car(dx2, -0.2, r1, g1, b1);

	if (rain == 1 || rain == 3) {
		int sec = rand() % 20 + 1;
		for (int i = 0; i < sec; i++) 
			raining();
	}else{
		if(time >= 5000)
			star();
	}

	glFlush();
	glutSwapBuffers();
}
void spinDisplay(void)
{
	//Flowe with wind
	flowerWind += 0.0001;
	if (flowerWind > 0.009)
		flowerWind = -0.009;
		
	//shining star
	starchange += 1;
	if (starchange == 100)
		starchange = 0;

	//Smoke house and cars
	smoke += 1;
	smoke2 += 1;
	if (smoke2 == 10)
		smoke2 = 0;
	if (smoke == 100)
		smoke = 0;

	//Raining
	ry1 += 0.002;
	if (ry1 >= 0.095)
		ry1 = -0.095;

	dx1 -= 0.003;
	dx2 -= 0.001;
	dx3 -= 0.004;
	dx4 -= 0.005;

	if (dx1 <= -3.0) {
		dx1 = 1.5;
		r = rand() % 2; r / 10;
		g = rand() % 2; g / 10;
		b = rand() % 2; b / 10;
		rain = rand() % 5 + 1;
	}

	if (dx2 <= -3.5) {
		dx2 = 2.0;
		r1 = rand() % 2; r1 / 10;
		g1 = rand() % 2; g1 / 10;
		b1 = rand() % 2; b1 / 10;
		random = rand() % 2 + 1;
	}

	if (dx3 <= -4.0) {
		dx3 = 2.5;
		r2 = rand() % 2; r2 / 10;
		g2 = rand() % 2; g2 / 10;
		b2 = rand() % 2; b2 / 10;
		random1 = rand() % 2 + 1;
	}

	if (dx4 <= -4.5) {
		dx4 = 3.0;
		r3 = rand() % 2; r3 / 10;
		g3 = rand() % 2; g3 / 10;
		b3 = rand() % 2; b3 / 10;
		random2 = rand() % 2 + 1;
	}

	//day/night cycle
	time += 1;
	if (time == 10000) {
		time = 0;
	}

	//car wheels
	a -= 0.01;
	if (a == -360)
		a = 0;

	glutPostRedisplay();
}
void mouse(int button, int state, int x, int y)
{
	int i;
	if (button == GLUT_LEFT_BUTTON) {
		if (state == GLUT_DOWN)
			for (i = 1; i <= 10; i++) {
				glutIdleFunc(spinDisplay);
			}
	}
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // 2. add glut_double
	glutInitWindowSize(900, 600);
	glutInitWindowPosition(300, 200);
	glutCreateWindow("Test OpenGL");
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	init();
	glutMainLoop();
	return 0;
}
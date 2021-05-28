#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

#define window_height 400
#define window_width 600
float rotation = 1;
float zoom = 1;
float trans = 1;

void display(void);
void tela(GLsizei w, GLsizei h);
void keyboard(unsigned char tecla, int x, int y);

int main(int argc, char** argv)
{
	glutInit(&argc, argv); //Suporte a janelas
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //padrao de cores

	glutInitWindowSize(window_width, window_height); //Tamanho janela
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Eduardo Rampon Meireles");

	//glutFullScreen();
	glutReshapeFunc(tela);//configurar tela
	glutDisplayFunc(display);
	glutKeyboardFunc(&keyboard);//chama teclado
	glutMainLoop(); //redesenhar

	return(0);
}

void keyboard(unsigned char tecla,int x,int y)
{
	printf("\nTecla  %c\n", tecla);
	printf("Digite 1 para esquera e 2 para direita");
	if (tecla == '1')
	{
		rotation = rotation + 1.5;
		printf("Valor da rotacao %.2f\n", rotation);
	}
	if (tecla == '2')
	{
		rotation = rotation - 1.5;
		printf("Valor da rotacao %.2f\n", rotation);
	}
	if (tecla == '3')
	{
		zoom = zoom + 0.5; //Escala
		printf("\nValor do zoom e %.2f\n", zoom);
	}
	if (tecla == '4')
	{
		trans = trans + 0.5;
		printf("\nValor da translacao e %.2f\n", trans);
	}
	if (tecla == '5')
	{
		trans = trans - 0.5;
		printf("\nValor da translacao e %.2f\n", trans);
	}
	if (tecla == '6')
	{
		zoom = zoom - 0.5; //Escala
		printf("\nValor do zoom e %.2f\n", zoom);
	}
	glutPostRedisplay();
}

void desenhar()
{
	glBegin(GL_QUADS);
		glColor3f(1, 0, 0);
		glVertex2f(-30, -30);
		glVertex2f(-30, 30);
		glVertex2f(30, 30);
		glVertex2f(30, -30);
	glEnd();

	glRotated(rotation, 0, 0, 1);

	glScalef(zoom, zoom, 0);
	glTranslatef(trans, trans,0);
	
	glBegin(GL_QUADS);
		glColor3f(0, 0, 0);
		glVertex2f(-120, -120);
		glVertex2f(-120, -50);
		glVertex2f(0, -50);
		glVertex2f(0, -120);
	glEnd();
	
	glRotated(-rotation, 0, 0, 1);

}

void display()
{
	glMatrixMode(GL_MODELVIEW); //coordenadas de desenho
	glLoadIdentity();

	glClearColor(1, 1, 1, 1); //cor de fundo
	glClear(GL_COLOR_BUFFER_BIT); //Executa limpeza

	//Especificar onde o desenho ocorre
	glTranslatef(window_width / 2, window_height / 2, 0);

	glViewport(0, 0, window_width, window_height);
	desenhar();

	glFlush(); //Executa o desenho
}

void tela(GLsizei w, GLsizei h)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	//cria janela (esq,direita,em baixo,em cima)
	gluOrtho2D(0, window_width, 0, window_height);

	glMatrixMode(GL_MODELVIEW);
}

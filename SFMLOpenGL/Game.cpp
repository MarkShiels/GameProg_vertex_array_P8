#include <Game.h>

bool flip = false;
int current = 1;

Game::Game() : window(VideoMode(800, 600), "OpenGL Cube")
{
}

Game::~Game() {}


	// Vertices for Front Face
	//float verticesF0[] = { 1.0f, 1.0f, -5.0f, -1.0f, 1.0f, -5.0f, -1.0f, -1.0f, -5.0f };
	//float verticesF1[] = {1.0f, 1.0f, -5.0f, 1.0f, -1.0f, -5.0f, -1.0f, -1.0f, -5.0f };

	float rotationAngle{ 0.0f };
	
	Matrix3 mFront0 = Matrix3(1.0f, 1.0f, -5.0f, -1.0f, 1.0f, -5.0f, -1.0f, -1.0f, -5.0f);
	Matrix3 mFront1 = Matrix3(1.0f, 1.0f, -5.0f, 1.0f, -1.0f, -5.0f, -1.0f, -1.0f, -5.0f);

	float verticesF0[] = { mFront0.m_A11, mFront0.m_A12, mFront0.m_A13, mFront0.m_A21, mFront0.m_A22, mFront0.m_A23, mFront0.m_A31, mFront0.m_A32, mFront0.m_A33 };
	float verticesF1[] = { mFront1.m_A11, mFront1.m_A12, mFront1.m_A13, mFront1.m_A21, mFront1.m_A22, mFront1.m_A23, mFront1.m_A31, mFront1.m_A32, mFront1.m_A33 };

	Matrix3 mFront0Alt = (mFront0.rotationX(rotationAngle)) * mFront0;
	float verticesF0Alt[] = { mFront0Alt.m_A11, mFront0Alt.m_A12, mFront0Alt.m_A13, mFront0Alt.m_A21, mFront0Alt.m_A22, mFront0Alt.m_A23, mFront0Alt.m_A31, mFront0Alt.m_A32, mFront0Alt.m_A33 };

	// Vertices for Rear Face
	//float verticesB0[] = { 1.0f, 1.0f, -15.0f, -1.0f, 1.0f, -15.0f, -1.0f, -1.0f, -15.0f };
	//float verticesB1[] = { 1.0f, 1.0f, -15.0f, 1.0f, -1.0f, -15.0f, -1.0f, -1.0f, -15.0f };

	Matrix3 mBack0 = Matrix3(1.0f, 1.0f, -15.0f, -1.0f, 1.0f, -15.0f, -1.0f, -1.0f, -15.0f);
	Matrix3 mBack1 = Matrix3(1.0f, 1.0f, -15.0f, 1.0f, -1.0f, -15.0f, -1.0f, -1.0f, -15.0f);

	float verticesB0[] = { mBack0.m_A11, mBack0.m_A12, mBack0.m_A13, mBack0.m_A21, mBack0.m_A22, mBack0.m_A23, mBack0.m_A31, mBack0.m_A32, mBack0.m_A33 };
	float verticesB1[] = { mBack1.m_A11, mBack1.m_A12, mBack1.m_A13, mBack1.m_A21, mBack1.m_A22, mBack1.m_A23, mBack1.m_A31, mBack1.m_A32, mBack1.m_A33 };

	//Vertices for Left Face
	float verticesL0[] = { -1.0f, 1.0f, -5.0f, -1.0f, -1.0f, -5.0f,  -1.0f, 1.0f, -15.0f, };
	float verticesL1[] = { -1.0f, 1.0f, -15.0f, -1.0f, -1.0f, -5.0f, -1.0f, -1.0f, -15.0f };

	//Vertices for Right Face
	float verticesR0[] = { 1.0f, 1.0f, -5.0f, 1.0f, -1.0f, -5.0f,  1.0f, 1.0f, -15.0f, };
	float verticesR1[] = { 1.0f, 1.0f, -15.0f, 1.0f, -1.0f, -5.0f, 1.0f, -1.0f, -15.0f };

	//Vertices for the Top Face
	float verticesT0[] = { 1.0f, 1.0f, -5.0f, -1.0f, 1.0f, -5.0f, 1.0f, 1.0f, -15.0f };
	float verticesT1[] = { -1.0f, 1.0f, -5.0f, -1.0f, 1.0f, -15.0f, 1.0f, 1.0f, -15.0f };

	//Vertices for the Under Face
	float verticesU0[] = { 1.0f, -1.0f, -5.0f, -1.0f, -1.0f, -5.0f, 1.0f, -1.0f, -15.0f };
	float verticesU1[] = { -1.0f, -1.0f, -5.0f, -1.0f, -1.0f, -15.0f, 1.0f, -1.0f, -15.0f };

	// Colors for those vertices
	//float colors[] = { 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f };
	float coloursF[] = { 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f };
	float coloursB[] = { 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f };
	float coloursLR[] = { 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f };
	float coloursTU[] = { 1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f };

	// Index to be drawn
	unsigned int vertex_index[] = { 0, 1, 2 };


void Game::run()
{

	initialize();

	Event event;

	while (isRunning) {

		//cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		render();
	}

}

void Game::initialize()
{
	isRunning = true;

	//glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
}

void Game::update()
{
	elapsed = clock.getElapsedTime();

	rotationAngle+=0.1;
	if (rotationAngle > 360)
	{
		rotationAngle = 0;
	}
	

	//cout << "Update up" << endl;
}

void Game::render()
{

	mFront0Alt = mFront0.rotationX(rotationAngle) * mFront0;
	//float verticesF0Alt[] = { mFront0Alt.m_A11, mFront0Alt.m_A12, mFront0Alt.m_A13, mFront0Alt.m_A21, mFront0Alt.m_A22, mFront0Alt.m_A23, mFront0Alt.m_A31, mFront0Alt.m_A32, mFront0Alt.m_A33 };
	for (int i{ 0 }; i < 9; i++)
	{
		verticesF0Alt[i] = mFront0Alt.point(i);
		//cout << mFront0Alt.point(i) << endl;
	}
	//cout << "Drawing" << endl;
	//glDrawArrays(GL_TRIANGLES, 0, 3);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	//Front Face
	glVertexPointer(3, GL_FLOAT, 0, &verticesF0Alt);
	glColorPointer(3, GL_FLOAT, 0, &coloursF);
	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, &vertex_index);

	glVertexPointer(3, GL_FLOAT, 0, &verticesF1);
	glColorPointer(3, GL_FLOAT, 0, &coloursF);
	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, &vertex_index);

	////Rear Face
	//glVertexPointer(3, GL_FLOAT, 0, &verticesB0);
	//glColorPointer(3, GL_FLOAT, 0, &coloursB);
	//glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, &vertex_index);

	//glVertexPointer(3, GL_FLOAT, 0, &verticesB1);
	//glColorPointer(3, GL_FLOAT, 0, &coloursB);
	//glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, &vertex_index);

	////Left Face
	//glVertexPointer(3, GL_FLOAT, 0, &verticesL0);
	//glColorPointer(3, GL_FLOAT, 0, &coloursLR);
	//glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, &vertex_index);

	//glVertexPointer(3, GL_FLOAT, 0, &verticesL1);
	//glColorPointer(3, GL_FLOAT, 0, &coloursLR);
	//glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, &vertex_index);

	////Right Face
	//glVertexPointer(3, GL_FLOAT, 0, &verticesR0);
	//glColorPointer(3, GL_FLOAT, 0, &coloursLR);
	//glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, &vertex_index);

	//glVertexPointer(3, GL_FLOAT, 0, &verticesR1);
	//glColorPointer(3, GL_FLOAT, 0, &coloursLR);
	//glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, &vertex_index);

	////Top Face
	//glVertexPointer(3, GL_FLOAT, 0, &verticesT0);
	//glColorPointer(3, GL_FLOAT, 0, &coloursTU);
	//glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, &vertex_index);

	//glVertexPointer(3, GL_FLOAT, 0, &verticesT1);
	//glColorPointer(3, GL_FLOAT, 0, &coloursTU);
	//glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, &vertex_index);

	////Under Face
	//glVertexPointer(3, GL_FLOAT, 0, &verticesU0);
	//glColorPointer(3, GL_FLOAT, 0, &coloursTU);
	//glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, &vertex_index);

	//glVertexPointer(3, GL_FLOAT, 0, &verticesU1);
	//glColorPointer(3, GL_FLOAT, 0, &coloursTU);
	//glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, &vertex_index);

	//
	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);

	window.display();

}

void Game::unload()
{
	//cout << "Cleaning up" << endl;
}




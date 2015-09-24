//put global includes in 'BasicIncludes'

#include <iostream>
#include "rand.h"
#include "BasicIncludes.h"



//Function List
void Update(double);
void Draw();
void InitializeWindow();
void Terminate();

//Variables
GLFWwindow* mainThread;
glm::uvec2 SCREEN_SIZE;
Camera camera;
glm::vec2 mouseChangeDegrees;

void InitializeWindow() {

	
	//
	if (!glfwInit()) {
		Terminate();
	}

	//set screen size
	const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());

	SCREEN_SIZE = glm::uvec2(720,720);

	//basic aa done for us ;D
	glfwWindowHint(GLFW_SAMPLES, 16);
	glfwWindowHint(GLFW_VISIBLE, GL_TRUE);


	//can change the screen setting later


	//if (window == FULLSCREEN) {

	//	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	//	mainThread = glfwCreateWindow(SCREEN_SIZE.x, SCREEN_SIZE.y, "LifeSim", glfwGetPrimaryMonitor(), NULL);

	//}
	//else if (window == WINDOWED) {

		glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
		mainThread = glfwCreateWindow(SCREEN_SIZE.x, SCREEN_SIZE.y, "LifeSim", NULL, NULL);

	//}
	//else if (BORDERLESS) {

	//	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	//	const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	//	glfwWindowHint(GLFW_RED_BITS, mode->redBits);
	//	glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
	//	glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
	//	glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);
	//	mainThread = glfwCreateWindow(mode->width, mode->height, "LifeSim", glfwGetPrimaryMonitor(), NULL);

	//}


	if (!mainThread) {
		glfwTerminate();
		throw std::runtime_error("GLFW window failed");
	}

	glfwMakeContextCurrent(mainThread);

	// initialise GLEW
	if (glewInit() != GLEW_OK) {
		throw std::runtime_error("glewInit failed");
	}

	glewExperimental = GL_TRUE; //stops glew crashing on OSX :-/

	glfwSetInputMode(mainThread, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSetCursorPos(mainThread, SCREEN_SIZE.x / 2.0, SCREEN_SIZE.y / 2.0);

	//Discard all the errors
	while (glGetError() != GL_NO_ERROR) {}

	glEnable(GL_DEPTH_TEST); // enable depth-testing
	glDepthMask(GL_TRUE);  // turn on
	glDepthFunc(GL_LEQUAL);
	glDepthRange(0.0f, 1.0f);
	glEnable(GL_TEXTURE_2D);

	mouseChangeDegrees = glm::vec2(0);

	// setup camera 
	camera.setViewportAspectRatio(SCREEN_SIZE.x / (float)SCREEN_SIZE.y);

	camera.setPosition(glm::vec3(-(METER* 5), METER * 5, -(METER * 5)));
	camera.offsetOrientation(135, 45);

	//unsigned concurentThreadsSupported = std::thread::hardware_concurrency();
	//threads = new ThreadPool(concurentThreadsSupported);


	//for keyboard controls
	glfwSetKeyCallback(mainThread, InputKeyboardCallback);
	SetInputWindow(mainThread);
}


int main(){

	//Comments
	//#define Connor GOD 
	//More Comments

	std::cout << "Hello World" << std::endl;

	return 0;
}

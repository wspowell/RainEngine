// window

#include "rain_window.h"

Window::Window() : WINDOW_TITLE("Rain: Window"), WINDOW_HEIGHT(600), WINDOW_WIDTH(800), WINDOW_MODE(GLFW_WINDOW), ANTIALIASING(1) {
	printf("Initializing window...\n");
}

Window::~Window() { }

void Window::setTitle(const char* t) { WINDOW_TITLE = t; }

void Window::setHeight(uint h) { if(WINDOW_MODE != GLFW_FULLSCREEN) { WINDOW_HEIGHT = h; } }

void Window::setWidth(uint w) { if(WINDOW_MODE != GLFW_FULLSCREEN) { WINDOW_WIDTH = w; } }

void Window::setAntiAliasing(uint a) { ANTIALIASING = a; }

void Window::setMode(int m) {
	/*WINDOW_MODE = GLFW_FULLSCREEN;
	GLFWvidmode return_struct;
	glfwGetDesktopMode( &return_struct );
	WINDOW_HEIGHT = return_struct.Height;
	WINDOW_WIDTH = return_struct.Width;*/
	switch(m) {
		case 0: 
			printf("Setting window mode to windowed.\n");
			WINDOW_MODE = GLFW_WINDOW;
			break;
		case 1:
			printf("Setting window mode to fullscreen.\n");
			// let glfw set the size to defaults
			setWidth(1920);
			setHeight(1080);
			WINDOW_MODE = GLFW_FULLSCREEN;
			break;
		/*case 2: // not implemented in glfw until v3.x
			printf("Setting window mode to fullscreen windowed.\n");
			WINDOW_MODE = GLFW_WINDOW;
			break;*/
		default:
			printf("Setting window mode to windowed (default).\n");
			setWidth(800);
			setHeight(600);
			WINDOW_MODE = GLFW_WINDOW;
			break;
	}
}

void GLFWCALL Window::resize(int width, int height) {
	printf("RESIZING\n");
	glfwSetWindowSize(width, height);
}

void Window::init(uint w, uint h, uint m, uint a) {
	WINDOW_WIDTH = w;
	WINDOW_HEIGHT = h;
	setMode(m);
	ANTIALIASING = a;
}

bool Window::open() {
	// Initialise GLFW
	if( !glfwInit() )
	{
		fprintf( stderr, "Failed to initialize GLFW\n" );
		return false;
	}

	glfwOpenWindowHint(GLFW_FSAA_SAMPLES, ANTIALIASING); // 4x antialiasing
	glfwOpenWindowHint(GLFW_OPENGL_VERSION_MAJOR, 4); // We want OpenGL 4.1
	glfwOpenWindowHint(GLFW_OPENGL_VERSION_MINOR, 1);
	glfwOpenWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwOpenWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwOpenWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //We don't want the old OpenGL

	// Open a window and create its OpenGL context
	if( !glfwOpenWindow( WINDOW_WIDTH, WINDOW_HEIGHT, 8,8,8,0, 8,0, WINDOW_MODE ) )
	{
		fprintf( stderr, "Failed to open GLFW window\n" );
		glfwTerminate();
		return false;
	}
	int w,h;
	glfwGetWindowSize(&w,&h);
	glViewport(0,0,w,h);

	glfwEnable(GLFW_AUTO_POLL_EVENTS);

	// set window callback for when the window is resized
	glfwSetWindowSizeCallback((GLFWwindowsizefun)resize);

	// set window position
	glfwSetWindowPos(WINDOW_WIDTH/4,WINDOW_HEIGHT/4);

	// Initialize GLEW
	glewExperimental=true; // Needed in core profile
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		return false;
	}

	glfwSetWindowTitle( WINDOW_TITLE );
	
	int version_major, version_minor, version_revision;
	glfwGetGLVersion(&version_major, &version_minor, &version_revision);
	printf("Using OpenGL version %d.%d\n",version_major,version_minor);
	printf("width %u height %u mode %d aa %u\n",WINDOW_WIDTH,WINDOW_HEIGHT,WINDOW_MODE,ANTIALIASING);	
	printf("Window opened successfully\n");

	// Ensure we can capture the escape key being pressed below
	glfwEnable( GLFW_STICKY_KEYS );
	
	// set clear color
	glClearColor(0,0,0,0);
	// set clear depth
	glClearDepth(1);
	// set clear stencil buffer
	glClearStencil(0);

	glScalef(1.0f, -1.0f, 1.0f);

	// Create vertex array object
	glGenVertexArrays(1, &vaoID);
	glBindVertexArray(vaoID);

	return true;
}

GLuint Window::getVao() {
	return vaoID;
}

// Gets the frame rate as 1/secondsPerFrame
// for 60FPS the target should be 16.66ms
double Window::getFrameRate() {
	double framerate = -1;
	static double lastTime = glfwGetTime();
	static int nbFrames = 0;

	// Measure speed
	double currentTime = glfwGetTime();
	nbFrames++;
	if ( currentTime - lastTime >= 1.0 ){ // If last prinf() was more than 1 sec ago
		// printf and reset timer
		//printf("%f ms/frame\n", 1000.0/double(nbFrames));
		framerate = 1000.0/double(nbFrames);
		nbFrames = 0;
		lastTime += 1.0;
	}

	return framerate;
}

uint Window::getHeight() { return WINDOW_HEIGHT; }

uint Window::getWidth() { return WINDOW_WIDTH; }























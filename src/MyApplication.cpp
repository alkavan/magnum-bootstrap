#include <Platform/Sdl2Application.h>
#include <SceneGraph/Scene.h>
#include <SceneGraph/Camera2D.h>

#include "Dnmix/Object.h"

namespace MyNamespace {

	using namespace Magnum;
	using namespace Dnmix;

	typedef SceneGraph::Object<SceneGraph::MatrixTransformation2D> Object2D;
	typedef SceneGraph::Scene<SceneGraph::MatrixTransformation2D> Scene2D;

class MyApplication: public Platform::Application {

public:
	explicit MyApplication(const Arguments& arguments);

protected:
	void viewportEvent(const Vector2i& size) override;
	void drawEvent() override;
	void mousePressEvent(MouseEvent& event) override;
	void mouseReleaseEvent(MouseEvent& event) override;
	void mouseMoveEvent(MouseMoveEvent &event) override;
	void keyPressEvent(KeyEvent &event) override;
	void keyReleaseEvent(KeyEvent &event) override;

private:
	Scene2D scene;
	Object2D* cameraObject;
	SceneGraph::Camera2D* camera;
	SceneGraph::DrawableGroup2D drawables;

	Mesh mesh;
};

MyApplication::MyApplication(const Arguments& arguments): Platform::Application(arguments, Configuration().setTitle("MyApplication 0.1")) {

	/* Configure camera */
	cameraObject = new Object2D(&scene);
	camera = new SceneGraph::Camera2D(*cameraObject);
	camera->setAspectRatioPolicy(SceneGraph::AspectRatioPolicy::Extend)
	.setProjection({4.0f/3.0f, 1.0f})
	.setViewport(defaultFramebuffer.viewport().size());

	/* Add a few object instances. Note that it's done this way only for
	brevity and is not efficient, as the data (buffer, mesh, shader) are
	not shared among the instances. Consider using e.g. ResourceManager (see
	Viewer example) */
	(new Object(&scene, &drawables))->scale(Vector2(0.05f)).translate(Vector2::yAxis(0.2f));
	(new Object(&scene, &drawables))->scale(Vector2(0.1f)).translate({-0.3f, -0.2f});
	(new Object(&scene, &drawables))->scale(Vector2(0.2f)).translate({+0.3f, -0.2f});
}

void MyApplication::viewportEvent(const Vector2i& size) {
	defaultFramebuffer.setViewport({{}, size});
	camera->setViewport(size);
}

void MyApplication::drawEvent() {
	defaultFramebuffer.clear(FramebufferClear::Color);
	camera->draw(drawables);
	swapBuffers();
}

void MyApplication::mousePressEvent(MouseEvent &event)
{
	// TODO
}

void MyApplication::mouseReleaseEvent(MouseEvent &event)
{
	// TODO
}

void MyApplication::mouseMoveEvent(MouseMoveEvent &event)
{
	// TODO
}

void MyApplication::keyPressEvent(KeyEvent &event)
{
	// TODO
}
void MyApplication::keyReleaseEvent(KeyEvent &event)
{
	// TODO
}


}
MAGNUM_APPLICATION_MAIN(MyNamespace::MyApplication)

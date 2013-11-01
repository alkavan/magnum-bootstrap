#ifndef OBJECT_H
#define OBJECT_H

#include <DefaultFramebuffer.h>
#include <Mesh.h>
#include <Shaders/Flat.h>
#include <SceneGraph/MatrixTransformation2D.h>
#include <SceneGraph/Camera2D.h>
#include <SceneGraph/Drawable.h>

namespace Dnmix {

using namespace Magnum;

typedef SceneGraph::Object<SceneGraph::MatrixTransformation2D> Object2D;
typedef SceneGraph::Scene<SceneGraph::MatrixTransformation2D> Scene2D;

class Object: public Object2D, public SceneGraph::Drawable2D {
	public:
	explicit Object(Object2D* parent, SceneGraph::DrawableGroup2D* drawables = nullptr);

	private:
	void draw(const Matrix3& transformationMatrix, SceneGraph::AbstractCamera2D& camera) override;

	Buffer buffer;
	Mesh mesh;
	Shaders::Flat2D shader;
};

}
#endif // OBJECT_H

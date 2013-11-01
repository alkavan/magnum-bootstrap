#include "Object.h"

using namespace Dnmix;

Object::Object(Object2D* parent, SceneGraph::DrawableGroup2D* drawables): Object2D(parent), SceneGraph::Drawable2D(*this, drawables) {
  constexpr static Vector2 data[] = {
  {-0.5f, -0.5f}, /* Left vertex */
  { 0.5f, -0.5f}, /* Right vertex */
  { 0.0f, 0.5f} /* Top vertex */
};

  buffer.setData(data, Buffer::Usage::StaticDraw);
  mesh.setPrimitive(Mesh::Primitive::Triangles)
	.setVertexCount(3)
	.addVertexBuffer(buffer, 0, Shaders::Flat2D::Position());
}

void Object::draw(const Matrix3& transformationMatrix, SceneGraph::AbstractCamera2D& camera) {
  shader.setTransformationProjectionMatrix(camera.projectionMatrix()*transformationMatrix)
	.setColor(Color3::fromHSV(32.0_degf, 0.9f, 1.0f))
	.use();
  mesh.draw();
}


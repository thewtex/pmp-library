//=============================================================================
#pragma once
//=============================================================================

#include <surface_mesh/gl/gl.h>
#include <surface_mesh/gl/Shader.h>
#include <surface_mesh/Vector.h>
#include <surface_mesh/Matrix.h>
#include <surface_mesh/SurfaceMesh.h>

//=============================================================================

namespace surface_mesh {

//=============================================================================

class SurfaceMeshGL : public SurfaceMesh
{
public:

    //! Constructor
    SurfaceMeshGL();

    //! default destructor
    ~SurfaceMeshGL();

    //! get crease angle (in degrees) for visualization of sharp edges
    Scalar creaseAngle() const { return crease_angle_; }

    //! set crease angle (in degrees) for visualization of sharp edges
    void setCreaseAngle(Scalar ca);

    //! draw the mesh
    void draw(const mat4& projectionMatrix,
              const mat4& modelviewMatrix,
              const std::string drawMode);

    //! update all opengl buffers for efficient core profile rendering
    void updateOpenGLBuffers();


private:

    // material parameters
    float crease_angle_;

    //! OpenGL buffers 
    GLuint vertex_array_object_;
    GLuint vertex_buffer_;
    GLuint normal_buffer_;
    GLuint edge_buffer_;

    //! buffer sizes
    GLsizei n_vertices_;
    GLsizei n_edges_;
    GLsizei n_triangles_;

    //! shaders
    Shader  m_phongShader;
};


//=============================================================================
} // namespace
//=============================================================================

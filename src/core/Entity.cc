//
// Created by Eddie Hoyle on 4/09/16.
//

#include <glm/gtc/type_ptr.hpp>
#include "Entity.hh"


Entity::Entity()
        : m_shader( NULL ),
          m_model( NULL ),
          m_transform( NULL )
{
    m_transform = new Transform();
}

Entity::~Entity()
{
    delete m_shader;
    delete m_model;
    delete m_transform;
}


void Entity::initializeShader( Shader* shader, Model* model )
{
    m_shader = shader;
    m_model = model;

}

Shader* Entity::getShader() const
{
    return m_shader;
}

Transform* Entity::getTransform() const
{
    return m_transform;
}

Model* Entity::getModel() const
{
    return m_model;
}

void Entity::draw()
{
    GLuint program = m_shader->getProgram();
    glUseProgram( program );

    // ------------------------------------------------------------

//    glm::mat4 projection = WindowManager::instance()->getOrthographicProjectionMatrix();
//    glm::mat4 projection = WindowManager::instance()->getPerspectiveProjectionMatrix();

//

//    glm::mat4 projection = camera->getProjectionMatrix();
//    GLint projectionHandle = glGetUniformLocation( program, "projection" );
//    glUniformMatrix4fv(projectionHandle, 1, GL_FALSE, glm::value_ptr(projection));
//
//    // ------------------------------------------------------------
//
//
//    int mPositionHandle = glGetAttribLocation(m_program, "position");
//
//    // Enable a handle to the triangle vertices
//    glEnableVertexAttribArray( mPositionHandle );
//
//    // Number of components per attribute, ie: len([x, y, z]) == 3
//    // This is confusing, because the 'position' attribute in the
//    // vert shader is vec4, implying a size of 4?
//    GLint size = 3;
//
//    // Stride simply means the amount of bytes between each vertex.
//    // In this case: [[x, y, z], [x, y, z], ...] == [12, 12, ...]
//    GLuint stride = size * sizeof( GLfloat );
//
//    glVertexAttribPointer( mPositionHandle, size, GL_FLOAT, GL_FALSE, stride, &m_vertices[0] );
//
//    // get handle to fragment shader's vColor member
//    int mColorHandle = glGetUniformLocation(m_program, "color");
//
//    // Set color for drawing the triangle
//    float color[] = { 0.63671875f, 0.76953125f, 0.22265625f, 1.0f };
//    glUniform4fv(mColorHandle, 1, color);
//
//    // Draw the triangle
//    glDrawArrays(GL_TRIANGLES, 0, ( GLuint )m_numVertices );
//
//    // Disable vertex array
//    glDisableVertexAttribArray(mPositionHandle);
}

void Entity::listen( AbstractEvent *event )
{
    // TODO
}
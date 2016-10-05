//
// Created by Eddie Hoyle on 4/09/16.
//

#include <glm/gtc/type_ptr.hpp>
#include <glm/ext.hpp>

#include "Entity.hh"
#include "Game.hh"
#include "Rect.hh"

Entity::Entity()
        : m_shader( NULL ),
          m_model( NULL ),
          m_transform( NULL ),
          m_rect( NULL )
{
    m_transform = new Transform();
}

Entity::~Entity()
{
    delete m_shader;
    delete m_model;
    delete m_transform;
    delete m_rect;
}


void Entity::initializeShader( Shader* shader, Mesh* model )
{
    m_shader = shader;
    m_model = model;

}

void Entity::initializeShader( Shader* shader, Rect* rect )
{
    m_shader = shader;
    m_rect = rect;

}

Shader* Entity::getShader() const
{
    return m_shader;
}

Transform* Entity::getTransform() const
{
    return m_transform;
}

Mesh* Entity::getModel() const
{
    return m_model;
}

//void Entity::draw()
//{
//    GLuint program = m_shader->getProgram();
//    glUseProgram( program );
//
//    // ------------------------------------------------------------
//
//    glm::mat4 projection = Game::instance()->getCamera()->getOrthographicMatrix();
////    std::cout << "Orthographic: " << glm::to_string( projection ) << std::endl;
////    glm::mat4 projection = Game::instance()->getCamera()->getPerspectiveMatrix();
////    std::cout << "Perspective: " << glm::to_string( projection ) << std::endl;
//
////    getShader()->
//
//    GLint projectionHandle = glGetUniformLocation( program, "projection" );
//    glUniformMatrix4fv(projectionHandle, 1, GL_FALSE, glm::value_ptr(projection));
////
////    // ------------------------------------------------------------
////
////
//    GLuint mPositionHandle = ( GLuint )glGetAttribLocation( getShader()->getProgram(), "position" );
////
////    // Enable a handle to the triangle vertices
//    glEnableVertexAttribArray( mPositionHandle );
////
////    // Number of components per attribute, ie: len([x, y, z]) == 3
////    // This is confusing, because the 'position' attribute in the
////    // vert shader is vec4, implying a size of 4?
//    GLint size = 3;
////
////    // Stride simply means the amount of bytes between each vertex.
////    // In this case: [[x, y, z], [x, y, z], ...] == [12, 12, ...]
//    GLuint stride = size * sizeof( GLfloat );
//
//    Mesh vertexes = getModel()->getVertexes();
////    std::cout << "Paddle vertexes: "
////    << vertexes[0] << ", " << vertexes[1] << ", " << vertexes[2] << std::endl;
//    glVertexAttribPointer( mPositionHandle, size, GL_FLOAT, GL_FALSE, stride, &vertexes[0] );
//
////
////    // get handle to fragment shader's vColor member
//    int mColorHandle = glGetUniformLocation( getShader()->getProgram(), "color");
////
////    // Set color for drawing the triangle
//    float color[] = { 0.63671875f, 0.76953125f, 0.22265625f, 1.0f };
//    glUniform4fv(mColorHandle, 1, color);
////
////    // Draw the triangle
////    GLfloat* vertexes = getModel()->getVertexes();
//    GLuint numVertexes = ( GLuint )vertexes.size();
////    std::cout << "Entity numVertexes: " << numVertexes << std::endl;
//    glDrawArrays(GL_TRIANGLES, 0, 18 );
////
////    // Disable vertex array
//    glDisableVertexAttribArray(mPositionHandle);
//
////    std::cout << "Entity draw()" << std::endl;
//}

void Entity::listen( AbstractEvent* event )
{
    // TODO
}

void Entity::update( double elapsed )
{
    // TODO
}

void Entity::draw()
{

}

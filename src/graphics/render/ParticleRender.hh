//
// Created by Eddie Hoyle on 7/02/17.
//

#ifndef SEVENGINE_RENDERPARTICLE_HH
#define SEVENGINE_RENDERPARTICLE_HH


#define GL_GLEXT_PROTOTYPES
#include <GLES2/gl2.h>

#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <vector>

struct Point;
struct Particle;

typedef std::vector< Point > Points;
typedef std::vector< Particle > Particles;
typedef std::vector< GLuint > Elements;

struct Point {

    void set ( GLfloat _x, GLfloat _y,
               GLubyte _r, GLubyte _g, GLubyte _b, GLubyte _a,
               GLfloat _size ) {
        x = _x;
        y = _y;
        r = _r;
        g = _g;
        b = _b;
        a = _a;
        size = _size;
    }

    GLfloat x, y;
    GLubyte r, g, b, a;
    GLfloat size;
};

struct Particle {

    void setPosition( const glm::vec2& vec );
    void setColor( GLubyte r, GLubyte g, GLubyte b, GLubyte a );
    void setSize( GLfloat size );

    Point point;
};

class ParticleBuffer {

public:
    void add( const Particle& particle );
    void add( const Particles& particles );
    void bind();
    void clear();

    const Points& getData() const;
    const Elements& getElements() const;

private:
    Points m_data;
    Elements m_elements;

    GLuint m_vbo;
    GLuint m_vao;
};


class ParticleRender {

public:

    ParticleRender();
    explicit ParticleRender( const ParticleBuffer& buffer );

    void bind();
    void draw();
    void release();

private:
    ParticleBuffer m_buffer;

};


#endif //SEVENGINE_RENDERPARTICLE_HH

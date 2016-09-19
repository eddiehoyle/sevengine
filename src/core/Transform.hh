//
// Created by Eddie Hoyle on 28/08/16.
//

#ifndef SEV_TRANSFORM_HH
#define SEV_TRANSFORM_HH

#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>

class Transform {

public:

    enum RotateOrder
    {
        XYZ = 0,
        YZX,
        ZXY,
        XZY,
        YXZ,
        ZYX,
    };

    enum DirtyFlags
    {
        WorldDirty = ( 1 << 0 ),
        LocalDirty = ( 1 << 1 ),
    };

//    DirtyFlags dirtyFlags = WorldDirty | LocalDirty;

public:


    Transform();
    explicit Transform( const glm::vec3 translate,
                        const glm::vec3 rotate,
                        const glm::vec3 scale,
                        RotateOrder order = XYZ );

    explicit Transform( const glm::mat4 matrix );

    ~Transform();

public:

    glm::mat4 getMatrix();
    glm::vec3& getTranslate();
    glm::vec3& getRotate();
    glm::vec3& getScale();

    void setTranslate( const glm::vec3 translate );
    void setRotate( const glm::vec3 rotate );
    void setScale( const glm::vec3 scale );

private:

    glm::vec3 m_translate;
    glm::vec3 m_rotate;
    glm::vec3 m_scale;

    glm::mat4 m_matrix;
    glm::mat4 m_worldMatrix;

};


#endif //SEV_TRANSFORM_HH

//
// Created by Eddie Hoyle on 14/08/16.
//

#ifndef SEV_SCREEN_HH
#define SEV_SCREEN_HH

#include <vector>

// GLM
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Window
{

public:
    Window();

private:

    int m_width;
    int m_height;

public:

    float getAspectRatio() const;

    void update( int width, int height );

    void setWidth( int m_width );
    void setHeight( int m_height );

    int getWidth() const;
    int getHeight() const;

};

//class WindowManager
//{
//
//public:
//
//    enum Orientation {
//        kLandscape,
//        kPortrait,
//    };
//
//private:
//    static WindowManager *s_instance;
//    WindowManager();
//
//    WindowManager( WindowManager const& );
//    void operator=( WindowManager const& );
//
//    int m_width;
//    int m_height;
//
//    glm::mat4 m_orthographicProjectionMatrix;
//    glm::mat4 m_perspectiveProjectionMatrix;
//
//    WindowManager::Orientation m_orientation;
//
//public:
//
//
//    static WindowManager* instance();
//    ~WindowManager();
//
//    int getWidth() const;
//    int getHeight() const;
//
//    void setWindowSize( const int width, const int height );
//
//    WindowManager::Orientation getOrientation() const;
//
//    void computeOrthographicProjectionMatrix();
//    void computePerspectiveProjectionMatrix();
//
//    void setOrthographicProjectionMatrix( const glm::mat4 &matrix );
//    void setPerspectiveProjectionMatrix( const glm::mat4 &matrix );
//
//    glm::mat4 getOrthographicProjectionMatrix() const;
//    glm::mat4 getPerspectiveProjectionMatrix() const;
//
//};



#endif //SEV_SCREEN_HH

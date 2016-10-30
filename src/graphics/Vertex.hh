//
// Created by Eddie Hoyle on 5/10/16.
//

#ifndef SEV_VERTEX_HH
#define SEV_VERTEX_HH


struct Vertex {

    float x, y;
    float u, v;

    void set( float _x, float _y, float _u, float _v );
    void set( Vertex vertex );
};


#endif //SEV_VERTEX_HH

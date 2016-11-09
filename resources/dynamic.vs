// Attributes
attribute vec2 in_Position;
attribute vec2 in_Texture;

// Uniforms
uniform mat4 uf_Projection;
uniform mat4 uf_Model;
uniform vec4 uf_Color;

// Pixels
uniform sampler2D uf_Pixels;

// Output
varying vec4 var_Color;
varying vec2 var_Texture;


void main()
{
    // Pass through data to fragment
    var_Color = uf_Color;
    var_Texture = in_Texture;

    vec4 pos = texture2D( uf_Pixels, vec2(0,1) );
    mat4 m = mat4( 1 );
    m[3] = pos;
//    m[3] = vec4(50.0, 20.0, 0.0, 1.0);

    // Vertex position
    gl_Position = uf_Projection * m * vec4( in_Position.xy, 0.0, 1.0 );
//    gl_Position = uf_Projection * uf_Model * vec4( in_Position.xy, 0.0, 1.0 );
}

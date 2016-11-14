// Attributes
attribute vec2 in_Position;
attribute vec2 in_Texture;

// Uniforms
uniform mat4 uf_Projection;
//uniform mat4 uf_Model;
uniform vec4 uf_Color;

// Pixels
uniform sampler2D uf_Pixels;

// Output
varying vec4 var_Color;
varying vec2 var_TexturePosition;


void main()
{
    // Pass through data to fragment
    var_Color = uf_Color;
    var_TexturePosition = in_Texture;

    // Vertex position
    gl_Position = uf_Projection * vec4( in_Position.xy, 0.0, 1.0 );
//    gl_Position = uf_Projection * m * vec4( in_Position.xy, 0.0, 1.0 );
//    gl_Position = uf_Projection * uf_Model * vec4( in_Position.xy, 0.0, 1.0 );
}

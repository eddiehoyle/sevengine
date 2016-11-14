// Texture data pointer
uniform sampler2D uf_Texture;

// Texture UV coordinates
varying vec2 var_TexturePosition;
varying vec4 var_Color;

void main()
{
//    gl_FragColor = texture2D( uf_Texture, var_Texture ) * var_Color;
    gl_FragColor = var_Color * texture2D( uf_Texture, var_TexturePosition );
//    gl_FragColor = var_Color;
}
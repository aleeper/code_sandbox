// Nothing here is actually working code -- just snippets reminding me of
// how some things work.


// Returns an iterator pointing to the first element in the range
// greater or equal to value, or last if no such element is found.
auto lower = std::lower_bound(data.begin(), data.end(), value);



// GL Shader inputs:

// Variable Qualifiers

// Qualifiers give a special meaning to the variable.
// The following qualifiers are available:

// const – The declaration is of a compile time constant
// attribute – Global variables that may change per vertex,
//     that are passed from the OpenGL application to vertex shaders.
//     This qualifier can only be used in vertex shaders.
//     For the shader this is a read-only variable. See Attribute section
// uniform – Global variables that may change per primitive
//     (may not be set inside glBegin,/glEnd), that are passed from
//     the OpenGL application to the shaders. This qualifier can be used
//     in both vertex and fragment shaders. For the shaders this is
//     a read-only variable. See Uniform section
// varying – used for interpolated data between a vertex shader and
//     a fragment shader. Available for writing in the vertex shader,
//     and read-only in a fragment shader. See Varying section.
//     Examples: color, intensity, normals.

// Example:

#version 410
 
layout (std140) uniform Matrices {
    mat4 projModelViewMatrix;
    mat3 normalMatrix;
};
 
in vec3 position;
in vec3 normal;
in vec2 texCoord;
 
out VertexData {
    vec2 texCoord;
    vec3 normal;
} VertexOut;
 
void main()
{
    VertexOut.texCoord = texCoord;
    VertexOut.normal = normalize(normalMatrix * normal);    
    gl_Position = projModelViewMatrix * vec4(position, 1.0);
}
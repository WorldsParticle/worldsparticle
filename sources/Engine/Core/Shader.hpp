///
/// \file Shader.hpp
///
/// \author Martin-Pierrat Louis (mart_p)
///
/// \date Sun, 17 Jan 2016 07:01:27
///
/// \version 1.0.4
///

#ifndef         __ENGINE_SHADER_HPP__
# define        __ENGINE_SHADER_HPP__

#include    <string>

namespace   Engine
{
    ///
    /// \brief This class is used to abstract a shader
    ///
    class Shader
    {

        public:
            ///
            /// \brief The differents types of shader that can be used with this class.
            ///
            enum Type
            {
                /// The Vertex Shader is the programmable Shader stage in the rendering pipeline that handles the processing of individual vertices.
                VERTEX_SHADER,
                /// The Tessellation Control Shader (TCS) is a Shader program written in GLSL. It sits between the Vertex Shader and the Tessellation Evaluation Shader.
                TESSELATION_CONTROL_SHADER,
                /// The Tessellation Evaluation Shader (TES) is a Shader program written in GLSL that takes the results of a Tessellation operation and computes the interpolated positions and other per-vertex data from them.
                EVALUATION_SHADER,
                /// A Geometry Shader (GS) is a Shader program written in GLSL that governs the processing of Primitives.
                GEOMETRY_SHADER,
                /// A Fragment Shader is the Shader stage that will processes a Fragment generated by the Rasterization into a set of colors and a single depth value.
                FRAGMENT_SHADER,
                /// A Compute Shader is a Shader Stage that is used entirely for computing arbitrary information. While it can do rendering, it is generally used for tasks not directly related to drawing triangles and pixels.
                COMPUTE_SHADER
            };

        public:

            ///
            /// \brief This constructor will directly generate the shader and add the data. Just need to compile it.
            /// \param shaderType : the type of the shader that should be created.
            /// \param data : The string should contain a shader.
            ///
            Shader(const Type &shaderType, const std::string &data);

            ///
            /// \brief Copy constructor.
            ///
            Shader(const Shader &other) = delete;

            ///
            /// \brief Move constructor.
            ///
            Shader(Shader &&other) noexcept;

            ///
            /// \brief Destructor
            ///
            ~Shader(void);

        public:
            ///
            /// \brief Copy assignment operator.
            ///
            Shader      &operator=(const Shader &other) = delete;

            ///
            /// \brief Move assignment operator.
            ///
            Shader      &operator=(Shader &&other) noexcept;

        public:
            ///
            /// \brief This method is used to compile the shader.
            ///
            bool    compile(void);

        public:

            ///
            /// \brief This method is used to get the type of the shader.
            /// \return the shader type.
            ///
            const Type          &getType(void) const;

            ///
            /// \brief Getter for the shader id attribute.
            /// \return the shader id value.
            ///
            unsigned int        getId(void) const;

        public:
            ///
            /// \brief This method is used to know if the shader have already been compiled.
            /// \return true if yes, false otherwise.
            ///
            bool    isCompiled(void) const;

        private:
            ///
            /// \brief This method is privately used to generate a shader with the graphic API with the good type.
            ///
            unsigned int    createShaderFromType(const Type &type);

        protected:
            ///
            /// \brief This attribute is used as opengl shader id.
            ///
            unsigned int    id;

            ///
            /// \brief This attribute is used to know if the shader have already been compiled.
            ///
            bool            compiled;

            ///
            /// \brief This attribute contain the type of the shader.
            ///
            Type            type;
    };
}

#endif /* !__ENGINE_SHADER_HPP__ */

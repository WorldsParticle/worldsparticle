#ifndef     __MESH_LIBRARY_HPP__
# define    __MESH_LIBRARY_HPP__

#include    "Library.hpp"
#include    "Mesh.hpp"

namespace   WorldParticles
{
    namespace   Engine
    {
        class       MeshLibrary : public Library<Mesh>
        {
            public:
                ///
                /// \brief Default constructor.
                ///
                MeshLibrary(void);

                ///
                /// \brief Construct the library from an assimp mesh array.
                ///
                /// TODO GSL array_view
                ///
                MeshLibrary(const aiMesh *assimpMeshes, unsigned int size);

                ///
                /// \brief Copy constructor.
                ///
                MeshLibrary(const MeshLibrary &other) = default;

                ///
                /// \brief Move constructor.
                ///
                MeshLibrary(MeshLibrary &&other) = default noexcept;

                ///
                /// \brief Destructor.
                ///
                virtual ~MeshLibrary(void) noexcept;

            public:
                ///
                /// \brief Copy assignment operator.
                ///
                MeshLibrary     &operator=(const MeshLibrary &other) = default;

                ///
                /// \brief Move assignment operator.
                ///
                MeshLibrary     &operator=(MeshLibrary &&other) = default noexcept;
        };
    }
}

#endif /* !__MESH_LIBRARY_HPP__ */

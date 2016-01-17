///
/// \file AssimpImporter.hpp
///
/// \author Martin-Pierrat Louis (mart_p)
///
/// \date Sun, 17 Jan 2016 06:50:13
///
/// \version 1.0.4
///

#ifndef     __ENGINE_ASSIMP_IMPORTER_HPP__
# define    __ENGINE_ASSIMP_IMPORTER_HPP__

#include    <string>
#include    <list>
#include    <assimp/Importer.hpp>
#include    <assimp/mesh.h>

namespace   Engine
{

    class   Scene;

    ///
    /// \brief This class is used to import a scene with the assimp library.
    ///
    class       AssimpImporter
    {
        public:
            ///
            /// \brief Default constructor
            ///
            AssimpImporter(void);

            ///
            /// \brief Copy constructor.
            ///
            AssimpImporter(const AssimpImporter &other) = default;

            ///
            /// \brief Move constructor.
            ///
            AssimpImporter(AssimpImporter &&other) noexcept = default;

            ///
            /// \brief Destructor
            ///
            virtual ~AssimpImporter(void) noexcept;

        public:
            ///
            /// \brief Copy assignment operator.
            ///
            AssimpImporter  &operator=(const AssimpImporter &other) = default;

            ///
            /// \brief Move assignment importer.
            ///
            AssimpImporter  &operator=(AssimpImporter &&other) noexcept = default;

        public:
            ///
            /// \brief This method is used to load a scene from a filename.
            ///
            Scene   *import(const std::string &filename);

        private:
            ///
            /// \brief This method use the ReadFile method with appropriate assimp flags.
            ///
            const aiScene   *load(const std::string &filename);

        private:
            ///
            /// \brief the assimp importer that wil be used to load the file in a new scene.
            ///
            Assimp::Importer    importer;
    };
}

#endif /* !__ENGINE_ASSIMP_IMPORTER_HPP__ */

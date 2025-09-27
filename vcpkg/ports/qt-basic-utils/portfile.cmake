set(GIT_REF_of_library 94ba8c905bd558d680a5557f62dc7fcb9b93fa00)

vcpkg_from_github(
    OUT_SOURCE_PATH SOURCE_PATH
    REPO drescherjm/QtBasicUtils
    REF ${GIT_REF_of_library} 
    SHA512 4cc79bfa8f177d2d10dc328ab0daa76ec6f25abad9fb0f213fcd3d79ebe05f4de439bcaaad89d62a49060d4a276c844ec4760bacecf9b15a53bd06e08e63b700
)

vcpkg_cmake_configure(
    SOURCE_PATH "${SOURCE_PATH}"
)

vcpkg_cmake_build()
vcpkg_cmake_install()

# Fixup cmake config locations and paths. This is essential for vcpkg to setup the SimpleLibraryExampleConfig.cmake file 
# and setup each configuration for multiconfig generators like Visual Studio 2022. 
# Remember that vcpkg builds the Debug and Release config then maps the other configs: MinSizeRel, RelWithDebInfo to
# use the binaries created for the Release config. 
vcpkg_cmake_config_fixup(PACKAGE_NAME QtBasicUtils CONFIG_PATH lib/cmake/QtBasicUtils)

# Install license into share/${PORT}/
file(INSTALL "${SOURCE_PATH}/LICENSE" DESTINATION "${CURRENT_PACKAGES_DIR}/share/${PORT}")

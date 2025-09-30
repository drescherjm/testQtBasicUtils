vcpkg_from_github(
    OUT_SOURCE_PATH SOURCE_PATH
    REPO drescherjm/QtBasicUtils
    REF 31d3475c2385297c83d52d8eb96db0c1e1b2d14f
    SHA512 5bd5b1a6dcf3d0ea1cb5a9d85f32e42472c76f2b76fe8d8998a56344fdfc9aea1156d70bac4eb2eae5c192ed441a44a9754cc933f6e61b9c26822ab1e8eb0e56
)

set(CONFIGURE_OPTIONS)

if("qt5" IN_LIST FEATURES AND "qt6" IN_LIST FEATURES)
    message(FATAL_ERROR "Features 'qt5' and 'qt6' cannot be used together.")
elseif("qt5" IN_LIST FEATURES)
    list(APPEND CONFIGURE_OPTIONS -DSELECT_QT_VERSION="Qt5")
elseif("qt6" IN_LIST FEATURES)
    list(APPEND CONFIGURE_OPTIONS -DSELECT_QT_VERSION="Qt6")
else()
    message(FATAL_ERROR "Either 'qt5' or 'qt6' must be enabled.")
endif()

vcpkg_configure_cmake(
    SOURCE_PATH ${SOURCE_PATH}
    PREFER_NINJA
    OPTIONS ${CONFIGURE_OPTIONS}
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

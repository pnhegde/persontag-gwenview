project(persontag-gwenview)

find_package(KDE4 REQUIRED)
find_package(Nepomuk REQUIRED)
find_package(NepomukExtras)
include(MacroLibrary)
include(SopranoAddOntology)
include (KDE4Defaults)

include_directories(
  ${QT_INCLUDES}
  ${KDE4_INCLUDES}
  ${SOPRANO_INCLUDE_DIR}
  ${NEPOMUK_INCLUDE_DIR}
  ${CMAKE_SOURCE_DIR}
  ${NEPOMUK_INCLUDE_DIR}
  )

set( SRCS
  main.cpp
  persontagwidget.cpp
)

kde4_add_executable(persontag-gwenview ${SRCS})


target_link_libraries( persontag-gwenview
  nepomukutils
  nepomukextras
  ${KDE4_KDEUI_LIBS}
  ${KDE4_KIO_LIBS}
  ${NEPOMUK_LIBRARIES}
  ${NEPOMUK_QUERY_LIBRARIES}
  ${SOPRANO_LIBRARIES}
  ${NEPOMUKEXTRAS_INCLUDE_DIR}	
  )

install(TARGETS persontag-gwenview
        DESTINATION ${PLUGIN_INSTALL_DIR})
#install(FILES resourcebrowser.desktop DESTINATION ${SERVICES_INSTALL_DIR})

#install(PROGRAMS resourcebrowser.desktop DESTINATION ${XDG_APPS_INSTALL_DIR})

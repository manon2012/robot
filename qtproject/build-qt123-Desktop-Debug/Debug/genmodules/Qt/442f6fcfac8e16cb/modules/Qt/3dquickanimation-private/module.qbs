import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "3DQuickAnimation"
    Depends { name: "Qt"; submodules: ["core-private","qml-private","3dquick-private","3dcore-private","3drender-private","3dquickanimation"]}

    architectures: ["x86_64"]
    targetPlatform: "linux"
    hasLibrary: false
    staticLibsDebug: []
    staticLibsRelease: []
    dynamicLibsDebug: []
    dynamicLibsRelease: []
    linkerFlagsDebug: []
    linkerFlagsRelease: []
    frameworksDebug: []
    frameworksRelease: []
    frameworkPathsDebug: []
    frameworkPathsRelease: []
    libNameForLinkerDebug: undefined
    libNameForLinkerRelease: undefined
    libFilePathDebug: undefined
    libFilePathRelease: undefined
    pluginTypes: []
    moduleConfig: []
    cpp.defines: []
    cpp.includePaths: ["/opt/Qt5.12.6/5.12.6/gcc_64/include/Qt3DQuickAnimation/5.12.6","/opt/Qt5.12.6/5.12.6/gcc_64/include/Qt3DQuickAnimation/5.12.6/Qt3DQuickAnimation"]
    cpp.libraryPaths: []
    
}

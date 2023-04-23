#!/bin/bash

export QT_PLUGIN_PATH=/opt/Qt5.12.6/5.12.6/gcc_64/plugins
export LD_LIBRARY_PATH=/opt/Qt5.12.6/5.12.6/gcc_64/lib:$LD_LIBRARY_PATH
export PATH=/opt/Qt5.12.6/5.12.6/gcc_64/bin:$PATH

. /opt/Sdk/Runtime_Env/Runtime_setup.sh --setup
. /opt/Parser/Runtime_Env/Runtime_setup.sh --setup
. /home/diana/project/DianaGit/diana/Environment/Runtime_Env/Runtime_setup.sh --setup

./DianaApiDemo



#!/bin/bash
export DEST="./.exvim.example"
export TOOLS="/Users/wzcjj/.vim/tools/"
export TMP="${DEST}/_symbols"
export TARGET="${DEST}/symbols"
sh ${TOOLS}/shell/bash/update-symbols.sh

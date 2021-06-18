#! /usr/bin/env bash

#-----------------------------------------------------
# This scripts performs three tasks:                 -
#                                                    -
# (1) Sets the environmental variable                -
# MOUSEION.                                          -
#                                                    -
# (2) Modifies your PATH environmental               -
# variable to include Mouseion's software package    -
# bin directory.                                     -
#                                                    -
# (3) Modifies your PYTHONPATH environmental         -
# variable to include Mouseion's software package    -
# python_packages directory.                         -
#                                                    -
# This file is to be sourced while                   -
# the current working directory is the top level     -
# of the Mouseion software package:                  -
#                                                    -
# source ./bin/set_env_var_anansi_top_level.sh       -
#                                                    -
#-----------------------------------------------------

export MOUSEION=$(pwd)

export PATH="${MOUSEION}/bin:${PATH}"

export PYTHONPATH="${MOUSEION}/python_packages:${PYTHONPATH}"

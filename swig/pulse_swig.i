/* -*- c++ -*- */

#define PULSE_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "pulse_swig_doc.i"

%{
#include "pulse/pulse_detect.h"
%}


%include "pulse/pulse_detect.h"
GR_SWIG_BLOCK_MAGIC2(pulse, pulse_detect);

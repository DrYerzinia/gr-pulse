/* -*- c++ -*- */
/* 
 * Copyright 2018 <+YOU OR YOUR COMPANY+>.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "pulse_detect_impl.h"

#include <stdio.h>
#include <gnuradio/blocks/complex_to_mag.h>

namespace gr {
  namespace pulse {

    pulse_detect::sptr
    pulse_detect::make(int sample_average, float average_multiple)
    {
      return gnuradio::get_initial_sptr
        (new pulse_detect_impl(sample_average, average_multiple));
    }

    /*
     * The private constructor
     */
    pulse_detect_impl::pulse_detect_impl(int sample_average_i, float average_multiple_i)
      : gr::sync_block("pulse_detect",
              gr::io_signature::make(1, 1, sizeof(gr_complex)),
              gr::io_signature::make(0, 0, 0))
    {
      max = 0;
      sample_count = 0;
      average_multiple = average_multiple_i;
      sample_average = sample_average_i;
      pulse_length = 80;
      last_pulse = 0;
      previous_pulse = 0;

    }

    /*
     * Our virtual destructor.
     */
    pulse_detect_impl::~pulse_detect_impl()
    {
    }

    int
    pulse_detect_impl::work(int noutput_items,
        gr_vector_const_void_star &input_items,
        gr_vector_void_star &output_items)
    {
      const gr_complex *in = (const gr_complex *) input_items[0];

      // Do <+signal processing+>

      for(int i = 0; i < noutput_items; i++){

        // Build up average for sample_average samples
        if(sample_count <= sample_average){
          max += std::abs(in[i])*average_multiple/sample_average;
        }

        if(sample_count == sample_average){
          printf("Sample Threshold set at %.6e\n", max);
          fflush(stdout);
        }

        if(sample_count > sample_average){

          // Compare incomming samples against average*average_multiple
          float mag = std::abs(in[i]);
          if(last_pulse + pulse_length > sample_count){
            if(max_mag > mag) max_mag = mag;
          } else if(last_pulse + pulse_length == sample_count){
            printf(" with amplitude %.6e\n", max_mag);
            fflush(stdout);
            last_pulse = 0;
          } else if(mag > max){
            printf("Pulse Detected at time %lu", sample_count);
            last_pulse = sample_count;
            previous_pulse = sample_count;
            max_mag = mag;
          }

        }

        sample_count++;

      }

      // Tell runtime system how many output items we produced.
      return noutput_items;
    }

  } /* namespace pulse */
} /* namespace gr */


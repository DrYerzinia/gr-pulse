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

#ifndef INCLUDED_PULSE_PULSE_DETECT_IMPL_H
#define INCLUDED_PULSE_PULSE_DETECT_IMPL_H

#include <pulse/pulse_detect.h>

namespace gr {
  namespace pulse {

    class pulse_detect_impl : public pulse_detect
    {
     private:
      // Nothing to declare in this block.
      float max;
      uint64_t sample_count;
      uint64_t last_pulse;
      uint64_t previous_pulse;
      int sample_average;
      float average_multiple;
      float pulse_length;
      float max_mag;

     public:
      pulse_detect_impl(int sample_average, float average_multiple);
      ~pulse_detect_impl();

      // Where all the action really happens
      int work(int noutput_items,
         gr_vector_const_void_star &input_items,
         gr_vector_void_star &output_items);
    };

  } // namespace pulse
} // namespace gr

#endif /* INCLUDED_PULSE_PULSE_DETECT_IMPL_H */


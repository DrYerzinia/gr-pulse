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


#ifndef INCLUDED_PULSE_PULSE_DETECT_H
#define INCLUDED_PULSE_PULSE_DETECT_H

#include <pulse/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
  namespace pulse {

    /*!
     * \brief <+description of block+>
     * \ingroup pulse
     *
     */
    class PULSE_API pulse_detect : virtual public gr::sync_block
    {
     public:
      typedef boost::shared_ptr<pulse_detect> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of pulse::pulse_detect.
       *
       * To avoid accidental use of raw pointers, pulse::pulse_detect's
       * constructor is in a private implementation
       * class. pulse::pulse_detect::make is the public interface for
       * creating new instances.
       */
      static sptr make(int sample_average, float average_multiple);
    };

  } // namespace pulse
} // namespace gr

#endif /* INCLUDED_PULSE_PULSE_DETECT_H */


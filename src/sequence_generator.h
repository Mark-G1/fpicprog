/* Copyright (C) 2016 G.P. Halkes
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License version 3, as
   published by the Free Software Foundation.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef SEQUENCE_GENERATOR_H_
#define SEQUENCE_GENERATOR_H_

#include <string>
#include <vector>

#include "device_db.h"
#include "util.h"

struct TimedStep {
  Datastring data;
  Duration sleep;
};

typedef std::vector<TimedStep> TimedSequence;

class Pic18SequenceGenerator {
 public:
  enum TimedSequenceType {
    INIT_SEQUENCE,
    BULK_ERASE_SEQUENCE,
    WRITE_SEQUENCE,
    WRITE_CONFIG_SEQUENCE,
  };

  Datastring GetCommandSequence(Pic18Command command, uint16_t payload) const;
  virtual std::vector<TimedStep> GetTimedSequence(TimedSequenceType type,
                                                  const DeviceInfo *device_info) const;
  virtual ~Pic18SequenceGenerator() = default;

 private:
  Datastring GenerateBitSequence(uint32_t data, int bits) const;
};

#endif
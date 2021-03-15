// Copyright (c) 2021 Ichiro ITS
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#ifndef MOTION_OPENCR__MOTION_HPP_
#define MOTION_OPENCR__MOTION_HPP_

#include <motion_opencr/pose.hpp>
#include <dynamixel_sdk/dynamixel_sdk.h>

#include <memory>
#include <string>
#include <vector>

namespace motion
{

class Motion
{
public:
  explicit Motion(std::string pose_name);

  void start();
  void stop();

  void start_pose(uint8_t id);
  void insert_pose(Pose pose);
  void insert_pose(uint8_t id, Pose pose);
  void delete_pose(uint8_t id);

  void set_name(std::string pose_name);
  std::string get_name();

private:
  dynamixel::PortHandler * port_handler;
  dynamixel::PacketHandler * packet_handler;

  uint8_t id;
  std::string name;

  uint8_t next_motion_id;

  static std::vector<Pose> poses;
};

}  // namespace motion

#endif  // MOTION_OPENCR__MOTION_HPP_
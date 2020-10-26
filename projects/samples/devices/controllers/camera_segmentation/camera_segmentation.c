/*
 * Copyright 1996-2020 Cyberbotics Ltd.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * Description:  An example of use of a camera device with recognition segmentation capability.
 */

#include <webots/camera.h>
#include <webots/motor.h>
#include <webots/robot.h>

#define SPEED 1.5
#define TIME_STEP 64

int main() {
  WbDeviceTag camera, left_motor, right_motor;

  wb_robot_init();

  /* Get the camera device, enable the camera, the recognition and the segmentation functionalities */
  camera = wb_robot_get_device("camera");
  wb_camera_enable(camera, TIME_STEP);
  wb_camera_recognition_enable(camera, TIME_STEP);
  wb_camera_recognition_enable_segmentation(camera);

  /* get a handler to the motors and set target position to infinity (speed control). */
  left_motor = wb_robot_get_device("left wheel motor");
  right_motor = wb_robot_get_device("right wheel motor");
  wb_motor_set_position(left_motor, INFINITY);
  wb_motor_set_position(right_motor, INFINITY);
  wb_motor_set_velocity(left_motor, 0.0);
  wb_motor_set_velocity(right_motor, 0.0);

  /* Set the motors speed */
  wb_motor_set_velocity(left_motor, -SPEED);
  wb_motor_set_velocity(right_motor, SPEED);

  /* Main loop */
  while (wb_robot_step(TIME_STEP) != -1) {
  }

  wb_robot_cleanup();

  return 0;
}

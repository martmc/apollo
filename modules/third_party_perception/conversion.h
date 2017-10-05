/******************************************************************************
 * Copyright 2017 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

/**
 * @file
 */

#ifndef MODEULES_THIRD_PARTY_PERCEPTION_CONVERSION_H_
#define MODEULES_THIRD_PARTY_PERCEPTION_CONVERSION_H_

#include <queue>

#include "modules/drivers/proto/delphi_esr.pb.h"
#include "modules/drivers/proto/mobileye.pb.h"
#include "modules/third_party_perception/proto/radar_obstacle.pb.h"
#include "modules/localization/proto/localization.pb.h"
#include "modules/perception/proto/perception_obstacle.pb.h"

/**
 * @namespace apollo::third_party_perception::conversion
 * @brief apollo::third_party_perception
 */
namespace apollo {
namespace third_party_perception {
namespace conversion {

using ::apollo::perception::PerceptionObstacles;
using ::apollo::drivers::Mobileye;
using ::apollo::drivers::DelphiESR;
using ::apollo::localization::LocalizationEstimate;
using ::apollo::third_party_perception::RadarObstacles;

PerceptionObstacles MobileyeToPerceptionObstacles(
    const Mobileye& mobileye, const LocalizationEstimate& localization);

RadarObstacles DelphiToRadarObstacles(
    const DelphiESR& delphi_esr, const LocalizationEstimate& localization,
    const RadarObstacles& last_radar_obstacles);

PerceptionObstacles RadarObstaclesToPerceptionObstacles(
    const RadarObstacles& radar_obstacles);

}  // namespace conversion
}  // namespace third_party_perception
}  // namespace apollo

#endif  // MODULES_THIRD_PARTY_PERCEPTION_FUSION_H_

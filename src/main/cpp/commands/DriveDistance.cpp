// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/DriveDistance.h"

#include <units/math.h>


// DriveDistance::DriveDistance(double speed, units::meter_t distance, Drivetrain* drive)
//       : m_speed(speed), m_distance(distance), m_drive(drive) {
//     AddRequirements({m_drive});
//   // m_speed = speed; 
//   // m_distance = distance;
//   // m_drive = drive;
// }

void DriveDistance::Initialize() {
  m_drive->ArcadeDrive(0.5, 0);
  m_drive->ResetEncoders();
}

void DriveDistance::Execute() {
  m_drive->ArcadeDrive(m_speed, 0);
}

void DriveDistance::End(bool interrupted) {
  m_drive->ArcadeDrive(0, 0);
}

bool DriveDistance::IsFinished() {
  return units::math::abs(m_drive->GetAverageDistance()) >= m_distance;
}

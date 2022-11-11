// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/Drive.h"

#include <units/math.h>


// DriveDistance::DriveDistance(double speed, units::meter_t distance, Drivetrain* drive)
//       : m_speed(speed), m_distance(distance), m_drive(drive) {
//     AddRequirements({m_drive});
//   // m_speed = speed; 
//   // m_distance = distance;
//   // m_drive = drive;
// }

void Drive::Initialize() {
  m_drive->ArcadeDrive(0, 0);
  m_drive->ResetEncoders();
}

void Drive::Execute() {
  m_drive->ArcadeDrive(m_speed, 0);
}

void Drive::End(bool interrupted) {
  m_drive->ArcadeDrive(0, 0);
}

bool Drive::IsFinished() {
  // return units::math::abs(m_drive->GetAverageDistance()) >= m_distance;
  return false;
}

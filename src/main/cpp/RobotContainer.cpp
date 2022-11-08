// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/PrintCommand.h>
#include <frc2/command/button/Button.h>

#include "commands/DriveDistance.h"
#include "commands/TeleopArcadeDrive.h"
#include "subsystems/Drivetrain.h"

RobotContainer::RobotContainer() {
  // Configure the button bindings
  ConfigureButtonBindings();
  DriveDistance* driveDistance = new DriveDistance(0.0,(units::length::meter_t)0,&m_drive);
  
}

void RobotContainer::ConfigureButtonBindings() {
  // Also set default commands here
  m_drive.SetDefaultCommand(TeleopArcadeDrive(
      &m_drive, [this] { return -m_controller.GetRawAxis(1); },
      [this] { return m_controller.GetRawAxis(2); }));

  // Example of how to use the onboard IO
  m_onboardButtonA.WhenPressed(frc2::PrintCommand("Button A Pressed"))
      .WhenReleased(frc2::PrintCommand("Button A Released"));

  frc2::JoystickButton(&m_controller, 1).WhenPressed(frc2::PrintCommand("Button Pressed"))
      .WhenReleased(frc2::PrintCommand("Button Released"));
  
frc2::JoystickButton(&m_controller, 1).WhenPressed(driveDistance.Execute(0.2, 0.0))
                                      .WhenReleased(driveDistance.Execute(0.0, 0.0));


  // Setup SmartDashboard options.
  m_chooser.SetDefaultOption("Auto Routine Distance", &m_autoDistance);
  m_chooser.AddOption("Auto Routine Time", &m_autoTime);
  frc::SmartDashboard::PutData("Auto Selector", &m_chooser);
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  return m_chooser.GetSelected();
}

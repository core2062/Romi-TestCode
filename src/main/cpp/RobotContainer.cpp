// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/PrintCommand.h>
#include <frc2/command/button/Button.h>


RobotContainer::RobotContainer() : m_move(10,&m_drive), m_stop(0,0_m,&m_drive) {
  
  // Configure the button bindings
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
  // Also set default commands here
  m_drive.SetDefaultCommand(TeleopArcadeDrive(
      &m_drive, [this] { return -m_controller.GetRawAxis(1); },
      [this] { return m_controller.GetRawAxis(2); }));

  // Example of how to use the onboard IO
  m_onboardButtonA.WhenPressed(frc2::PrintCommand("Button A Pressed"))
                  .WhenReleased(frc2::PrintCommand("Button A Released"));

  frc2::JoystickButton(&m_controller, 1).WhenPressed(frc2::PrintCommand("Trigger Pressed")).WhenReleased(frc2::PrintCommand("Trigger Released"));
  frc2::JoystickButton(&m_controller, 1).WhenPressed(GetDrive(true)).WhenReleased(GetDrive(false));

  frc2::JoystickButton(&m_controller, 7).WhenPressed(frc2::PrintCommand("Button 7 Pressed")).WhenReleased(frc2::PrintCommand("Button 7 Released"));
  frc2::JoystickButton(&m_controller, 7).WhenPressed(new DriveDistance(2,1_m,&m_drive));


  // Setup SmartDashboard options.
  m_chooser.SetDefaultOption("Auto Routine Distance", &m_autoDistance);
  m_chooser.AddOption("Auto Routine Time", &m_autoTime);
  m_chooser.AddOption("Auto Routine Test", &m_autoTest);
  frc::SmartDashboard::PutData("Auto Selector", &m_chooser);
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  return m_chooser.GetSelected();
}
frc2::Command* RobotContainer::GetDrive(bool moving){
  if (moving)
  {
    return &m_move;
  } else {
    return &m_stop;
  }
  
}